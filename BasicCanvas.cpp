#include "BasicCanvas.h"
#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{
		
	BasicCanvas::BasicCanvas(int width, int height, Color bgColor) :
	myWidth{ width },
	myHeight{ height },
	myBackgroundColor{ bgColor }	
	{		
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
		if (location.getX() > myWidth || location.getY() > myHeight)
		{
			throw std::runtime_error("Invalid point (" + std::string(std::to_string(location.getX())) + "," + std::string(std::to_string(location.getY())) + ") passed to getPixelColor method");
		}

		std::map<VG::Point, Color>::const_iterator it;
		it = myCanvas.find(location);
		if (it != myCanvas.end())
		{
			return it->second;
		}		

		return myBackgroundColor;			
	}	
	
	HBitmapIterator BasicCanvas::createBitmapIterator()
	{			
		return std::make_unique<BasicCanvasBitmapIterator>(*this);
	}
}