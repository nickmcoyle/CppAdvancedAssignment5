#include "Pen.h"

namespace BitmapGraphics
{

	Pen::Pen(const HStroke& stroke, const HCanvas& canvas) :
	myStroke(stroke),
	myCanvas(canvas)
	{
	}

	void Pen::drawPoint(const VG::Point& point)
	{
		myCanvas->setPixelColor(point, myStroke->getColor());
	}

}