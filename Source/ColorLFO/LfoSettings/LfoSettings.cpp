/*
  ==============================================================================

    LfoSettings.cpp
    Created: 8 Feb 2023 6:01:27pm
    Author:  honza

  ==============================================================================
*/

#include "LfoSettings.h"

LfoSettings::LfoSettings()
{
    initGui();
}

LfoSettings::~LfoSettings()
{
}

void LfoSettings::initGui()
{
    // GUI
    for (int8 i = 0; i < 3; i++)
    {
        separators.add(new Separator());
        addAndMakeVisible(separators.getLast());
    }


    addAndMakeVisible(colorSelectRadioBox);
    addAndMakeVisible(directionRadioBox);
    addAndMakeVisible(depthKnob);
    addAndMakeVisible(rateKnob);
}

void LfoSettings::paint(Graphics& g)
{
    g.setColour(L_GRAY);
    g.fillRoundedRectangle(getLocalBounds().toFloat(), 30);
}

void LfoSettings::resized()
{
    FlexBox fb{
            FlexBox::Direction::row,
            FlexBox::Wrap::noWrap,
            FlexBox::AlignContent::center,
            FlexBox::AlignItems::center,
            FlexBox::JustifyContent::spaceBetween
    };
    
    int tmpWidth = getWidth() * 1/4 * 0.85;
    int tmpHeight = getHeight() * 0.85;

    Utils::addToFb(&fb, directionRadioBox, 1, tmpWidth, tmpHeight);
    Utils::addToFb(&fb, rateKnob, 3, tmpWidth, tmpHeight);
    Utils::addToFb(&fb, depthKnob, 5, tmpWidth, tmpHeight );
    Utils::addToFb(&fb, colorSelectRadioBox, 7, tmpWidth, tmpHeight);

    // White lines
    for (int8 i = 0; i < 4; i++)
    {
        fb.items.add(FlexItem(*separators[i]).withMinWidth(1).withHeight(tmpHeight).withOrder((i + 1) * 2));
    }

    fb.performLayout(getLocalBounds());

}
