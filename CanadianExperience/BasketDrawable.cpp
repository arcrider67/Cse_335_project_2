#include "pch.h"
#include "BasketDrawable.h"
#include "TreeFactory.h"
#include "Basket.h"


CBasketDrawable::CBasketDrawable(std::wstring name) : CDrawable(name){
	CTreeFactory treeFactory;
	mBasket = treeFactory.CreateBasket();
}

void CBasketDrawable::Draw(Gdiplus::Graphics* graphics)
{
	mBasket->SetBasketLocation(GetPosition().X, GetPosition().Y);
	mBasket->DrawBasket(graphics);
}

void CBasketDrawable::AddFruits(std::vector < std::shared_ptr<CFruit>> fruit) {
	mBasket->AddToBasket(fruit);
}

