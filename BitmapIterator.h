#pragma once

#include "IBitmapIterator.h"
#include "Bitmap.h"

namespace BitmapGraphics
{
    class BitmapIterator : public IBitmapIterator
    {
    public:
        BitmapIterator(Bitmap& bitmap);

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) = default;

		BitmapIterator& operator=(const BitmapIterator&) = default;
		BitmapIterator& operator=(BitmapIterator&&) = default;		

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