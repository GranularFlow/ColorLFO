/*
  ==============================================================================

    ColorDecomposer.h
    Created: 8 Feb 2023 6:28:46pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../Constants.h"
class ColorDecomposer : public Component
{
public:
    // Class
    ColorDecomposer();
    ~ColorDecomposer();
    // GUI
    void paint(Graphics&)override;
    void resized()override;


private:

};
