#include "Point.h"
#include <iostream>

namespace VG
{

	std::ostream& operator<<(std::ostream& os, const Point& p)
	{
		os << "(" << p.getX() << ", " << p.getY() << ")";
		return os;
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
		return std::make_pair(lhs.getY(), lhs.getX()) < std::make_pair(rhs.getY(), rhs.getX());
	}

	bool operator>(const Point& lhs, const Point& rhs)
	{
		return ! (lhs < rhs);
	}

	bool operator<=(const Point& lhs, const Point& rhs)
	{
		return (std::make_pair(lhs.getX(), lhs.getY()) < std::make_pair(rhs.getX(), rhs.getY()) || lhs == rhs);
	}

	bool operator>=(const Point& lhs, const Point& rhs)
	{
		return (std::make_pair(lhs.getX(), lhs.getY()) > std::make_pair(rhs.getX(), rhs.getY()) || lhs == rhs);
	}
}
