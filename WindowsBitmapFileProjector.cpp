#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapCommon.h"
#include <fstream>

namespace BitmapGraphics
{		
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(const std::string& fileName, const CodecLibrary& codecLibrary) :
	myCodecLibrary(codecLibrary), 
	myFileName(fileName)
	{
	}

	void WindowsBitmapFileProjector::projectCanvas(const HCanvas& canvas)
	{
		std::ofstream outputStream{ myFileName, std::ios::binary };
		if (!outputStream.is_open())
		{
			throw std::runtime_error("Could not create filename" + myFileName);
		}
		
		auto bitmapIter = canvas->createBitmapIterator();
		
		auto encoder = myCodecLibrary.createEncoder(WindowsBitmapMimeType, bitmapIter);
		
		encoder->encodeToStream(outputStream);
		outputStream.close();
	}
	
}
