#pragma once
#include "Basket.h"


class CFruit;


class CBasketAdapter : public CBasket
{
	///virtual void DrawBasket(Gdiplus::Graphics* graphics);


	virtual void SetBasketLocation(int x, int y);

	/**
	 * Empty all fruit from the basket
	*/
	virtual void EmptyBasket() { mFruit.clear(); };



private:
	int mX = 0;     ///< Basket X location
	int mY = 0;     ///< Basket Y location

	///vector to store all fruit in basket
	std::vector < std::shared_ptr<CFruit>> mFruit;
};

