#include "pch.h"
#include "Limb.h"

using namespace Gdiplus;

void CLimb::Draw(Gdiplus::Graphics* graphics, double treeX, double treeY) {
	
	CalcGrownFactor();
	Pen pen(Color(139, 69, 19), (REAL)5 * mGrownFactor);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)mX, (REAL)mY, (REAL)(mX), (REAL)(mY - 100.0 * mGrownFactor));

}