//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef PLUGINPARAMETERS_H
#define PLUGINPARAMETERS_H

#include <juce_audio_processors/juce_audio_processors.h>

namespace ParameterConfig
{
    const juce::ParameterID driveParamID { "drive", 1 };
    const juce::String driveParamName { "drive"  };

    constexpr float driveMin { 0.0f };
    constexpr float driveMax { 0.04f };
    constexpr float driveStep { 0.0001f };
    constexpr float driveDefault { 0.0f };
    const juce::NormalisableRange driveRange { driveMin, driveMax, driveStep };
}

class PluginParameters {
public:
    PluginParameters(const juce::AudioProcessorValueTreeState& state);

    float getDrive() const;
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    static juce::String stringFromDrive(const float value, int);
private:
    juce::AudioParameterFloat* m_paramDrive;
};

#endif //PLUGINPARAMETERS_H
