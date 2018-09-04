#pragma once

namespace BitmapGraphics
{    
    class IStroke
    {
    public:
		IStroke() = default;
		virtual ~IStroke() = default;

		IStroke(const IStroke &) = delete;
		IStroke& operator =(IStroke const&) = delete;
		IStroke(IStroke&&) = delete;
		IStroke& operator=(IStroke&&) = delete;		
		
		virtual HPen createPen() = 0;    	
    };
}