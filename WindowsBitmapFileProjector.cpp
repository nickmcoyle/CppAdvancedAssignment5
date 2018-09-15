#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapCommon.h"
#include "BitmapIteratorStack.h"
#include <fstream>
#include <memory>

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
		Bitmap bitmap(canvas->getHeight(), canvas->getWidth());
		HBitmapIterator bitmapIterStack = std::make_shared<BitmapIteratorStack>(bitmap, bitmapIter);		

		auto encoder = myCodecLibrary.createEncoder(WindowsBitmapMimeType, bitmapIterStack);
		
		encoder->encodeToStream(outputStream);
		outputStream.close();
	}
	
}
