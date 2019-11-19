#pragma once
#include "Growable.h"
class CLimb : public CGrowable
{
public:
	virtual void Draw(Gdiplus::Graphics* graphics, double treeX, double treeY);

	virtual void Grow();

private:

	double mAngle;

};

