#pragma once
#include "Drawable.h"

class CBasket;
class CFruit;

class CBasketDrawable : public CDrawable
{
public:

	CBasketDrawable() = delete;

	CBasketDrawable(std::wstring name);

	virtual void Draw(Gdiplus::Graphics* graphics);


	virtual bool HitTest(Gdiplus::Point pos) { return false; };

	void AddFruits(std::vector < std::shared_ptr<CFruit>> fruit);

private:

	std::shared_ptr<CBasket> mBasket;
};

