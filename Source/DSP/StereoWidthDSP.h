//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef STEREOWIDTHDSP_H
#define STEREOWIDTHDSP_H

/*
 * - Takes L/R channels.
 * - Calculate middle signal.
 * - Calculate side signal.
 * - Amplify side by parameter coeffcient.
 */

#include <juce_audio_basics/juce_audio_basics.h>
#include "../PluginParameters.h"

class StereoWidthDSP {
public:
    StereoWidthDSP();
    void processBlock(juce::AudioBuffer<float>& buffer, int numSamples) const;
    void setWidth(float widthParam);
    float getWidth() const;
private:
    float m_width { };
    float m_minWidth { 1.0f };
    float m_maxWidth { 1.5f };
};



#endif //STEREOWIDTHDSP_H
