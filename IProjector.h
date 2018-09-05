#pragma once

namespace BitmapGraphics
{    
	
    class IProjector
    {
    public:
		IProjector() = default;
		virtual ~IProjector() = default;

		IProjector(const IProjector &) = delete;
		IProjector& operator =(IProjector const&) = delete;
		IProjector(IProjector&&) = delete;
		IProjector& operator=(IProjector&&) = delete;		
    	
		virtual void projectCanvas(const HCanvas& canvas) = 0;
    };
}