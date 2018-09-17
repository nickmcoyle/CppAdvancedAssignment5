#pragma once

#include "IBitmapIterator.h"
#include "IBitmapIterator.h"
#include "ICanvas.h"
#include "Bitmap.h"
#include <stack>

namespace BitmapGraphics
{
	class BasicCanvasBitmapIterator : public IBitmapIterator
	{
	public:
		BasicCanvasBitmapIterator(Bitmap& bitmap);	

		BasicCanvasBitmapIterator(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator(BasicCanvasBitmapIterator&& other) = default;

		BasicCanvasBitmapIterator& operator=(const BasicCanvasBitmapIterator&) = default;
		BasicCanvasBitmapIterator& operator=(BasicCanvasBitmapIterator&&) = default;
		
		void nextScanLine() override;
		bool isEndOfImage() const override;
		void nextPixel() override;
		bool isEndOfScanLine() const override;
		Color getColor() const override;

		int getBitmapWidth() const override;
		int getBitmapHeight() const override;

	private:
		Bitmap& myBitmap;
		Bitmap::ScanLineIterator myScanLine;
		Bitmap::PixelIterator myPixel;
	};
}