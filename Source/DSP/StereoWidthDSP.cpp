//
// Created by Joe Bristow on 25/01/2026.
//

#include "StereoWidthDSP.h"
StereoWidthDSP::StereoWidthDSP()
{
}

void StereoWidthDSP::processBlock(juce::AudioBuffer<float>& buffer, const int numSamples) const
{
    const float widthCoefficient { m_width * 0.5f };

    // The DSP requires both the L and R channels within the same scope. Therefore the buffer is passed, not the individual channel data.
    for (int i = 0; i < numSamples; ++i)
    {
        const float inLeft { buffer.getSample(0, i) };
        const float inRight { buffer.getSample(1, i) };

        // Mid-side processing (width is added by multiplying the side by the coefficient)
        const float mid { (inLeft + inRight) * 0.5f };
        const float side { (inRight - inLeft) * widthCoefficient };

        const float outLeft { mid - side };
        const float outRight { mid + side };

        buffer.setSample(0, i, outLeft);
        buffer.setSample(0, i, outRight);
    }
}

void StereoWidthDSP::setWidth(const float widthParam)
{
    // maxAttitude * x = maxWidth, therefore x = maxWidth / maxAttitude. x is used to convert width -> drive.
    const float x { m_maxWidth / ParameterConfig::attitudeMax };
    const float normalisedWidth = widthParam * x;
    m_width = normalisedWidth;

    // min width value is 1.0f
    if (m_width < 1.0f)
    {
        m_width += m_minWidth;
    }
}


float StereoWidthDSP::getWidth() const
{
    return m_width;
}





