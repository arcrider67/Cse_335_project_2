#include "pch.h"
#include "GrowableVisitor.h"
#include "FruitAdapter.h"

void CGrowableVisitor::VisitFruit(std::shared_ptr<CFruit> fruit)
{
	mFruits.push_back(fruit);
}
