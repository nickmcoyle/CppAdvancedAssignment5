#include "SlashPen.h"

namespace BitmapGraphics
{

	SlashPen::SlashPen(int size, Color color) :
	mySize(size),
	myColor(color)
	{
	}

	void SlashPen::drawPoint(const VG::Point& point, const HCanvas& canvas)
	{		
		int offset = mySize / 2;		

		//only draw center point if tip size is odd
		if (mySize % 2 != 0)
		{
			canvas->setPixelColor(point, myColor);
		}
		
		for (offset; offset > 0; --offset)
		{			
			canvas->setPixelColor( VG::Point( (point.getX() - offset), (point.getY() + offset) ), myColor);
			canvas->setPixelColor(VG::Point((point.getX() + offset), (point.getY() - offset)), myColor);
		}				
	}
	
}