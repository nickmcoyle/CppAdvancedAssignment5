#pragma once

#include "ICanvas.h"
#include <list>

namespace BitmapGraphics
{
    class BasicCanvas : public ICanvas
    {   
    public:               
		BasicCanvas() = default;
        BasicCanvas(int width, int height) : myWidth{width}, myHeight{height} { }
        
		BasicCanvas(const BasicCanvas&) = default;
		BasicCanvas(BasicCanvas&&) = default;

		BasicCanvas& operator=(const BasicCanvas&) = default;
		BasicCanvas& operator=(BasicCanvas&&) = default;        
        
        int getWidth() const { return myWidth; }
        int getHeight() const { return myHeight; }       
        
    private:
		int myWidth{ 0 };
        int myHeight{ 0 };        
    };   
}
