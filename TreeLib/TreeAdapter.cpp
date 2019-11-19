#include "pch.h"
#include "TreeAdapter.h"
#include "Growable.h"
#include "Limb.h"


using namespace std;
using namespace Gdiplus;

CTreeAdapter::CTreeAdapter() : CTree() {

	mTrunk = make_shared<CLimb>();
	mTrunk->SetTree(this);
	mTrunk->Grow();
	mTrunk->SetLocation(mX, mY);
}

void CTreeAdapter::DrawTree(Gdiplus::Graphics* graphics)
{
	mTrunk->Draw(graphics, mX, mY);

}
