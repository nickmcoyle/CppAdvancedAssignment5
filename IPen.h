#pragma once

#include "Point.h"
#include <memory>

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
    	
		virtual void drawPoint(const VG::Point& point) = 0;
    };

	using HPen = std::shared_ptr<IPen>;
}