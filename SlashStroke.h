#pragma once

#include "IStroke.h"
#include "SlashPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>
#include <memory>

namespace BitmapGraphics
{
	class SlashStroke : public IStroke
	{
	public:
		SlashStroke(int size, const Color& color) : mySize(size), myColor(color) {};

		SlashStroke(const SlashStroke& other) = default;
		SlashStroke(SlashStroke&& other) = default;

		SlashStroke& operator=(const SlashStroke&) = default;
		SlashStroke& operator=(SlashStroke&&) = default;

		void setSize(int size) override { mySize = size; };
		int getSize() const override { return mySize; };

		void setColor(const Color& color) override { myColor = color; };
		Color getColor() const override { return myColor; };
		
		BitmapGraphics::HPen createPen() override
		{
			HPen pen = std::make_shared<SlashPen>(mySize, myColor);
			return pen;
		};

	private:		
		int mySize;
		Color myColor;		
	};
}