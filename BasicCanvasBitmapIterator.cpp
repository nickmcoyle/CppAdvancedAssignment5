#include "BasicCanvasBitmapIterator.h"
#include <memory>

namespace BitmapGraphics
{

	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(const BasicCanvas& canvas) :
	myCanvas{ canvas },
	myCurrentPoint{ VG::Point(0,0) }	
	{	
	}	
	
	void BasicCanvasBitmapIterator::nextScanLine()
	{		
		if (!isEndOfImage())
		{
			myCurrentPoint = VG::Point(0, myCurrentPoint.getY() + 1);
		}
	}

	bool BasicCanvasBitmapIterator::isEndOfImage() const
	{
		return myCurrentPoint.getY() >= myCanvas.getHeight();
	}

	void BasicCanvasBitmapIterator::nextPixel()
	{
		if (!isEndOfImage())
		{
			if (isEndOfScanLine())
			{
				nextScanLine();
			}
			else 
			{
				myCurrentPoint = VG::Point(myCurrentPoint.getX() + 1, myCurrentPoint.getY());
			}
		}		
	}

	bool BasicCanvasBitmapIterator::isEndOfScanLine() const
	{
		return myCurrentPoint.getX() >= myCanvas.getWidth();
	}

	Color BasicCanvasBitmapIterator::getColor() const
	{
		return myCanvas.getPixelColor(myCurrentPoint);
	}

	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myCanvas.getWidth();
	}

	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myCanvas.getHeight();
	}

}
