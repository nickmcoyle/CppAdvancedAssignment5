#pragma once

#include "IPen.h"
#include "Point.h"

namespace BitmapGraphics
{	
	class SlashPen : public IPen
	{
	public:
		SlashPen() = default;
		SlashPen(int size, Color color);

		SlashPen(const SlashPen &) = default;
		SlashPen& operator =(SlashPen const&) = default;
		SlashPen(SlashPen&&) = default;
		SlashPen& operator=(SlashPen&&) = default;
				
		void drawPoint(const VG::Point& point, const HCanvas& canvas) override;	

	private:		
		int mySize;
		Color myColor;
	};
}