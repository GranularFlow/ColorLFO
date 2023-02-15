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
    startTimerHz(20);
    initGui();
    addListeners();
}

ColorLFO::~ColorLFO()
{
    stopTimer();
    removeListeners();
}

void ColorLFO::initGui()
{
    addAndMakeVisible(imageHandler);
    addAndMakeVisible(settings);
}

void ColorLFO::paint(Graphics& g)
{
    g.fillAll(C_DARK);
    paintLogoOnce(g);

}

void ColorLFO::resized()
{
    Rectangle<int> settingsBounds = getLocalBounds().withTrimmedTop((getHeight() - 50) * 4 / 5).withTrimmedBottom(10).withTrimmedLeft(getWidth() * 1 / 4).withTrimmedRight(getWidth() * 1 / 4);
    settings.setBounds(settingsBounds);
    imageHandler.setBounds(getLocalBounds().withTrimmedTop(60).withTrimmedBottom(settingsBounds.getHeight() + 20).withTrimmedLeft(20).withTrimmedRight(20));
}

void ColorLFO::paintLogoOnce(Graphics& g)
{
    const Image logo = ImageFileFormat::loadFrom(BinaryData::logo250_png, BinaryData::logo250_pngSize);
    g.drawImageAt(logo, (50 - 36) / 2, 7, false);

}

void ColorLFO::addListeners()
{
    settings.uploadButton.addListener(this);
    settings.depthKnob.slider.addListener(this);
    settings.rateKnob.slider.addListener(this);
}

void ColorLFO::removeListeners()
{
    settings.uploadButton.removeListener(this);
    settings.depthKnob.slider.removeListener(this);
    settings.rateKnob.slider.removeListener(this);
}

void ColorLFO::timerCallback()
{
    checkNextColor();
}

void ColorLFO::buttonClicked(Button* button)
{
    if (button == &settings.uploadButton)
    {
        imageHandler.loadImage();
    }
}

void ColorLFO::sliderValueChanged(Slider* slider)
{
    if (slider == &settings.rateKnob.slider)
    {
        stopTimer();
        startTimerHz(slider->getValue());
    }
}

void ColorLFO::checkNextColor()
{
    if (!imageHandler.isImageSet()) {
        return;
    }

    imageHandler.setColors(currentX, currentY);

    if (settings.isCurrentDirection(LfoSettings::RANDOM))
    {
        Random random;
        currentX = random.nextInt(imageHandler.getImageWidth());
        currentY = random.nextInt(imageHandler.getImageHeight());
    }
    else if (settings.isCurrentDirection(LfoSettings::FORWARD)) {
        currentX = (currentX + 1) % imageHandler.getImageWidth();
        if (currentX == imageHandler.getImageWidth() - 2)
        {
            currentX = 0;
            currentY = (currentY + 1) % imageHandler.getImageHeight();
        }
    }
    else if (settings.isCurrentDirection(LfoSettings::REVERSED)) {

        currentX = (currentX - 1) % imageHandler.getImageWidth();
        if (currentX == 0)
        {
            currentX = 0;
            currentY = (currentY - 1) % imageHandler.getImageHeight();
        }

    }

    if (settings.isCurrentSelectedColor(LfoSettings::RED))
    {
        outputValue = imageHandler.getRed(currentX, currentY);
    }
    else if (settings.isCurrentSelectedColor(LfoSettings::GREEN)) {
        outputValue = imageHandler.getGreen(currentX, currentY);

    }
    else if (settings.isCurrentSelectedColor(LfoSettings::BLUE)) {
        outputValue = imageHandler.getBlue(currentX, currentY);
    }
}

float ColorLFO::getOutputValue()
{
    return outputValue * (settings.getDepth() /(float) 100);
}
