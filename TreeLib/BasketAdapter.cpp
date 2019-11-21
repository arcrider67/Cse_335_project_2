#include "pch.h"
#include "BasketAdapter.h"
#include "Fruit.h"
#include <string>

using namespace Gdiplus;
using namespace std;

const wstring backImageName = L"../images/basket.png";
const wstring frontImageName = L"../images/basket-front.png";

CBasketAdapter::CBasketAdapter() {
	mBackImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(backImageName.c_str()));
	mFrontImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(frontImageName.c_str()));

	if (mFrontImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += frontImageName;
		AfxMessageBox(msg.c_str());
	}

}

void CBasketAdapter::DrawBasket(Gdiplus::Graphics* graphics)
{
	int x = mX;
	int y = mY;

	double scale = 1;
	
	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mBackImage.get(), -(int)mBackImage->GetWidth() / 2,
		-(int)mBackImage->GetHeight(),
		mBackImage->GetWidth(), mBackImage->GetHeight());
	graphics->Restore(state);


	for (auto fruit : mFruits) {
		fruit->DrawInBasket(graphics, x, y);
	}

	/*
	state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mFrontImage.get(), -(int)mFrontImage->GetWidth() / 2,
		-(int)mFrontImage->GetHeight(),
		mFrontImage->GetWidth(), mFrontImage->GetHeight());
	graphics->Restore(state);
	*/
}


void CBasketAdapter::SetBasketLocation(int x, int y)
{
	mX = x;
	mY = y;
}

void CBasketAdapter::AddToBasket(std::vector < std::shared_ptr<CFruit>> fruits) {
	for (auto fruit : fruits) {
		mFruits.push_back(fruit);
	}

}