#pragma once

#include "Color.h"
#include "ICanvas.h"
#include "IPen.h"
#include <memory>

namespace BitmapGraphics
{    
    class IStroke
    {
    public:
		IStroke() = default;
		virtual ~IStroke() = default;

		IStroke(const IStroke &) = delete;
		IStroke& operator =(IStroke const&) = delete;
		IStroke(IStroke&&) = delete;
		IStroke& operator=(IStroke&&) = delete;		
		
		virtual void setSize(int size) = 0;
		virtual int getSize() const = 0;

		virtual void setColor(const Color& color) = 0;
		virtual Color getColor() const = 0;

		virtual std::string getTip() const = 0;

		virtual BitmapGraphics::HPen createPen(const BitmapGraphics::HCanvas& canvas) = 0;
    };

	using HStroke = std::shared_ptr<IStroke>;
}