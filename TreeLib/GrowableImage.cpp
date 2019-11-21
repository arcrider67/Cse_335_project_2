#include "pch.h"
#include "GrowableImage.h"
#include "TreeAdapter.h"

using namespace Gdiplus;

const double RtoD = 0.0174533;

CGrowableImage::CGrowableImage(const std::wstring &filename) : CGrowable() {

}

void CGrowableImage::Draw(Gdiplus::Graphics* graphics)
{
	double angle = GetAngle();

	CTreeAdapter* tree = GetTree();


	double x = GetEndpoint().X;
	double y = GetEndpoint().Y;

	double scale = GetGrowthFactor() * mImageScale;

	if (scale > 0) {
		auto state = graphics->Save();
		graphics->TranslateTransform((float)x, (float)y);
		graphics->RotateTransform((float)(angle));
		graphics->ScaleTransform((float)scale, (float)scale);
		graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2,
			-(int)mImage->GetHeight(),
			mImage->GetWidth(), mImage->GetHeight());
		graphics->Restore(state);
	}
}


