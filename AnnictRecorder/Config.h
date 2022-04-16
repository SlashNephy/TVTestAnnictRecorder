#pragma once

namespace AnnictRecorder
{
    constexpr auto MaxAnnictTokenLength = 64;

    struct Config
    {
        char AnnictToken[MaxAnnictTokenLength]{};
        int RecordThresholdPercent = 20;
        bool ShareOnTwitter = false;
        bool ShareOnFacebook = false;
        bool SetWatchingStatusInFirstEpisode = false;
        bool SetWatchingStatusInAnyEpisodes = false;
        bool SetWatchedInLastEpisode = false;
        bool SkipUpdateStatusIfAlreadyWatched = false;
        bool SkipUpdateStatusIfAlreadyStopWatching = false;
        bool SetWatchingStatusOnFirstEpisodeEvenIfWatched = false;
        bool DryRun = false;
    };
}
