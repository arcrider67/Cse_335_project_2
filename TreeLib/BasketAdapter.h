#pragma once
#include "Basket.h"
#include "GrowableImage.h"


class CFruit;


class CBasketAdapter : public CBasket
{
public:
	
	CBasketAdapter();

	virtual void DrawBasket(Gdiplus::Graphics* graphics);


	virtual void SetBasketLocation(int x, int y);

	/**
	 * Empty all fruit from the basket
	*/
	virtual void EmptyBasket() { mFruits.clear(); };

	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit);

private:
	int mX = 0;     ///< Basket X location
	int mY = 0;     ///< Basket Y location

	///vector to store all fruit in basket
	std::vector < std::shared_ptr<CFruit>> mFruits;



	std::shared_ptr<Gdiplus::Bitmap> mFrontImage;
	std::shared_ptr<Gdiplus::Bitmap> mBackImage;


};

