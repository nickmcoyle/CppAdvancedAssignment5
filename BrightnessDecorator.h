#pragma once

#include "BitmapIteratorDecorator.h"
#include "Byte.h"

namespace BitmapGraphics
{
	class BrightnessDecorator : public BitmapIteratorDecorator
	{
	public:
		BrightnessDecorator(HBitmapIterator originalIterator, const int& brightnessAdjustment);

		BrightnessDecorator(const BrightnessDecorator& other) = default;
		BrightnessDecorator(BrightnessDecorator&& other) = default;

		BrightnessDecorator& operator=(const BrightnessDecorator&) = default;
		BrightnessDecorator& operator=(BrightnessDecorator&&) = default;
		
		void setBrightnessAdjustment(int brightnessAdjustment);
        int getBrightnessAdjustment() const;

	    Color getColor() const override;

	private:
		int myBrightnessAdjustment;
	};
}