#pragma once

#include "IStroke.h"
#include "Pen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>
#include <memory>

namespace BitmapGraphics
{
	class SlashStroke : public IStroke
	{
	public:
		SlashStroke(const std::string& tip, int size, const Color& color) : myTip(tip), mySize(size), myColor(color) {};

		SlashStroke(const SlashStroke& other) :
			myTip(other.myTip),
			mySize(other.mySize),
			myColor(other.myColor)
		{
		};
		
		SlashStroke(SlashStroke&& other) = default;

		SlashStroke& operator=(const SlashStroke&) = default;
		SlashStroke& operator=(SlashStroke&&) = default;

		void setSize(int size) { mySize = size; };
		int getSize() const { return mySize; };

		void setColor(const Color& color) { myColor = color; };
		Color getColor() const { return myColor; };

		BitmapGraphics::HPen createPen(const BitmapGraphics::HCanvas& canvas) override
		{
			HStroke stroke = std::make_shared<SlashStroke>(*this);
			HPen pen = std::make_shared<Pen>(stroke, canvas);
			return pen;
		};

	private:
		std::string myTip;
		int mySize;
		Color myColor;		
	};
}