#pragma once

#include "IStroke.h"
#include "RoundPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class RoundStroke : public IStroke
	{
	public:
		RoundStroke(int size, const Color& color) :mySize(size), myColor(color) {};

		RoundStroke(const RoundStroke&) = default;
		RoundStroke(RoundStroke&& other) = default;

		RoundStroke& operator=(const RoundStroke&) = default;
		RoundStroke& operator=(RoundStroke&&) = default;
						
		void setSize(int size) override { mySize = size; };
		int getSize() const override { return mySize; };

		void setColor(const Color& color) override { myColor = color; };
		Color getColor() const override { return myColor; };
				
		BitmapGraphics::HPen createPen() override
		{			
			HPen pen = std::make_shared<RoundPen>(mySize, myColor);
			return pen;
		};

	private:			
		int mySize;
		Color myColor;	
	};
}