/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ColorLFOAudioProcessorEditor::ColorLFOAudioProcessorEditor (ColorLFOAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(audioProcessor.colorLfo);
    setSize (1200, 700);

}

ColorLFOAudioProcessorEditor::~ColorLFOAudioProcessorEditor()
{
}

//==============================================================================
void ColorLFOAudioProcessorEditor::paint (juce::Graphics& g)
{
   
}

void ColorLFOAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    audioProcessor.colorLfo.setBounds(getLocalBounds());
}
