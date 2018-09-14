#pragma once

#include "IStroke.h"
#include "Pen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class SquareStroke : public IStroke
	{
	public:
		SquareStroke(std::string tip, int size, const Color& color) : myTip(tip), mySize(size), myColor(color) {};

		SquareStroke(const SquareStroke& other) :
			myTip(other.myTip),
			mySize(other.mySize),
			myColor(other.myColor)
		{			
		};

		SquareStroke(SquareStroke&& other) = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;
				
		~SquareStroke() = default;

		void setSize(int size) { mySize = size; };
		int getSize() const { return mySize; };

		void setColor(const Color& color) { myColor = color; };
		Color getColor() const { return myColor; };

		BitmapGraphics::HPen createPen(const BitmapGraphics::HCanvas& canvas) override
		{			
			HStroke stroke = std::make_shared<SquareStroke>(*this);
			HPen pen = std::make_shared<Pen>(stroke, canvas);
			return pen;
		};

	private:	
		std::string myTip;
		int mySize;
		Color myColor;	
	};
}