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
class ImageHandler : public Component
{
public:
    // Class
	ImageHandler();
	~ImageHandler();
    // GUI
    void paint(Graphics&)override;
    void resized()override;

private:

};
