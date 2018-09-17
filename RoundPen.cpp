#include "RoundPen.h"

namespace BitmapGraphics
{

	RoundPen::RoundPen(int size, Color color) :
	mySize(size),
	myColor(color)
	{
	}

	void RoundPen::drawPoint(const VG::Point& point, const HCanvas& canvas)
	{		
		int offset = mySize / 2;		

		//only draw center point if tip size is odd
		if (mySize % 2 != 0)
		{
			canvas->setPixelColor(point, myColor);
		}					
		
		/* .
		  .o.
		   .
		*/
		canvas->setPixelColor(VG::Point((point.getX() + 1), point.getY()), myColor);
		canvas->setPixelColor(VG::Point((point.getX() - 1), point.getY()), myColor);
		canvas->setPixelColor(VG::Point(point.getX(), (point.getY() + 1)), myColor);
		canvas->setPixelColor(VG::Point(point.getX(), (point.getY() - 1)), myColor);
		
		/* ...
		   .o.
		   ...
		*/
		canvas->setPixelColor(VG::Point((point.getX() + 1), (point.getY() + 1)), myColor);
		canvas->setPixelColor(VG::Point((point.getX() - 1), (point.getY() - 1)), myColor);								
		canvas->setPixelColor( VG::Point((point.getX() + 1), (point.getY() - 1)), myColor);
		canvas->setPixelColor( VG::Point((point.getX() - 1), (point.getY() + 1)), myColor);				
			
		/*  ...
		   ..o..
		    ...
		*/
		canvas->setPixelColor(VG::Point((point.getX() + 2), point.getY()), myColor);
		canvas->setPixelColor(VG::Point((point.getX() - 2), point.getY()), myColor);	

		/*   .
		    ...
		   ..o..
		    ...
			 .
		*/
		canvas->setPixelColor(VG::Point((point.getX()), (point.getY() + 2) ), myColor);
		canvas->setPixelColor(VG::Point((point.getX()), (point.getY() + 2) ), myColor);				
			
	}
	
}