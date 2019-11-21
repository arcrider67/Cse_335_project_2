#pragma once

#include <vector>
#include <memory>


class CLimb;
class CFruitAdapter;
class CLeaf;
class CGrowable;
class CFruit;

class CGrowableVisitor
{
public:
	/** Visit a CFruit object
	* \param fruit Fruit we are visiting */
	virtual void VisitFruit(std::shared_ptr<CFruit> fruit);

	std::vector<std::shared_ptr<CFruit>> getFruits() { return mFruits; }

private:

	
	CGrowable* mPicker;

	std::vector<std::shared_ptr<CFruit>> mFruits;
};

