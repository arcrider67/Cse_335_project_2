#include "pch.h"
#include "GrowableImage.h"

using namespace Gdiplus;

CGrowableImage::CGrowableImage(const std::wstring &filename) {

	mImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));

}

void CGrowableImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y)
{
	auto state = graphics->Save();
    graphics->TranslateTransform((float)x, (float)y);
    graphics->RotateTransform((float)(angle * RtoD));
    graphics->ScaleTransform((float)scale, (float)scale);
    graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2,
        -(int)mImage->GetHeight(),
        mImage->GetWidth(), mImage->GetHeight());
    graphics->Restore(state);
}
