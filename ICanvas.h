#pragma once

#include "Point.h"
#include "Color.h"
#include "IBitmapIterator.h"
#include <memory>
#include <map>

namespace BitmapGraphics
{   		
	class ICanvas
    {
    public:
		using PixelMap = std::map<VG::Point, Color>;
		using BasicCanvasIterator = PixelMap::iterator;

		ICanvas() = default;
		virtual ~ICanvas() = default;

		ICanvas(const ICanvas &) = delete;
		ICanvas& operator =(ICanvas const&) = delete;
		ICanvas(ICanvas&&) = delete;
		ICanvas& operator=(ICanvas&&) = delete;		
    	
		virtual void setPixelColor(const VG::Point& location, const Color& color) = 0;
		virtual Color getPixelColor(const VG::Point& location) const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;		

		virtual HBitmapIterator createBitmapIterator() = 0;
    };

	using HCanvas = std::shared_ptr<ICanvas>;	
}