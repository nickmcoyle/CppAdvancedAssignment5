#pragma once

#include "IStroke.h"
#include "SquarePen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class SquareStroke : public IStroke
	{
	public:
		SquareStroke(int size, const Color& color) :mySize(size), myColor(color) {};

		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;		

		void setSize(int size) override { mySize = size; };
		int getSize() const override { return mySize; };

		void setColor(const Color& color) override { myColor = color; };
		Color getColor() const override { return myColor; };
				
		BitmapGraphics::HPen createPen() override
		{			
			HPen pen = std::make_shared<SquarePen>(mySize, myColor);
			return pen;
		};

	private:			
		int mySize;
		Color myColor;	
	};
}