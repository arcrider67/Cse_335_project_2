#include "pch.h"
#include "FruitAdapter.h"
#include "TreeAdapter.h"
#include <string>

using namespace Gdiplus;
using namespace std;

const wstring imageName = L"images/apple.png";
const double imageScale = 0.5;

CFruitAdapter::CFruitAdapter() : CGrowableImage(imageName) {
	SetScale(imageScale);
}


void CFruitAdapter::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	mInBasket = TRUE;

	Point point;
	point.X = x;
	point.Y = y;

	SetEndpoint(point);
	SetImage(GetTree()->GetFruitImage());
	
	CGrowableImage::Draw(graphics);
}

void CFruitAdapter::Draw(Gdiplus::Graphics* graphics)
{
	if (mInBasket) {

	}
	else {
		Point point;
		point.X = GetX() + GetTree()->GetTreeX();
		point.Y = GetTree()->GetTreeY() - GetY();


		SetImage(GetTree()->GetFruitImage());
		SetEndpoint(point);
		CalcGrownFactor();

		CGrowableImage::Draw(graphics);
	}
}