#pragma once

#include "VectorGraphic.h"

namespace BitmapGraphics
{    
    class IPen
    {
    public:
		IPen() = default;
		virtual ~IPen() = default;

		IPen(const IPen &) = delete;
		IPen& operator =(IPen const&) = delete;
		IPen(IPen&&) = delete;
		IPen& operator=(IPen&&) = delete;		
    	
		virtual void drawPoint(const HCanvas&, const Point&) = 0;		
    };
}