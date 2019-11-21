#pragma once
#include "GrowableImage.h"
class CLeaf : public CGrowableImage
{
public:
	CLeaf();

	virtual void Draw(Gdiplus::Graphics* graphics);	

};

