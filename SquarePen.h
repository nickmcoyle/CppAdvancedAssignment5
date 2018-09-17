#pragma once

#include "IPen.h"
#include "Point.h"

namespace BitmapGraphics
{	
	class SquarePen : public IPen
	{
	public:
		SquarePen() = default;
		SquarePen(int size, Color color);

		SquarePen(const SquarePen &) = default;
		SquarePen& operator =(SquarePen const&) = default;
		SquarePen(SquarePen&&) = default;
		SquarePen& operator=(SquarePen&&) = default;
		
		void drawPoint(const VG::Point& point, const HCanvas& canvas) override;
		
	private:		
		int mySize;
		Color myColor;
	};
}