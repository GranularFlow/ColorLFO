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
class ColorLFO : public Component, public Timer, public Button::Listener, public Slider::Listener
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
    void buttonClicked(Button*);
    void sliderValueChanged(Slider*);

    // Tools
    void checkNextColor();
    float getOutputValue();


private:
    int outputValue = 0;
    int currentX = 1;
    int currentY = 1;
    //  -- handler
    ImageHandler imageHandler;
    //  -- Settings
    LfoSettings settings;
    
};