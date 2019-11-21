#include "pch.h"
#include "Growable.h"
#include "TreeAdapter.h"
#include "Leaf.h"
#include "Limb.h"
#include "FruitAdapter.h"
#include <cmath>


using namespace Gdiplus;
using namespace std;

CGrowable::CGrowable(){
	

}

void CGrowable::Draw(Gdiplus::Graphics* graphics)
{
	CalculateWind();
	for (auto child : mChildren) {
		child->Draw(graphics);
	}
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


double CGrowable::CalcAdjacent(double hypo) {
	return (cos(mAngle * 0.0174533) * hypo);
}

double CGrowable::CalcOpposite(double hypo) {
	return (sin(mAngle * 0.0174533) * hypo);
}


void CGrowable::GenerateAngle() {
	mAngle = mParent->GetAngle() + mHostTree->Random(-60, 60);
	mBaseAngle = mAngle;
}

void CGrowable::Grow() {


	if (mDepth < 3) {
		auto limb = make_shared<CLimb>();
		limb->SetTree(mHostTree);
		AddChild(limb);
		limb->GetParentInfo();



		auto limb2 = make_shared<CLimb>();
		limb2->SetTree(mHostTree);
		AddChild(limb2);
		limb2->GetParentInfo();

		limb->Grow();
		limb2->Grow();
	}
	else if (mDepth < 8){

		if (mHostTree->Random(0.0, 1.0) > 0.7) {
			auto leaf = make_shared<CLeaf>();
			AddChild(leaf);
			leaf->GetParentInfo();


		}
		else {
			auto limb = make_shared<CLimb>();
			limb->SetTree(mHostTree);
			AddChild(limb);
			limb->GetParentInfo();
			limb->Grow();
			}
		
		if (mHostTree->Random(0.0, 1.0) > 0.5) {
			auto fruit = make_shared<CFruitAdapter>();
			AddChild(fruit);
			fruit->GetParentInfo();
			fruit->SetSelf(fruit);

		}
		else {
			auto limb = make_shared<CLimb>();
			limb->SetTree(mHostTree);
			AddChild(limb);
			limb->GetParentInfo();
			limb->Grow();
		}
	}
}



void CGrowable::GrowChildren() {
	for (auto child : mChildren) {
		child->Grow();
	}
}

void CGrowable::GetParentInfo()
{
	mHostTree = mParent->GetTree();
	mX = mParent->GetEndpoint().X;
	mY = mParent->GetEndpoint().Y;
	SetStartFrame(mParent->GetStartFrame() + mParent->GetFrameAge());
	mEndpoint = mParent->GetEndpoint();
	GenerateAngle();
	mDepth = mParent->GetDepth() + 1;

}

void CGrowable::Accept(CGrowableVisitor* visitor)
{
	for (auto child : mChildren) {
		child->Accept(visitor);
	}

}

void CGrowable::CalculateWind()
{
	mAngle = mBaseAngle + mHostTree->GetWindSpeed() * mDepth;
}
