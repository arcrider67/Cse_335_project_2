#pragma once
#include "Growable.h"
#include <string>

class CGrowableImage :
	public CGrowable
{
public:

public:
	CGrowableImage(const std::wstring &name);

	/// Default constructor/disabled
	CGrowableImage() = delete;

	/// Copy constructor/disabled
	CGrowableImage(const CGrowableImage&) = delete;

	/// Destructor
	virtual ~CGrowableImage() {}

	void CGrowableImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y);

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image

};

