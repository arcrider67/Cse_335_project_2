#pragma once
#include "Tree.h"
#include "PseudoRandom.h"

class CGrowable;
class CLimb;
class CPseudoRandom;

class CTreeAdapter : public CTree
{
public:
	
	CTreeAdapter();

	virtual void DrawTree(Gdiplus::Graphics* graphics);

	void SetTreeFrame(int frame) { mFrame = frame;}

	int GetTreeFrame() { return mFrame; }

	int GetTreeX() { return mX; }
	int GetTreeY() { return mY; }

	double Random(double fm, double to) { return mRandomGenerator->Random(fm, to);  }

	double Random(int fm, int to) { return mRandomGenerator->Random(fm, to); }


private:

	int mSeed;

	int mFrame = 0; ///< Current frame

	std::shared_ptr<CLimb> mTrunk;

	int mX = 500;     ///< Tree X location
	int mY = 550;     ///< Tree Y location

	std::shared_ptr<CPseudoRandom> mRandomGenerator;
};

