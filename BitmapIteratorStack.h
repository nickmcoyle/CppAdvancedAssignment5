#pragma once

#include "IBitmapIterator.h"
#include "IBitmapIterator.h"
#include "Bitmap.h"
#include <stack>

namespace BitmapGraphics
{
	class BitmapIteratorStack : public IBitmapIterator
	{
	public:
		BitmapIteratorStack(Bitmap& bitmap);
		BitmapIteratorStack(Bitmap& bitmap, const HBitmapIterator& other);

		BitmapIteratorStack(const BitmapIteratorStack& other) = default;
		BitmapIteratorStack(BitmapIteratorStack&& other) = default;			

		BitmapIteratorStack& operator=(const BitmapIteratorStack&) = default;
		BitmapIteratorStack& operator=(BitmapIteratorStack&&) = default;


		void nextScanLine() override;
		bool isEndOfImage() const override;
		void nextPixel() override;
		bool isEndOfScanLine() const override;
		Color getColor() const override;

		int getBitmapWidth() const override;
		int getBitmapHeight() const override;

	private:
		Bitmap & myBitmap;
		Bitmap::ScanLineIterator myScanLine;
		Bitmap::PixelIterator myPixel;
	};
}