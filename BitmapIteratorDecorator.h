#pragma once

#include "IBitmapIterator.h"

namespace BitmapGraphics
{
    class BitmapIteratorDecorator : public IBitmapIterator
    {
    public:
	    explicit BitmapIteratorDecorator(HBitmapIterator originalIterator);

		BitmapIteratorDecorator(const BitmapIteratorDecorator& other) = default;
		BitmapIteratorDecorator(BitmapIteratorDecorator&& other) = default;

		BitmapIteratorDecorator& operator=(const BitmapIteratorDecorator&) = default;
		BitmapIteratorDecorator& operator=(BitmapIteratorDecorator&&) = default;
		
    	void nextScanLine() override;
        bool isEndOfImage() const override;;
        void nextPixel() override;;
        bool isEndOfScanLine() const override;;
        
        int getBitmapWidth() const override;;
        int getBitmapHeight() const override;;
        
    protected:
        HBitmapIterator myOriginalIterator;
    };
}