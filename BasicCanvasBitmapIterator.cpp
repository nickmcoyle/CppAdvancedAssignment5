#include "BasicCanvasBitmapIterator.h"
#include <memory>

namespace BitmapGraphics
{

	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(Bitmap& bitmap) :
	myBitmap{ bitmap },
	myScanLine{ bitmap.begin() },
	myPixel{ myScanLine->begin() }
	{		
		
		std::stack<Bitmap::ScanLine> myStack;		

		for (myScanLine; myScanLine != bitmap.end(); ++myScanLine)
		{
			myStack.push(*myScanLine);
		}

		Bitmap flippedBitmap(bitmap.getWidth(), bitmap.getHeight());

		while (!myStack.empty())
		{				
			flippedBitmap.addScanLine(myStack.top());
			myStack.pop();
		}

		myBitmap = flippedBitmap;
		myScanLine = bitmap.begin();
		myPixel = myScanLine->begin();

	}	
	
	void BasicCanvasBitmapIterator::nextScanLine()
	{
		++myScanLine;
		if (!isEndOfImage())
		{
			myPixel = myScanLine->begin();
		}
	}

	bool BasicCanvasBitmapIterator::isEndOfImage() const
	{
		return myScanLine == myBitmap.end();
	}

	void BasicCanvasBitmapIterator::nextPixel()
	{
		++myPixel;
	}

	bool BasicCanvasBitmapIterator::isEndOfScanLine() const
	{
		return myPixel == myScanLine->end();
	}

	Color BasicCanvasBitmapIterator::getColor() const
	{
		return *myPixel;
	}

	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}

}
