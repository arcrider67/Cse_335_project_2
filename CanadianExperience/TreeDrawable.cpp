#include "pch.h"
#include "TreeDrawable.h"
#include "Tree.h"
#include "TreeFactory.h"

#include "Picture.h"
#include "Actor.h"
#include "BasketDrawable.h"

CTreeDrawable::CTreeDrawable(std::wstring name) : CDrawable(name) {
	CTreeFactory treeFactory;
	mTree = treeFactory.CreateTree();
	

}

void CTreeDrawable::Draw(Gdiplus::Graphics* graphics) {



	///get current frame
	CActor* actor = GetActor();
	CPicture* pic = actor->GetPicture();
	
	int frameRate = pic->GetTimeline()->GetFrameRate();

	int currentFrame = pic->GetAnimationTime() * frameRate;
	mTree->SetTreeFrame(currentFrame);

	if (currentFrame >= mHarvestFrame && mHarvested == false) {
		std::vector < std::shared_ptr<CFruit>> fruits = mTree->Harvest();
		mBasket->AddFruits(fruits);
		mHarvested = true;
	}


	mTree->SetRootLocation(GetPosition().X, GetPosition().Y);
	mTree->DrawTree(graphics);

}
