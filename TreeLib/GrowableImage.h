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

	virtual void Draw(Gdiplus::Graphics* graphics);

	void SetScale(double scale) { mImageScale = scale; }

	void SetImage(std::shared_ptr<Gdiplus::Bitmap> image) { mImage = image; }

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image

	double mImageScale = 1; 

};

