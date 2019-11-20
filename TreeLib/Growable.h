#pragma once

#include "pch.h"
#include <vector>
#include <memory>

class CTreeAdapter;
class CLimb;

class CGrowable
{
public:

	CGrowable();

	/** Copy constructor disabled */
	CGrowable(const CGrowable&) = delete;
	/** Assignment operator disabled */
	void operator=(const CGrowable&) = delete;

	virtual void Grow();

	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	void SetTree(CTreeAdapter* tree) { mHostTree = tree; }

	virtual void Draw(Gdiplus::Graphics* graphics);

	void CalcGrownFactor();

	void SetParent(CGrowable* parent) { mParent = parent; }

	void AddChild(std::shared_ptr<CGrowable> child) { mChildren.push_back(child); child->SetParent(this); }

	void SetDepth(int depth) { mDepth = depth; }

	int GetDepth() { return mDepth; }

	void SetStartFrame(int frame) { mStartFrame = frame;}

	int GetStartFrame() { return mStartFrame; }

	int GetFrameAge() { return mMatureFrameAge; }

	void SetAngle(double angle) { mAngle = angle; }

	double CalcAdjacent(double hypo);

	double CalcOpposite( double hypo);

	void GenerateAngle();

	double GetAngle() { return mAngle; }

	void GrowChildren();

	CGrowable* GetParent() { return mParent; }


	Gdiplus::Point GetEndpoint() { return mEndpoint; }
	void SetEndpoint(Gdiplus::Point point) { mEndpoint = point; }

	virtual void GetParentInfo();

private:

	int mDepth = 0;

	///angle from verticle
	double mAngle = 0;

	Gdiplus::Point mEndpoint;


	///remove protected switch to private with getters and setters
protected:
	int mStartFrame = 0;
	int mMatureFrameAge = 10;

	///decimal from 0 to 1 how close the object is to fully grown
	float mGrownFactor = 1;

	/// X position relative to the tree root
	double mX = 0;
	/// Y position relative to the tree root
	double mY = 0;

	std::vector<std::shared_ptr<CGrowable>> mChildren;
	CGrowable* mParent = nullptr;

	CTreeAdapter* mHostTree;
};

