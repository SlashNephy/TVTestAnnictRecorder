#pragma once

#include "Common.h"

namespace AnnictRecorder
{
    struct Config
    {
        char annictToken[MaxAnnictTokenLength]{};
        int recordThresholdPercent = 20;
        bool shareOnTwitter = false;
        bool shareOnFacebook = false;
        bool dryRun = false;
    };
}
