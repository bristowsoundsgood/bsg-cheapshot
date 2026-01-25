//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef PLUGINPARAMETERS_H
#define PLUGINPARAMETERS_H

#include <juce_audio_processors/juce_audio_processors.h>

// TODO: Address redundancy in variable values (min, max, step, width)
namespace ParameterConfig
{
    constexpr float attitudeMin { 0.0f };
    constexpr float attitudeMax { 100.0f };
    constexpr float attitudeStep { 0.01f };
    constexpr float attitudeDefault { 0.0f };
    const juce::NormalisableRange attitudeRange { attitudeMin, attitudeMax, attitudeStep };
    const juce::ParameterID attitudeParamID { "attitude", 1 };
    const juce::String attitudeParamName { "attitude" };

    constexpr float driveMin {attitudeMin };
    constexpr float driveMax { attitudeMax };
    constexpr float driveStep { attitudeStep };
    constexpr float driveDefault { attitudeDefault };
    const juce::NormalisableRange driveRange { driveMin, driveMax, driveStep };
    const juce::ParameterID driveParamID { "drive", 1 };
    const juce::String driveParamName { "drive"  };

    constexpr float widthMin { attitudeMin };
    constexpr float widthMax { attitudeMax };
    constexpr float widthStep { attitudeStep };
    constexpr float widthDefault { attitudeDefault };
    const juce::NormalisableRange widthRange { widthMin, widthMax, widthStep };
    const juce::ParameterID widthParamID { "width", 1 };
    const juce::String widthParamName { "width" };
}

class PluginParameters {
public:
    explicit PluginParameters(const juce::AudioProcessorValueTreeState& state);

    [[nodiscard]] float getAttitude() const;
    [[nodiscard]] float getDrive() const;
    [[nodiscard]] float getStereoWidth() const;
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    static juce::String stringFromDrive(float value, int);
private:
    juce::AudioParameterFloat* m_paramAttitude;
    juce::AudioParameterFloat* m_paramDrive;
    juce::AudioParameterFloat* m_paramWidth;
};

#endif //PLUGINPARAMETERS_H
