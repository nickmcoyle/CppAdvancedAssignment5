#pragma once

namespace BitmapGraphics
{    
    class ICanvas
    {
    public:
		ICanvas() = default;
		virtual ~ICanvas() = default;

		ICanvas(const ICanvas &) = delete;
		ICanvas& operator =(ICanvas const&) = delete;
		ICanvas(ICanvas&&) = delete;
		ICanvas& operator=(ICanvas&&) = delete;		
    	
		virtual void setPixelColor() = 0;
		
		virtual HBitmapIterator createBitmapIterator() = 0;
    };
}