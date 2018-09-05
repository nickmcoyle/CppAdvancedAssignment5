#pragma once

#include "IStroke.h"

namespace BitmapGraphics
{
	class SquareStroke : public IStroke
	{
	public:
		SquareStroke();

		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;

	private:
		//Tip tip; //create a tip library?
		int size;
		Color color;
	};
}