#include "TestHarness.h"

#include "CodecLibrary.h"
#include "BrightnessDecorator.h"
#include "ColorInversionDecorator.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "BitmapIterator.h"
#include <fstream>
#include <memory>
#include <iostream>

using namespace BitmapGraphics;

namespace
{
    const std::string msBmp{"image/x-ms-bmp"};
    
    std::shared_ptr<CodecLibrary> theCodecLibrary;

    void setUp()
    {
        theCodecLibrary.reset(new CodecLibrary);
        theCodecLibrary->registerEncoder(std::make_unique<WindowsBitmapEncoder>());
        theCodecLibrary->registerDecoder(std::make_unique<WindowsBitmapDecoder>());
    }

    void tearDown()
    {
        theCodecLibrary.reset();
    }
}

TEST(invalidDecoder, CodecLibrary)
{
    HBitmapDecoder decoder = std::make_unique<WindowsBitmapDecoder>();

    try
    {
        decoder->createIterator();
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(invalidEncoder, CodecLibrary)
{
    HBitmapEncoder encoder = std::make_unique<WindowsBitmapEncoder>();

    try
    {
        std::ostringstream os{std::ios::binary};
        encoder->encodeToStream(os);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(createEncoderViaMimeType, CodecLibrary)
{
    setUp();
    
    Bitmap nullBitmap{0, 0};
    HBitmapIterator iterator {nullBitmap.createIterator()};
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, iterator)};

    CHECK(dynamic_cast<WindowsBitmapEncoder*>(encoder.get()));

    tearDown();
}

TEST(failedCreateEncoderViaMimeType, CodecLibrary)
{
    setUp();
    
    Bitmap nullBitmap{0, 0};
    HBitmapIterator iterator {nullBitmap.createIterator()};
    
    try
    {
        HBitmapEncoder encoder {theCodecLibrary->createEncoder("image/unsupported-type", iterator)};
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
    
    tearDown();
}

TEST(createDecoderViaMimeType, CodecLibrary)
{
    setUp();

    std::stringstream ss;
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(msBmp, ss)};

    CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

    tearDown();
}

TEST(createFailedDecoderViaMimeType, CodecLibrary)
{
    setUp();
    
    std::stringstream ss;
    
    try
    {
        HBitmapDecoder decoder {theCodecLibrary->createDecoder("image/unsupported-type", ss)};
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }

    tearDown();
}

TEST(createDecoderAutoDetermine, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};

    CHECK(decoder.get());
    CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

    tearDown();
}

TEST(windowsBitmapDecodeEncode, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, iterator)};

    std::ofstream outFile{"output_basicCopy.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(brightnessDecoratorIterator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator brightnessIterator = std::make_unique<BrightnessDecorator>(iterator, 80);
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, brightnessIterator)};

    std::ofstream outFile{"output_basicBrightnessAdjusted.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(colorInvertDecoratorIterator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator colorInvertIterator = std::make_unique<ColorInversionDecorator>(iterator);
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, colorInvertIterator)};

    std::ofstream outFile{"output_basicColorInvert.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(doubleDecorator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator colorInvertIterator = std::make_unique<ColorInversionDecorator>(iterator);
    HBitmapIterator darkenColorInvertIterator = std::make_unique<BrightnessDecorator>(colorInvertIterator, -50);

    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, darkenColorInvertIterator)};
        
    std::ofstream outFile{"output_darkInverted.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}