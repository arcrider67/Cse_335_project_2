#include "pch.h"
#include "TreeAdapter.h"
#include "Growable.h"
#include "Limb.h"


using namespace std;
using namespace Gdiplus;


CTreeAdapter::CTreeAdapter() : CTree() {
	mRandomGenerator = make_shared<CPseudoRandom>();

	mTrunk = make_shared<CLimb>();
	mTrunk->SetTree(this);
	mTrunk->Grow();
}

void CTreeAdapter::DrawTree(Gdiplus::Graphics* graphics)
{
	mTrunk->Draw(graphics);

}
