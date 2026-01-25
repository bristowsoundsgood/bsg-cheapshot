#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), dialAttitudeAttachment(processorRef.state, ParameterConfig::attitudeParamID.getParamID(), dialAttitude),
                                 dialDriveAttachment(processorRef.state, ParameterConfig::driveParamID.getParamID(), dialAttitude),
                                 dialWidthAttachment(processorRef.state, ParameterConfig::widthParamID.getParamID(), dialAttitude)
{
    juce::ignoreUnused (processorRef);
    dialAttitude.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dialAttitude.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, GUIConfig::textboxWidth, GUIConfig::textboxHeight);
    addAndMakeVisible(dialAttitude);

    setSize (GUIConfig::windowWidth, GUIConfig::windowHeight);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    const juce::Rectangle<int> bounds = getLocalBounds();
    dialAttitude.setBounds(bounds.getCentreX() - GUIConfig::dialWidth / 2, bounds.getCentreY() - GUIConfig::dialHeight / 2,
        GUIConfig::dialWidth, GUIConfig::dialHeight);
}
