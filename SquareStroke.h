#pragma once

#include "IStroke.h"
#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class SquareStroke : public IStroke
	{
	public:
		SquareStroke(std::string tip, int size, Color color) : myTip(tip), mySize(size), myColor(color) {};

		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;

		void setSize(int size) override { mySize = size;  };
		int getSize() const override { return mySize; };

		void setColor(const Color& color) override { myColor = color; };
		Color getColor() const override { return myColor; };

		BitmapGraphics::HPen createPen(const BitmapGraphics::HCanvas& canvas) override
		{
			HPen pen = std::make_shared<IPen>(*this);
			return pen;
		};

	private:	
		std::string myTip;
		int mySize;
		Color myColor;
	};
}