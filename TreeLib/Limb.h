#pragma once
#include "Growable.h"
class CLimb : public CGrowable
{
public:

	CLimb();


	virtual void Draw(Gdiplus::Graphics* graphics);

	void CalculateEndpoint();

	virtual void Grow();

	virtual void SetLocation(int x, int y);

	virtual void GetParentInfo();

private:

	int mMaxSize = 100; 
};

