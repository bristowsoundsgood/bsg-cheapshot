//
// Created by Joe Bristow on 25/01/2026.
//

#include "PluginParameters.h"

PluginParameters::PluginParameters(const juce::AudioProcessorValueTreeState& state)
{
    m_paramDrive = dynamic_cast<juce::AudioParameterFloat*>(state.getParameter(ParameterConfig::driveParamID.getParamID()));
}

float PluginParameters::getDrive() const
{
    return m_paramDrive->get();
}

juce::AudioProcessorValueTreeState::ParameterLayout PluginParameters::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout {};
    layout.add(
        std::make_unique<juce::AudioParameterFloat>(
            ParameterConfig::driveParamID, ParameterConfig::driveParamName, ParameterConfig::driveRange, ParameterConfig::driveDefault,
            juce::AudioParameterFloatAttributes().withStringFromValueFunction(stringFromDrive)
        )
    );

    return layout;
}

juce::String PluginParameters::stringFromDrive(const float value, int)
{
    // Multiplier maps the max drive to 100% and the min drive to 0%.
    constexpr float multiplier { 100 / ParameterConfig::driveMax };
    return juce::String(value * multiplier) + "%";
}
