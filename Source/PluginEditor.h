#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include "PluginProcessor.h"

namespace GUIConfig
{
    constexpr int windowWidth { 450 };
    constexpr int windowHeight { 600 };

    constexpr int dialWidth { 200 };
    constexpr int dialHeight { 300 };

    constexpr int textboxWidth { 100 };
    constexpr int textboxHeight { 75 };
}

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::Slider dialAttitude {};
    juce::AudioProcessorValueTreeState::SliderAttachment dialAttitudeAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment dialDriveAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment dialWidthAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
