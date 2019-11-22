/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"

#include "TreeDrawable.h"
#include "TreeFactory.h"
#include "BasketDrawable.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

	//create basket
	auto basketActor = std::make_shared<CActor>(L"BasketActor");
	auto basketDrawable = std::make_shared<CBasketDrawable>(L"Basket");

	
	basketActor->AddDrawable(basketDrawable);
	basketDrawable->SetPosition(Point(300, 550));

	//create First tree
	auto tree = std::make_shared<CActor>(L"TreeActor");
	auto treeDrawable = std::make_shared<CTreeDrawable>(L"Tree");

	picture->AddActor(tree);
	tree->AddDrawable(treeDrawable);
	treeDrawable->SetPosition(Point(100, 550));
	treeDrawable->SetBasket(basketDrawable);

	// Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);




	///create second tree
	tree = std::make_shared<CActor>(L"TreeActor");
	treeDrawable = std::make_shared<CTreeDrawable>(L"Tree");

	picture->AddActor(tree);
	tree->AddDrawable(treeDrawable);
	treeDrawable->SetPosition(Point(600, 550));
	treeDrawable->SetBasket(basketDrawable);




	picture->AddActor(basketActor);
	
	return picture;
}
