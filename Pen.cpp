#include "Pen.h"
#include <vector>

namespace BitmapGraphics
{

	Pen::Pen(const HStroke& stroke, const HCanvas& canvas) :
	myStroke(stroke),
	myCanvas(canvas)	
	{
	}

	void Pen::drawPoint(const VG::Point& point)
	{
		Color color = myStroke->getColor();
		std::string tip = myStroke->getTip();
		int size = myStroke->getSize();
		int offset = size / 2;		

		//only draw center point if tip size is odd
		if (size % 2 != 0)
		{
			myCanvas->setPixelColor(point, color);
		}

		std::vector<VG::Point> points;
		for (offset; offset > 0; --offset)
		{	
			if(tip == "square")
			{
				VG::Point p1((point.getX() + offset), point.getY());
				VG::Point p2((point.getX() - offset), point.getY());
				VG::Point p3(point.getX(), (point.getY() + offset));
				VG::Point p4(point.getX(), (point.getY() - offset));
				VG::Point p5((point.getX() + offset), (point.getY() + offset));
				VG::Point p6((point.getX() - offset), (point.getY() - offset));
				VG::Point p7((point.getX() + offset), (point.getY() - offset));
				VG::Point p8((point.getX() - offset), (point.getY() + offset));
				points.push_back(p1);
				points.push_back(p2);
				points.push_back(p3);
				points.push_back(p4);
				points.push_back(p5);
				points.push_back(p6);
				points.push_back(p7);
				points.push_back(p8);
			}

			if (tip == "slash")
			{				
				points.push_back(VG::Point((point.getX() - offset), (point.getY() + offset)));				
			}

			for (const auto& point : points)
			{
				myCanvas->setPixelColor(point, color);
			}
			
		}

		
		
	}

}