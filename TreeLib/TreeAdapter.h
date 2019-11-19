#pragma once
#include "Tree.h"

class CGrowable;
class CLimb;

class CTreeAdapter : public CTree
{
public:
	
	CTreeAdapter();

	virtual void DrawTree(Gdiplus::Graphics* graphics);

	void SetTreeFrame(int frame) { mFrame = frame;}

	int GetTreeFrame() { return mFrame; }

private:



	int mFrame = 0; ///< Current frame

	std::shared_ptr<CLimb> mTrunk;

	int mX = 500;     ///< Tree X location
	int mY = 550;     ///< Tree Y location

};

