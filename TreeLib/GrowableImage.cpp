#include "pch.h"
#include "GrowableImage.h"

using namespace Gdiplus;

CGrowableImage::CGrowableImage(std::wstring filename) {

	//mImage = std::make_shared<Bitmap>(Bitmap::FromFile(filename));

}

void CGrowableImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y)
{
	//graphics->DrawImage(mImage);
}
