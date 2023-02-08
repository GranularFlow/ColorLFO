/*
  ==============================================================================

    ColorLFO.h
    Created: 8 Feb 2023 4:43:34pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../Utils/Utils.h"
#include "../Constants.h"
#include "LfoSettings/LfoSettings.h"
#include "ImageHandler/ImageHandler.h"
#include "ColorDecomposer/ColorDecomposer.h"

class ColorLFO : public Component, public Timer
{
public:
    // Class
	ColorLFO();
	~ColorLFO();
    // GUI
    void initGui();
    void paint(Graphics&)override;
    void resized()override;
    void paintLogoOnce(Graphics&);
    // Listener
    void addListeners();
    void removeListeners();
    void timerCallback();

private:

    //  -- Button
    TextButton uploadButton{ "LOAD" };
    //  -- Left picture
    ImageHandler imageHandler;
    //  -- Right Color
    ColorDecomposer colorDecomposer;
    //  -- Settings
    LfoSettings settings;
};