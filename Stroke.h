#pragma once

#include "IStroke.h"
#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class Stroke : public IStroke
	{
	public:
		Stroke() = default;
		Stroke(const Stroke& other) = default;
		Stroke(Stroke&& other) = default;
		Stroke& operator=(const Stroke&) = default;
		Stroke& operator=(Stroke&&) = default;

		Stroke(int size, Color color) : mySize(size), myColor(color) {};

		void setSize(int size) override { mySize = size; };
		int getSize() const override { return mySize; };

		void setColor(const Color& color) override { myColor = color; };
		Color getColor() const override { return myColor; };

		BitmapGraphics::HPen createPen(const BitmapGraphics::HCanvas& canvas) override
		{
			HPen pen = std::make_shared<IPen>(*this, canvas);
			return pen;
		};

	protected:		
		int mySize;
		Color myColor;
	};
}