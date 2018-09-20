#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapCommon.h"
#include <fstream>
#include <memory>
#include <stack>

namespace
{
	using namespace BitmapGraphics;

	HBitmap flipIt(const HCanvas& canvas)
	{
		HBitmapIterator canvasIterator = canvas->createBitmapIterator();

		std::stack<Bitmap::ScanLine> myStack;

		while (!canvasIterator->isEndOfImage())
		{
			Bitmap::ScanLine scanLine;

			while (!canvasIterator->isEndOfScanLine())
			{
				scanLine.push_back(canvasIterator->getColor());
				canvasIterator->nextPixel();
			}

			myStack.push(scanLine);
			canvasIterator->nextScanLine();
		}

		HBitmap flippedBitmap = std::make_unique<Bitmap>(canvasIterator->getBitmapWidth(), canvasIterator->getBitmapHeight());

		while (!myStack.empty())
		{
			flippedBitmap->addScanLine(myStack.top());
			myStack.pop();
		}

		return flippedBitmap;
	}

}

namespace BitmapGraphics
{		
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(const std::string& fileName, const CodecLibrary& codecLibrary) :
	myFileName(fileName),
	myCodecLibrary(codecLibrary)
	{
	}

	void WindowsBitmapFileProjector::projectCanvas(const HCanvas& canvas)
	{
		HBitmap flippedBitmap = flipIt(canvas);
		auto iter = flippedBitmap->createIterator();
		HBitmapEncoder encoder = myCodecLibrary.createEncoder(WindowsBitmapMimeType, iter);
		std::ofstream outputStream{ myFileName, std::ios::binary };
		if (!outputStream.is_open())
		{
			throw std::runtime_error("Could not create filename" + myFileName);
		}	
		
		encoder->encodeToStream(outputStream);
		outputStream.close();
	}
	
}
