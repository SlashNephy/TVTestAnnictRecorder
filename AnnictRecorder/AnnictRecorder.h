#pragma once

#include "pch.h"

#include "AnnictApi.h"

namespace AnnictRecorder
{
    struct CreateRecordResult
    {
        bool success = false;
        std::wstring message{L"AnnictRecorder �ҋ@��..."};
        std::optional<std::wstring> workName{};
        std::optional<std::wstring> episodeName{};
        std::optional<uint16_t> episodeNumber{};
        std::optional<std::wstring> episodeNumberText{};
    };

    static std::optional<std::wstring> GetWStringOrNull(const nlohmann::json& json, const std::string& key)
    {
        if (!json.is_object() || json[key].is_null())
        {
            return std::nullopt;
        }

        // ���P�[���̐ݒ�
        setlocale(LC_ALL, ".utf8");

        wchar_t buf[256];
        const auto value = json[key].get<std::string>();
        mbstowcs_s(nullptr, buf, value.c_str(), 255);

        return std::optional(buf);
    }

    static CreateRecordResult CreateEpisodeRecord(
        const uint32_t annictWorkId,
        const SyoboCal::LookupProgramResult& syobocalProgram,
        const std::string& annictToken,
        const bool dryRun
    )
    {
        // Annict ����G�s�\�[�h�ꗗ���擾����, �Y���̃G�s�\�[�h��������
        const auto episodes = Annict::GetEpisodes(annictWorkId, annictToken);
        const auto episodeIterator = std::ranges::find_if(episodes, [syobocalProgram](const nlohmann::json& episode)
        {
            return syobocalProgram.count == episode["number"].get<float_t>();  // NOLINT(clang-diagnostic-float-equal)
        });

        if (episodeIterator == episodes.end())
        {
            PrintDebug(L"Annict �ł̃G�s�\�[�h�f�[�^��������܂���ł����B�X�L�b�v���܂��B(TID={}, WorkID={})", syobocalProgram.titleId, annictWorkId);
            return CreateRecordResult{};
        }

        const auto& targetEpisode = *episodeIterator;
        if (!dryRun)
        {
            const auto annictEpisodeId = targetEpisode["id"].get<uint32_t>();
            Annict::PostRecord(annictEpisodeId, annictToken);
        }

        const auto workName = GetWStringOrNull(targetEpisode["work"], "title");
        const auto episodeName = GetWStringOrNull(targetEpisode, "title");
        const auto episodeNumber = !targetEpisode["number"].is_null() ? std::optional(targetEpisode["number"].get<uint16_t>()) : std::nullopt;
        const auto episodeNumberText = GetWStringOrNull(targetEpisode, "number_text");

        return CreateRecordResult{
            true,
            std::format(
                L"#{:2d}�u{}�v���L�^���܂����B",
                episodeNumber.value_or(0),
                episodeName.value_or(L"�T�u�^�C�g���s��")
            ),
            workName, episodeName, episodeNumber, episodeNumberText
        };
    }

    static CreateRecordResult CreateWorkRecord(
        const uint32_t annictWorkId,
        const nlohmann::json& annictWork,
        const std::string& annictToken,
        const bool dryRun
    )
    {
        if (!dryRun) {
            Annict::PostMyStatus(annictWorkId, annictToken);
        }

        const auto workName = GetWStringOrNull(annictWork, "title");

        return CreateRecordResult{
            true,
            std::format(L"�u{}�v���L�^���܂����B", workName.value_or(L"�^�C�g���s��")),
            workName, std::nullopt, std::nullopt, std::nullopt
        };
    }

    static CreateRecordResult CreateRecord(
        const std::string& annictToken,
        const TVTest::ProgramInfo& Program,
        const YAML::Node& ChannelDefinition,
        std::map<uint32_t, uint32_t>& AnnictIds,
        const bool DryRun
    )
    {
        // ����ڂ��J�����_�[�ɓo�^����Ă��Ȃ��`�����l���͖���
        const auto rawSyoboCalId = ChannelDefinition["syobocalId"];
        if (!rawSyoboCalId.IsDefined())
        {
            PrintDebug(L"����ڂ��J�����_�[�ɓo�^����Ă��Ȃ��`�����l���ł��B�X�L�b�v���܂��B");
            return CreateRecordResult{
                false, L"����ڂ��J�����_�[�ɓo�^����Ă��Ȃ��`�����l���ł��B"
            };
        }

        // ����ڂ��J�����_�[�ɕ��������Ŗ₢���킹��
        const auto syoboCalChId = rawSyoboCalId.as<int>();
        const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
        if (!syoboCalProgram.has_value())
        {
            PrintDebug(L"����ڂ��J�����_�[�ɕ����������o�^����Ă��܂���B�X�L�b�v���܂��B(ChID={})", syoboCalChId);
            return CreateRecordResult{
                false, L"����ڂ��J�����_�[�ɕ��������f�[�^������܂���B"
            };
        }

        // kawaiioverflow/arm ���� ����ڂ��J�����_�[ TID �� Annict Work ID ��������
        const auto syoboCalTID = syoboCalProgram.value().titleId;
        if (!AnnictIds.contains(syoboCalTID))
        {
            PrintDebug(L"Annict �ł̍�i�f�[�^��������܂���ł����B�X�L�b�v���܂��B(TID={})", syoboCalTID);
            return CreateRecordResult{
                false, L"Annict�ɍ�i�f�[�^��������܂���B"
            };
        }

        const auto annictWorkId = AnnictIds[syoboCalTID];
        const auto annictWork = Annict::GetWorkOrNull(annictWorkId, annictToken);
        if (!annictWork.has_value())
        {
            PrintDebug(L"Annict �ł̍�i�f�[�^��������܂���ł����B�X�L�b�v���܂��B(TID={}, WorkID={})", syoboCalTID, annictWorkId);
            return CreateRecordResult{
                false, L"Annict�ɍ�i�f�[�^��������܂���B"
            };
        }

        // �G�s�\�[�h�ŕʂ�Ă���ꍇ, �Y���̃G�s�\�[�h���L�^
        if (!annictWork.value()["no_episodes"].get<bool>())
        {
            return CreateEpisodeRecord(annictWorkId, syoboCalProgram.value(), annictToken, DryRun);
        }

        // �G�s�\�[�h�ŕʂ�Ă��Ȃ��ꍇ (�f��Ȃ�), ��i���̂��u�����v�ɐݒ�
        return CreateWorkRecord(annictWorkId, annictWork.value(), annictToken, DryRun);

    }
}