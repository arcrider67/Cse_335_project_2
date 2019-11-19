#pragma once

#include "pch.h"
#include <vector>

class CTreeAdapter;

class CGrowable
{
public:

	CGrowable();

	/** Copy constructor disabled */
	CGrowable(const CGrowable&) = delete;
	/** Assignment operator disabled */
	void operator=(const CGrowable&) = delete;

	virtual void Grow() {};

	void SetLocation(double x, double y) { mX = x; mY = y;}

	void SetTree(CTreeAdapter* tree) { mHostTree = tree; }

	virtual void Draw(Gdiplus::Graphics* graphics, double treeX, double treeY);

	void CalcGrownFactor();

private:
	double mWidth = 10;
	double mHeight = 50;
	double mAngle;


	///in use so far

	///remove protected switch to private with getters and setters
protected:
	int mStartFrame = 0;
	int mMatureFrameAge = 50;

	///decimal from 0 to 1 how close the object is to fully grown
	float mGrownFactor = 1;

	/// X position relative to the tree root
	double mX = 0;
	/// Y position relative to the tree root
	double mY = 0;

	std::vector<CGrowable*> mChildren;
	

	CTreeAdapter* mHostTree;
};

