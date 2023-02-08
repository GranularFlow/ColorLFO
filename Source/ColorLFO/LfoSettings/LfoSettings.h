/*
  ==============================================================================

    LfoSettings.h
    Created: 8 Feb 2023 6:01:27pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../Constants.h"
#include "../../Utils/Utils.h"
#include "../../CustomSetting/RadioBox.h"
#include "../../CustomSetting/Knob.h"
#include "../../CustomSetting/Separator.h"

class LfoSettings : public Component
{
public:
    static enum Direction {
        RANDOM,
        X,
        REVERSED_X
    };

    static enum SelectedColor {
        RED,
        GREEN,
        BLUE
    };
    // Class
    LfoSettings();
    ~LfoSettings();
    // GUI
    void initGui();
    void paint(Graphics&)override;
    void resized()override;
    // Listeners


private:
    // Settings
    RadioBox directionRadioBox {"DIRECTION", C_BARARED, DIRECTION_MODE };
    Knob rateKnob {"RATE", C_BILLS, 1, 20, 1, 2 };
    Knob depthKnob{ "DEPTH", C_BILLS, 1, 100, 1, 50 };
    RadioBox colorSelectRadioBox{ "SELECTED COLOR", C_BARARED, SELECTED_COLOR };
    // GUI
    OwnedArray<Separator> separators;
};
