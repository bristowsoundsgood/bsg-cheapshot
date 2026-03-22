//
// Created by Joe Bristow on 11/03/2026.
//

#include "ClipDSP.h"

void ClipDSP::processBlock(float* channelData, const int blockSize) noexcept
{
    for (int i = 0; i < blockSize; ++i)
    {
        const float dry { channelData[i] };
        if (dry <= -1) channelData[i] = -2.0f / 3.0f;
        else if (dry >= 1) channelData[i] = 2.0f / 3.0f;
        else channelData[i] = dry - dry * dry * dry / 3.0f;
    }
}
