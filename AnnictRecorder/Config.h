#pragma once

namespace AnnictRecorder
{
  constexpr auto MaxAnnictTokenLength = 64;
  constexpr auto MaxDiscordTokenLength = 256;
  constexpr auto MaxDiscordChannelIdLength = 32;

  struct Config
  {
    // Annict
    char AnnictToken[MaxAnnictTokenLength]{};

    // Record
    bool Enabled = true;
    int RecordThresholdPercent = 20;
    bool ShareOnTwitter = false;
    bool ShareOnFacebook = false;
    bool SetWatchingStatusInFirstEpisode = false;
    bool SetWatchingStatusInAnyEpisodes = false;
    bool SetWatchedInLastEpisode = false;
    bool SkipUpdateStatusIfAlreadyWatched = false;
    bool SetWatchingStatusOnFirstEpisodeEvenIfWatched = false;
    bool RecordDryRun = false;

    // Discord
    char DiscordToken[MaxDiscordTokenLength]{};
    char DiscordChannelId[MaxDiscordChannelIdLength]{};
    bool DiscordDryRun = false;
  };
}
