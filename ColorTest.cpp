#include "Color.h"
#include "TestHarness.h"

using namespace BitmapGraphics;

TEST(toColor, Color)
{
	std::string hexColor = "0000FF";	
	Color expected(00, 00, 255);
	
	Color actual = Color::toColor(hexColor);
	
	CHECK_EQUAL(actual, expected);

	std::string hexColor2 = "FF0000";
	Color expected2(255, 00, 00);

	Color actual2 = Color::toColor(hexColor2);

	CHECK_EQUAL(actual2, expected2);

	std::string hexColor3 = "00FF00";
	Color expected3(00, 255, 00);

	Color actual3 = Color::toColor(hexColor3);

	CHECK_EQUAL(actual3, expected3);


	std::string hexColor4 = "FFD700";
	Color expected4(255, 215, 00);

	Color actual4 = Color::toColor(hexColor4);

	CHECK_EQUAL(actual4, expected4);


	std::string hexColor5 = "D8F7A0";
	Color expected5(216, 247, 160);

	Color actual5 = Color::toColor(hexColor5);

	CHECK_EQUAL(actual5, expected5);

}