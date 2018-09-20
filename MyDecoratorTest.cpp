#include "CodecLibrary.h"
#include "BasicCanvas.h"
#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "BitmapIteratorDecorator.h"
#include "GrayScaleConversionDecorator.h"
#include "PosterizeDecorator.h"
#include "TestHarness.h"
#include <memory>
#include <fstream>

using namespace BitmapGraphics;

TEST(grayScaleConversion, IteratorDecorator)
{
	std::ifstream bitmapStream{ "baboon_color.bmp", std::ios::binary };
	CHECK(bitmapStream.is_open());

	WindowsBitmapDecoder decoderPrototype{};
	HBitmapDecoder decoder{ decoderPrototype.clone(bitmapStream) };
	HBitmapIterator bitmapIter{ decoder->createIterator() };
		
	GrayScaleConversionDecorator grayScaleIter(bitmapIter);

	Bitmap decoratedBitmap (bitmapIter->getBitmapWidth(), bitmapIter->getBitmapHeight());
	Bitmap::ScanLine sl;

	while (!grayScaleIter.isEndOfImage())
	{
		
		while (!grayScaleIter.isEndOfScanLine())
		{
			sl.push_back(grayScaleIter.getColor());
			grayScaleIter.nextPixel();
		}

		decoratedBitmap.addScanLine(std::move(sl));
		grayScaleIter.nextScanLine();
	}
	
	auto newIter = decoratedBitmap.createIterator();

	std::ofstream outputStream{ "output_baboon_grayscale.bmp", std::ios::binary };
	CHECK(outputStream.is_open());

	WindowsBitmapEncoder encoderPrototype{};
	HBitmapEncoder encoder{ encoderPrototype.clone(newIter) };

	encoder->encodeToStream(outputStream);
	outputStream.close();
}

TEST(Posterize, IteratorDecorator)
{
	std::ifstream bitmapStream{ "obama.bmp", std::ios::binary };
	CHECK(bitmapStream.is_open());

	WindowsBitmapDecoder decoderPrototype{};
	HBitmapDecoder decoder{ decoderPrototype.clone(bitmapStream) };
	HBitmapIterator bitmapIter{ decoder->createIterator() };

	PosterizeDecorator grayScaleIter(bitmapIter);

	Bitmap decoratedBitmap(bitmapIter->getBitmapWidth(), bitmapIter->getBitmapHeight());
	Bitmap::ScanLine sl;

	while (!grayScaleIter.isEndOfImage())
	{

		while (!grayScaleIter.isEndOfScanLine())
		{
			sl.push_back(grayScaleIter.getColor());
			grayScaleIter.nextPixel();
		}

		decoratedBitmap.addScanLine(std::move(sl));
		grayScaleIter.nextScanLine();
	}

	auto newIter = decoratedBitmap.createIterator();

	std::ofstream outputStream{ "output_obama_posterized.bmp", std::ios::binary };
	CHECK(outputStream.is_open());

	WindowsBitmapEncoder encoderPrototype{};
	HBitmapEncoder encoder{ encoderPrototype.clone(newIter) };

	encoder->encodeToStream(outputStream);
	outputStream.close();
}