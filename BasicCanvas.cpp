#include "BasicCanvas.h"

namespace BitmapGraphics
{
		
	BasicCanvas::BasicCanvas(int width, int height, Color bgColor) :
	myWidth{ width },
	myHeight{ height },
	backgroundColor{ bgColor },
	myBitmap {myWidth, myHeight}
	{
		int y = myHeight - 1, x = 0;
		
		for (y; y >= 0; --y)
		{
			for (x; x < myWidth; ++x)
			{				
				myCanvas.emplace(std::move(VG::Point(x,y)), std::move(backgroundColor));								
			}
			x = 0;			
		}
	}
	
	void BasicCanvas::setPixelColor(const VG::Point& location, const Color& color)
	{
		if (location.getX() > myWidth || location.getY() > myHeight)
		{
			throw std::invalid_argument("The Point (" + std::string(std::to_string(location.getX())) + "," + std::string(std::to_string(location.getY())) + ") is invalid for this Canvas. Index out of range.");
		}
		
		myCanvas[location] = color;
	}

	Color BasicCanvas::getPixelColor(const VG::Point& location) const
	{
		std::map<VG::Point, Color>::const_iterator it;
		it = myCanvas.find(location);
		if (it != myCanvas.end())
		{
			return it->second;
		}
		throw std::runtime_error("Invalid point (" + std::string(std::to_string(location.getX())) + "," + std::string(std::to_string(location.getY())) + ") passed to getPixelColor method");
	}	

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{			
		std::map<VG::Point, Color>::const_iterator it;
		
		BitmapGraphics::Bitmap::ScanLine sl;
		
		for (it = myCanvas.begin(); it != myCanvas.end(); ++it) 
		{		
			sl.emplace_back(std::move(it->second));
			if (it->first.getX() == myWidth-1)
			{				
				myBitmap.addScanLine(sl);
				sl.clear();
			}
		}

		return std::make_unique<BitmapIterator>(myBitmap);
	}
}