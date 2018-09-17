#pragma once

#include "Point.h"
#include "ICanvas.h"
#include "LineIterator.h"
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
    	
		virtual void drawPoint(const VG::Point& point, const HCanvas& canvas) = 0;		

		virtual void drawLine(VG::Point beginPoint, VG::Point endPoint, const HCanvas& canvas)
		{
			auto lineIter = LineIterator(beginPoint, endPoint);
			while (!lineIter.isEnd())
			{
				this->drawPoint(lineIter.getCurrentPoint(), canvas);
				lineIter.nextPoint();
			}
		}
    };

	using HPen = std::shared_ptr<IPen>;
}