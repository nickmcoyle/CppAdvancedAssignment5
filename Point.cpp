#include "Point.h"
#include <iostream>

namespace VG
{

	std::ostream& operator<<(std::ostream& os, const Point& p)
	{
		os << "(" << p.getX() << ", " << p.getY() << ")";
		return os;
	}

	bool Point::operator==(const Point& rhs)
	{
		return this->getX() == rhs.getX() && this->getY() == rhs.getY();
	}

	bool Point::operator!=(const Point& rhs)
	{
		return !(*this == rhs);
	}
	
	bool Point::operator<(const Point& rhs)
	{
		//return this->getX() < rhs.getX() && this->getY() < rhs.getY();
		return this->getX() + this->getY() < rhs.getX() + rhs.getY();
	}

	bool Point::operator>(const Point& rhs)
	{
		return !(*this < rhs);
	}

    bool operator==(const Point& lhs, const Point& rhs)
    {
        return rhs.getX() == lhs.getX() && rhs.getY() == lhs.getY();
    }
    
    bool operator!=(const Point& lhs, const Point& rhs)
    {
        return ! (lhs == rhs);
    }
    
	bool operator<(const Point& lhs, const Point& rhs)
	{
		//return rhs.getX() < lhs.getX() && rhs.getY() < lhs.getY();
		return rhs.getX() + rhs.getY() < lhs.getX() + lhs.getY();
	}

	bool operator>(const Point& lhs, const Point& rhs)
	{
		return ! (lhs < rhs);
	}

}
