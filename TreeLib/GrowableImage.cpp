#include "pch.h"
#include "GrowableImage.h"

using namespace Gdiplus;

CGrowableImage::CGrowableImage(const std::wstring &filename) {

	mImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));

}

void CGrowableImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y)
{
	//graphics->DrawImage(mImage, x, y);
}
