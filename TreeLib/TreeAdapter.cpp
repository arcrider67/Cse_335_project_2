#include "pch.h"
#include "TreeAdapter.h"
#include "Growable.h"
#include "Limb.h"
#include "GrowableVisitor.h"
#include <string>

using namespace std;
using namespace Gdiplus;


const wstring leafFilename = L"../images/leaf.png";
const wstring fruitFilename = L"../images/apple.png";

CTreeAdapter::CTreeAdapter() : CTree() {
	mRandomGenerator = make_shared<CPseudoRandom>();

	mLeafImage = unique_ptr<Bitmap>(Bitmap::FromFile(leafFilename.c_str()));
	mFruitImage = unique_ptr<Bitmap>(Bitmap::FromFile(fruitFilename.c_str()));

	mTrunk = make_shared<CLimb>();
	mTrunk->SetTree(this);
	mTrunk->Grow();
}

void CTreeAdapter::DrawTree(Gdiplus::Graphics* graphics)
{
	mTrunk->Draw(graphics);

}

std::vector<std::shared_ptr<CFruit>> CTreeAdapter::Harvest() {
	CGrowableVisitor harvester;

	mTrunk->Accept(&harvester);
	auto fruits  = harvester.getFruits();
	return fruits;
}