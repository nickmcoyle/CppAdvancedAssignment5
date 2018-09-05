#pragma once

#include "VectorGraphic.h"
#include "Point.h"
#include <memory>

namespace BitmapGraphics
{    
	class IPen;
	using HPen = std::shared_ptr<IPen>;	

    class IPen
    {
    public:
		IPen() = default;
		virtual ~IPen() = default;

		IPen(const IPen &) = delete;
		IPen& operator =(IPen const&) = delete;
		IPen(IPen&&) = delete;
		IPen& operator=(IPen&&) = delete;		
    	
		virtual void drawPoint(VG::Point const& point) = 0;
    };
}