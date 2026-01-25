//
// Created by Joe Bristow on 25/01/2026.
//

#include "DistortionDSP.h"

#include "../PluginParameters.h"

// Convert parameter value (range 0-100) into k (0 - 0.04).
// This value sets the constant, k, in the distortion equation.
void DistortionDSP::setDrive(const float driveParam)
{
    // maxAttitude * x = maxDrive, therefore x = maxDrive / maxAttitude. x is used to convert attitude -> drive.
    const float x { m_maxDrive / ParameterConfig::attitudeMax };
    m_drive = driveParam * x;
}

float DistortionDSP::getDrive() const
{
    return m_drive;
}

void DistortionDSP::processBlock(float* channelData, const int numSamples) const
{
    for (size_t i = 0; i < numSamples; ++i)
    {
        const float xn { channelData[i] };

        // distortion equation
        const float yn = standardCircleMap(xn);
        channelData[i] = yn;
    }
}

float DistortionDSP::standardCircleMap(const float x) const
{
    const float y { x + m_drive / 2 * juce::MathConstants<float>::twoPi * std::sin(juce::MathConstants<float>::twoPi * x) };
    return y;
}

