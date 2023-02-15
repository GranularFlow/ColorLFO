/*
  ==============================================================================

    ImageHandler.h
    Created: 8 Feb 2023 6:28:33pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../Constants.h"
#include "ColorDecomposer/ColorDecomposer.h"

class ImageHandler : public Component
{
public:
    // Class
	ImageHandler();
	~ImageHandler();

    // GUI
    void paint(Graphics&)override;
    void resized()override;
    void setImage(File);
    void loadImage();
    bool isImageSet();
    void setColors(int, int);

    // Getters
    int getRed(int, int);
    int getGreen(int, int);
    int getBlue(int, int);
    // image
    int getImageHeight();
    int getImageWidth();

private:
    bool wasPainted = false;
    ColorDecomposer decomposer;
    Image image;
    std::unique_ptr<juce::FileChooser> fileChooser;
};
