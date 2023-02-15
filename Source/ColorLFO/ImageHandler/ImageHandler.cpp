/*
  ==============================================================================

    ImageHandler.cpp
    Created: 8 Feb 2023 6:28:33pm
    Author:  honza

  ==============================================================================
*/

#include "ImageHandler.h"

ImageHandler::ImageHandler()
{
    addAndMakeVisible(decomposer);

}

ImageHandler::~ImageHandler()
{
}

void ImageHandler::paint(Graphics& g)
{
    
    if (!wasPainted && isImageSet())
    {
        g.drawImageWithin(image, 0, 10, (getWidth()/2) - 20, getHeight() - 20, juce::RectanglePlacement::centred);
        wasPainted = true;
    }
    
}

void ImageHandler::resized()
{
    decomposer.setBounds(getLocalBounds().withTrimmedRight(20).withTrimmedLeft(20 + getWidth()/2));    
}

void ImageHandler::setImage(File file)
{
    wasPainted = false;
    image = juce::ImageCache::getFromFile(juce::File(file.getFullPathName()));
    repaint();
}

void ImageHandler::loadImage()
{

    fileChooser = std::make_unique<juce::FileChooser>("Select a png file...", juce::File{}, "*.png");

    fileChooser->launchAsync({}, [this](const FileChooser& fc) {
        setImage(fc.getResult());
    });
}

bool ImageHandler::isImageSet()
{
    return !image.isNull();
}

void ImageHandler::setColors(int currentX, int currentY)
{
    decomposer.setRGB(getRed(currentX, currentY), getGreen(currentX, currentY), getBlue(currentX, currentY));
}

int ImageHandler::getRed(int x, int y)
{
    return image.getPixelAt(x, y).getRed();
}

int ImageHandler::getGreen(int x, int y)
{
    return image.getPixelAt(x, y).getGreen();
}

int ImageHandler::getBlue(int x, int y)
{
    return image.getPixelAt(x, y).getBlue();
}

int ImageHandler::getImageHeight()
{
    return image.getHeight();
}

int ImageHandler::getImageWidth()
{
    return image.getWidth();
}
