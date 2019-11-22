#pragma once
#include "Drawable.h"
#include"Tree.h"

class CBasketDrawable;

class CTreeDrawable : public CDrawable, public CTree
{
public:


	CTreeDrawable() = delete;

	CTreeDrawable(std::wstring name);

	virtual bool HitTest(Gdiplus::Point pos) { return false; };

	virtual void Draw(Gdiplus::Graphics* graphics);

	void SetBasket(std::shared_ptr<CBasketDrawable> basket) { mBasket = basket; }


private:
	std::shared_ptr<CTree> mTree;
	std::shared_ptr<CBasketDrawable> mBasket;

	int mStartFrame = 0;

	int mHarvestFrame = 200;

	bool mHarvested = false;

};

