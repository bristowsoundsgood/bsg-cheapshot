//
// Created by Joe Bristow on 25/01/2026.
//

#include <cmath>
#include <juce_audio_basics/juce_audio_basics.h>
#include "DistortionDSP.h"

void DistortionDSP::processBlock(float* channelData, const int numSamples) const
{
    for (size_t i = 0; i < numSamples; ++i)
    {
        const float xn { channelData[i] };

        // distortion equation (circle map)
        const float yn { xn + (m_drive / 2 * juce::MathConstants<float>::twoPi) * std::sin(juce::MathConstants<float>::twoPi * xn) };
        channelData[i] = yn;
    }
}
