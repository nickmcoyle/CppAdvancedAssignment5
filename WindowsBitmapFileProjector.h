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

		WindowsBitmapFileProjector(const std::string& fileName, const CodecLibrary& codecLibrary);

		WindowsBitmapFileProjector(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&&) = default;		

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&&) = default;       

		~WindowsBitmapFileProjector() = default;

		void projectCanvas(const HCanvas& canvas) override;       
        
    private:		
		std::string myFileName;
		CodecLibrary myCodecLibrary;
    };   
}
