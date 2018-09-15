#include "BitmapIteratorStack.h"

namespace BitmapGraphics
{
	BitmapIteratorStack::BitmapIteratorStack(Bitmap& bitmap) :
		myBitmap{ bitmap },
		myScanLine{ bitmap.begin() }
	{
		if (!BitmapIteratorStack::isEndOfImage())
		{
			myPixel = myScanLine->begin();
		}
	}

	BitmapIteratorStack::BitmapIteratorStack(Bitmap& bitmap, const HBitmapIterator& other) :
	myBitmap(bitmap)	
	{
		std::stack<Bitmap::ScanLine> myStack;		

		BitmapGraphics::Bitmap::ScanLine sl;
		
		while (!other->isEndOfImage())
		{					
			if (other->isEndOfScanLine())
			{
				myStack.push(sl);
				sl.clear();
				other->nextScanLine();

				if (other->isEndOfImage())
				{
					continue;
				}
			}
			sl.emplace_back(std::move(other->getColor()));
			other->nextPixel();			
		}
		 

		while (!myStack.empty())
		{
			BitmapGraphics::Bitmap::ScanLine sl = myStack.top();
			myStack.pop();
			myBitmap.addScanLine(sl);			
		}

		myScanLine = bitmap.begin();
		myPixel = myScanLine->begin();

	}
	
	void BitmapIteratorStack::nextScanLine()
	{
		++myScanLine;
		if (!isEndOfImage())
		{
			myPixel = myScanLine->begin();
		}
	}

	bool BitmapIteratorStack::isEndOfImage() const
	{
		return myScanLine == myBitmap.end();
	}

	void BitmapIteratorStack::nextPixel()
	{
		++myPixel;
	}

	bool BitmapIteratorStack::isEndOfScanLine() const
	{
		return myPixel == myScanLine->end();
	}

	Color BitmapIteratorStack::getColor() const
	{
		return *myPixel;
	}

	int BitmapIteratorStack::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BitmapIteratorStack::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}

}
