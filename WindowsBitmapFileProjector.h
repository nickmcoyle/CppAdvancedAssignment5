#pragma once

#include "IProjector.h"
#include "CodecLibrary.h"
#include "ICanvas.h"
#include <list>
#include <string>

namespace BitmapGraphics
{
    class WindowsBitmapFileProjector : public IProjector
    {
   
    public:               
		WindowsBitmapFileProjector() = default;     

		WindowsBitmapFileProjector(std::string fileName, CodecLibrary codecLibrary);

		WindowsBitmapFileProjector(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&&) = default;

		~WindowsBitmapFileProjector() = default;

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&&) = default;       

		void projectCanvas(const HCanvas& canvas) override;       
        
    private:
		CodecLibrary& myCodecLibrary;
		std::string myFileName;
    };   
}
