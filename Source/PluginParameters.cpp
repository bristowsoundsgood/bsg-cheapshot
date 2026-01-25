//
// Created by Joe Bristow on 25/01/2026.
//

#include "PluginParameters.h"

PluginParameters::PluginParameters(const juce::AudioProcessorValueTreeState& state)
{
    m_paramAttitude = dynamic_cast<juce::AudioParameterFloat*>(state.getParameter(ParameterConfig::attitudeParamID.getParamID()));
    m_paramDrive = dynamic_cast<juce::AudioParameterFloat*>(state.getParameter(ParameterConfig::driveParamID.getParamID()));
    m_paramWidth = dynamic_cast<juce::AudioParameterFloat*>(state.getParameter(ParameterConfig::widthParamID.getParamID()));
}

float PluginParameters::getAttitude() const
{
    return m_paramAttitude->get();
}

float PluginParameters::getDrive() const
{
    return m_paramDrive->get();
}

float PluginParameters::getStereoWidth() const
{
    return m_paramWidth->get();
}

juce::AudioProcessorValueTreeState::ParameterLayout PluginParameters::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout {};
    layout.add(
        std::make_unique<juce::AudioParameterFloat>(
            ParameterConfig::attitudeParamID, ParameterConfig::attitudeParamName, ParameterConfig::attitudeRange, ParameterConfig::attitudeDefault
        ),

        std::make_unique<juce::AudioParameterFloat>(
            ParameterConfig::driveParamID, ParameterConfig::driveParamName, ParameterConfig::driveRange, ParameterConfig::driveDefault
        ),

        std::make_unique<juce::AudioParameterFloat>(
            ParameterConfig::widthParamID, ParameterConfig::widthParamName, ParameterConfig::widthRange, ParameterConfig::widthDefault
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
