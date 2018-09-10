#include "BasicCanvas.h"

namespace BitmapGraphics
{
		
	BasicCanvas::BasicCanvas(int width, int height, Color bgColor) : 
	myWidth{ width },
	myHeight{ height },
	backgroundColor{ bgColor } 
	{
		int y = myHeight - 1;
		int x = 0;
		
		while (y >= 0)
		{
			while (x < myWidth)
			{
				VG::Point location(x, y);				
				myCanvas[location] = backgroundColor;
				++x;
			}
			x = 0;
			--y;
		}
	}
	
	void BasicCanvas::setPixelColor(const VG::Point& location, const Color& color)
	{
		if (location.getX() > myWidth || location.getY() > myHeight)
		{
			throw std::invalid_argument("Point is out invalid for Canvas");
		}

		//myCanvas.insert(std::pair<VG::Point, Color>(location, color));
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
		throw std::runtime_error("Invalid point passed to getPixelColor method");
	}	

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{		
		auto hBitmap = std::make_shared<Bitmap>(Bitmap(myWidth,myHeight));
		
		std::map<VG::Point, Color>::const_iterator it;
		
		BitmapGraphics::Bitmap::ScanLine sl;
		
		for (it = myCanvas.begin(); it != myCanvas.end(); ++it) 
		{		
			sl.emplace_back(it->second);
			if (it->first.getX() == myWidth)
			{
				hBitmap->addScanLine(sl);
				sl.clear();
			}
		}

		return std::make_unique<BitmapGraphics::BitmapIterator>(*hBitmap);
	}
}