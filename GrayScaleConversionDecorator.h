#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{
	class GrayScaleConversionDecorator : public BitmapIteratorDecorator
	{
	public:
		GrayScaleConversionDecorator() = default;
		GrayScaleConversionDecorator(HBitmapIterator originalIterator) :
		BitmapIteratorDecorator{ std::move(originalIterator) }
		{
		}

		GrayScaleConversionDecorator(const GrayScaleConversionDecorator&) = default;
		GrayScaleConversionDecorator(GrayScaleConversionDecorator&&) = default;
		GrayScaleConversionDecorator& operator=(const GrayScaleConversionDecorator&) = default;
		GrayScaleConversionDecorator& operator=(GrayScaleConversionDecorator&&) = default;
		~GrayScaleConversionDecorator() = default;

		Color getColor() const {
			Color const oldColor = myOriginalIterator->getColor();
			//average all the values, similar to what GIMP uses to convert color images to grayscale. works well but lowers contrast slightly
			Binary::Byte const grayScale = (Binary::Byte)((static_cast<int>(oldColor.getRed()) + static_cast<int>(oldColor.getBlue()) + static_cast<int>(oldColor.getGreen())) / 3);

			return Color(grayScale, grayScale, grayScale);
		}	
	};
}