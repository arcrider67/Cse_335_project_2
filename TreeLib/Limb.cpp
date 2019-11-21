#include "pch.h"
#include "Limb.h"
#include "TreeAdapter.h"
#include "Leaf.h"
#include <memory>
#include <cmath>

using namespace Gdiplus;
using namespace std;



CLimb::CLimb() {

}

void CLimb::Draw(Gdiplus::Graphics* graphics) {

	int treeX = mHostTree->GetTreeX();
	int treeY = mHostTree->GetTreeY();


	CalcGrownFactor();
	CalculateEndpoint();
	Pen pen(Color(139, 69, 19), ((REAL)10 * mGrownFactor) / (REAL)(1+GetDepth()));
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)(mX + treeX), (REAL)(treeY - mY) , (REAL)(treeX + GetEndpoint().X ), (REAL)(treeY - GetEndpoint().Y));
	
	CGrowable::Draw(graphics);
}

void CLimb::Grow()
{
	CalculateEndpoint();
	CGrowable::Grow();
}


void CLimb::CalculateEndpoint() {
	Gdiplus::Point point;
	point.Y = mY + CalcAdjacent(double(mMaxSize) * mGrownFactor);
	point.X = mX + CalcOpposite(double(mMaxSize) * mGrownFactor);

	SetEndpoint(point);
}

void CLimb::SetLocation(int x, int y){
	
	 CGrowable::SetLocation(x, y);
	 CalculateEndpoint(); 
}

void CLimb::GetParentInfo()
{
	auto parent = GetParent();
	SetDepth(parent->GetDepth() + 1);
	CLimb::SetLocation(parent->GetEndpoint().X, parent->GetEndpoint().Y);
	SetStartFrame(parent->GetStartFrame() + parent->GetFrameAge());
	GenerateAngle();
	
	mMaxSize = mMaxSize / GetDepth();

}

void CLimb::CalculateWind()
{
	CGrowable::CalculateWind();
	CalculateEndpoint();

	for (auto child : mChildren)
	{
		child->SetLocation(GetEndpoint().X, GetEndpoint().Y);
	}
}



