#pragma once

#include "Byte.h"
#include <string>
#include <sstream>

namespace BitmapGraphics
{
    class Color
    {
    public:
        explicit Color(
            const Binary::Byte& red = 0_byte,
            const Binary::Byte& green = 0_byte,
            const Binary::Byte& blue = 0_byte) noexcept;

		Color(int red, int green, int blue) noexcept;
		
		Color(const Color&) noexcept = default;
		Color(Color &&) noexcept = default;

		Color& operator=(const Color&) = default;
		Color& operator=(Color&&) = default;

		~Color() noexcept = default;

        static Color read(std::istream& sourceStream);
        void write(std::ostream& destinationStream) const;
			
		static Color toColor(const std::string& hexColor)
		{
			auto R = strtol(hexColor.substr(0,2).c_str(), 0, 16);
			auto G = strtol(hexColor.substr(2, 2).c_str(), 0, 16);
			auto B = strtol(hexColor.substr(4, 2).c_str(), 0, 16);
		
			return Color(R, G, B);			
		}

        Binary::Byte getRed() const { return myRed; }
        Binary::Byte getGreen() const { return myGreen; }
        Binary::Byte getBlue() const { return myBlue; }

        bool operator==(const Color& rhs) const;

    private:
        Binary::Byte myRed;
        Binary::Byte myGreen;
        Binary::Byte myBlue;
    };

    std::ostream& operator<<(std::ostream& os, const Color& color);
}
