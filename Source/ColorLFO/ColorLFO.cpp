/*
  ==============================================================================

    ColorLFO.cpp
    Created: 8 Feb 2023 4:43:34pm
    Author:  honza

  ==============================================================================
*/

#include "ColorLFO.h"


ColorLFO::ColorLFO()
{
    initGui();
}

ColorLFO::~ColorLFO()
{
}

void ColorLFO::initGui()
{
    addAndMakeVisible(imageHandler);
    addAndMakeVisible(uploadButton);
    addAndMakeVisible(colorDecomposer);
    addAndMakeVisible(settings);
}

void ColorLFO::paint(Graphics& g)
{
    g.fillAll(C_DARK);
    paintLogoOnce(g);

}

void ColorLFO::resized()
{
    FlexBox fb{
           FlexBox::Direction::row,
           FlexBox::Wrap::noWrap,
           FlexBox::AlignContent::center,
           FlexBox::AlignItems::center,
           FlexBox::JustifyContent::spaceBetween
    };
    Utils::addToFb(&fb, imageHandler, 0, (getWidth() / 2) - 50, ((getHeight() - 50) / 2)-25);
    Utils::addToFb(&fb, uploadButton, 1, 60, 40);
    Utils::addToFb(&fb, colorDecomposer, 2, (getWidth() / 2) - 50, ((getHeight() - 50) / 2) - 25);

    fb.performLayout(getLocalBounds().withTrimmedTop(50).withTrimmedBottom((getHeight() - 50) * 1/5).withTrimmedLeft(5).withTrimmedRight(5));
    
    settings.setBounds(getLocalBounds().withTrimmedTop((getHeight() - 50) * 4/5).withTrimmedBottom(10).withTrimmedLeft(getWidth() * 1/4).withTrimmedRight(getWidth() * 1 / 4));
}

void ColorLFO::paintLogoOnce(Graphics& g)
{
    const Image logo = ImageFileFormat::loadFrom(BinaryData::logo250_png, BinaryData::logo250_pngSize);
    g.drawImageAt(logo, (50 - 36) / 2, 7, false);

}

void ColorLFO::addListeners()
{
}

void ColorLFO::removeListeners()
{
}

void ColorLFO::timerCallback()
{
}

