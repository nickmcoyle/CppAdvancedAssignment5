#pragma once

#include "IPen.h"
#include "Point.h"

namespace BitmapGraphics
{	
	class RoundPen : public IPen
	{
	public:
		RoundPen() = default;
		RoundPen(int size, Color color);

		RoundPen(const RoundPen &) = default;
		RoundPen& operator =(RoundPen const&) = default;
		RoundPen(RoundPen&&) = default;
		RoundPen& operator=(RoundPen&&) = default;
		
		void drawPoint(const VG::Point& point, const HCanvas& canvas) override;
		
	private:		
		int mySize;
		Color myColor;
	};
}