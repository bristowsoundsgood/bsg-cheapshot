#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), dialDriveAttachment(processorRef.state, ParameterConfig::driveParamID.getParamID(), dialDrive)
{
    juce::ignoreUnused (processorRef);
    dialDrive.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dialDrive.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, GUIConfig::textboxWidth, GUIConfig::textboxHeight);
    addAndMakeVisible(dialDrive);

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
    dialDrive.setBounds(bounds.getCentreX() - GUIConfig::dialWidth / 2, bounds.getCentreY() - GUIConfig::dialHeight / 2,
        GUIConfig::dialWidth, GUIConfig::dialHeight);
}
