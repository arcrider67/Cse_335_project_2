#pragma once
#include "Fruit.h"
#include "GrowableImage.h"

class CBasketAdapter;


class CFruitAdapter : public CFruit, public CGrowableImage
{
public:
	CFruitAdapter();


	virtual void SetBasketPosition(int x, int y) {}

	virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y);

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual void Accept(CGrowableVisitor* visitor) { visitor->VisitFruit(GetSelf()); };

	void SetSelf(std::shared_ptr<CFruit> self) { mSelf = self; }
	std::shared_ptr<CFruit> GetSelf() { return mSelf.lock(); }

private:
	bool mInBasket = false;

	std::weak_ptr<CFruit> mSelf;



};

