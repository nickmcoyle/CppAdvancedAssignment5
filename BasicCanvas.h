#pragma once

#include "ICanvas.h"
#include "Point.h"
#include "Color.h"
#include "Bitmap.h"
#include "BitmapIterator.h"
#include <list>
#include <map>

namespace BitmapGraphics
{
	class BasicCanvas : public ICanvas
	{
	public:
		BasicCanvas() = default;
		//BasicCanvas(int width, int height) : myWidth{width}, myHeight{height} { }
		BasicCanvas(int width, int height, Color bgColor = Color{ Binary::Byte(255),Binary::Byte(255),Binary::Byte(255) });
        
		BasicCanvas(const BasicCanvas&) = default;
		BasicCanvas(BasicCanvas&&) = default;

		~BasicCanvas() = default;

		BasicCanvas& operator=(const BasicCanvas&) = default;
		BasicCanvas& operator=(BasicCanvas&&) = default;        
        
		void setPixelColor(const VG::Point& location, const Color& color) override;
		Color getPixelColor(const VG::Point& location) const override;

        int getWidth() const override { return myWidth; }
        int getHeight() const override { return myHeight; }       		
		
		HBitmapIterator createBitmapIterator() override;		
        
    private:
		int myWidth{ 0 };
        int myHeight{ 0 };
		std::map<VG::Point, Color> myCanvas;
		Color backgroundColor;
    };   
}
