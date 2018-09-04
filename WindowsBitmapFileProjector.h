#pragma once

#include "IProjector.h"
#include <list>

namespace BitmapGraphics
{
    class WindowsBitmapFileProjector : public IProjector
    {
   
    public:               
		WindowsBitmapFileProjector() = default;
        WindowsBitmapFileProjector(int width, int height) : myWidth{width}, myHeight{height} { }
        
		WindowsBitmapFileProjector(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&&) = default;

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&&) = default;        
        
        int getWidth() const { return myWidth; }
        int getHeight() const { return myHeight; }     
        
        
    private:
		int myWidth{ 0 };
        int myHeight{ 0 };        
    };   
}
