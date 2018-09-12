#pragma once

#include "IPen.h"
#include "Point.h"
#include "IStroke.h"
#include <memory>

namespace BitmapGraphics
{	
	class Pen : public IPen
	{
	public:
		Pen() = default;
		Pen(const HStroke& stroke, const HCanvas& canvas);

		virtual ~Pen() = default;

		Pen(const Pen &) = delete;
		Pen& operator =(Pen const&) = delete;
		Pen(Pen&&) = delete;
		Pen& operator=(Pen&&) = delete;

		void drawPoint(const VG::Point& point) override;

	private:
		HStroke myStroke;
		HCanvas myCanvas;
	};
}