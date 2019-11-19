#include "pch.h"
#include "Growable.h"
#include "TreeAdapter.h"
using namespace Gdiplus;


CGrowable::CGrowable(){
	

}

void CGrowable::Draw(Gdiplus::Graphics* graphics, double treeX, double treeY)
{

}


void CGrowable::CalcGrownFactor() {
	mGrownFactor = (float(mHostTree->GetTreeFrame()) - float(mStartFrame)) / float(mMatureFrameAge);

	if (mGrownFactor > 1) {
		mGrownFactor = 1;
	}
	else if (mGrownFactor < 0) {
		mGrownFactor = 0;
	}

}
