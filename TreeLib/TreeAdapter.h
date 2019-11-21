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

	std::shared_ptr<Gdiplus::Bitmap> GetLeafImage() { return mLeafImage; }
	std::shared_ptr<Gdiplus::Bitmap> GetFruitImage() { return mFruitImage; }

	virtual std::vector<std::shared_ptr<CFruit>> Harvest();

	virtual void SetWindSpeed(double speed) { mWindSpeed = speed; };
	virtual double GetWindSpeed() { return mWindSpeed; };


private:

	double mWindSpeed = 0;

	int mSeed;

	int mFrame = 0; ///< Current frame

	std::shared_ptr<CLimb> mTrunk;

	int mX = 500;     ///< Tree X location
	int mY = 550;     ///< Tree Y location

	std::shared_ptr<CPseudoRandom> mRandomGenerator;

	std::shared_ptr<Gdiplus::Bitmap> mLeafImage;

	std::shared_ptr<Gdiplus::Bitmap> mFruitImage;


};

