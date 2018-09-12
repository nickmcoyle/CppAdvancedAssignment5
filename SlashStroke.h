#pragma once

#include "Stroke.h"
#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class SlashStroke : public Stroke
	{
	public:
		SlashStroke(const std::string& tip, int size, const Color& color) : myTip(tip), mySize(size), myColor(color) {};

		SlashStroke(const SlashStroke& other) = default;
		SlashStroke(SlashStroke&& other) = default;

		SlashStroke& operator=(const SlashStroke&) = default;
		SlashStroke& operator=(SlashStroke&&) = default;

	private:
		std::string myTip;
		int mySize;
		Color myColor;
	};
}