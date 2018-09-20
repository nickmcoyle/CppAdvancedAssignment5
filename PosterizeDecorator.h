#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{
	class PosterizeDecorator : public BitmapIteratorDecorator
	{
	public:
		PosterizeDecorator() = default;
		
		PosterizeDecorator(HBitmapIterator originalIterator) :
			BitmapIteratorDecorator{ std::move(originalIterator) }
		{
		}

		PosterizeDecorator(const PosterizeDecorator&) = default;
		PosterizeDecorator(PosterizeDecorator&&) = default;
		PosterizeDecorator& operator=(const PosterizeDecorator&) = default;
		PosterizeDecorator& operator=(PosterizeDecorator&&) = default;
		~PosterizeDecorator() = default;

		const Binary::Byte& posterizeColor(const int& color) const
		{			
			if (color < 64)
			{
				return Binary::Byte(31);
			}

			if (color > 63 && color < 128)
			{
				return Binary::Byte(95);
			}

			if (color > 127 && color < 192)
			{
				return Binary::Byte(159);
			}

			if (color > 191 && color < 256)
			{
				return Binary::Byte(223);
			}
			return static_cast<Binary::Byte>(color);
		}

		Color getColor() const {
			Color const oldColor = myOriginalIterator->getColor();
			
			Binary::Byte const red = posterizeColor(static_cast<int>(oldColor.getRed()));
			Binary::Byte const green = posterizeColor(static_cast<int>(oldColor.getGreen()));
			Binary::Byte const blue = posterizeColor(static_cast<int>(oldColor.getBlue()));			

			return Color(red, green, blue);
		}	
	};
}