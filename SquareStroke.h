#pragma once

#include "Stroke.h"
#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class SquareStroke : public Stroke
	{
	public:
		SquareStroke(const std::string& tip, int size, const Color& color) : myTip(tip), mySize(size), myColor(color) {};

		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;
				
	private:	
		std::string myTip;
		int mySize;
		Color myColor;		
	};
}