#include "pch.h"
#include "Leaf.h"
#include "TreeAdapter.h"

using namespace Gdiplus;

const std::wstring image = L"images/leaf.png";

const double imageScale = 0.333;

CLeaf::CLeaf() : CGrowableImage(image){
	SetScale(imageScale);
}

void CLeaf::Draw(Gdiplus::Graphics* graphics)
{
	Point point;
	point.X = GetX() + GetTree()->GetTreeX();
	point.Y = GetTree()->GetTreeY()- GetY();

	SetEndpoint(point);

	SetImage(GetTree()->GetLeafImage());
	CalcGrownFactor();

	CGrowableImage::Draw(graphics);
}





