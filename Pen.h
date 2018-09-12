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
		Pen(HStroke stroke);

		virtual ~Pen() = default;

		Pen(const Pen &) = delete;
		Pen& operator =(Pen const&) = delete;
		Pen(Pen&&) = delete;
		Pen& operator=(Pen&&) = delete;

		void drawPoint(VG::Point const& point) override;

	private:
		HStroke myStroke;
	};
}