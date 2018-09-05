#pragma once

#include "ICanvas.h"
#include "Point.h"
#include "Color.h"
#include <list>
#include <map>

namespace BitmapGraphics
{
    class BasicCanvas : public ICanvas
    {   
    public:               
		BasicCanvas() = default;
        BasicCanvas(int width, int height) : myWidth{width}, myHeight{height} { }
        
		BasicCanvas(const BasicCanvas&) = default;
		BasicCanvas(BasicCanvas&&) = default;

		~BasicCanvas() = default;

		BasicCanvas& operator=(const BasicCanvas&) = default;
		BasicCanvas& operator=(BasicCanvas&&) = default;        
        
        virtual int getWidth() const override { return myWidth; }
        virtual int getHeight() const override { return myHeight; }       
        
    private:
		int myWidth{ 0 };
        int myHeight{ 0 };
		std::map<std::pair<VG::Point, VG::Point>, Color> myCanvas;
    };   
}
