#include "VectorGraphic.h"
#include <algorithm>

namespace VG
{
    VectorGraphic::VectorGraphic() :
    myShapeStyle{ShapeStyle::Closed}
    {
    }

	void VectorGraphic::draw(const Point& upperLeftOrigin, const BitmapGraphics::HCanvas& canvas)
	{		

		auto pen = myStroke->createPen();

		std::vector<VG::Point>::const_iterator pathIter;

		for (pathIter = myPath.begin(); pathIter != --myPath.end(); ++pathIter)
		{
			auto peek = (pathIter + 1);
			Point beginPoint( (pathIter->getX() + upperLeftOrigin.getX()), (pathIter->getY() + upperLeftOrigin.getY()));				
			Point endPoint((peek->getX() + upperLeftOrigin.getX()), (peek->getY() + upperLeftOrigin.getY()));			
			
			pen->drawPoint(beginPoint, canvas);
			pen->drawPoint(endPoint, canvas);
			
			pen->drawLine(beginPoint, endPoint, canvas);

			if (peek == --myPath.end() && this->isClosed())
			{
				Point beginPoint((peek->getX() + upperLeftOrigin.getX()), (peek->getY() + upperLeftOrigin.getY()));
				Point endPoint((myPath.begin()->getX() + upperLeftOrigin.getX()), (myPath.begin()->getY() + upperLeftOrigin.getY()));
				pen->drawLine(beginPoint, endPoint, canvas);
			}						
		}

	}
    
    bool VectorGraphic::isOpen() const
    {
        return myShapeStyle == ShapeStyle::Open;
    }
    
    bool VectorGraphic::isClosed() const
    {
        return myShapeStyle == ShapeStyle::Closed;
    }
    
    void VectorGraphic::openShape()
    {
        myShapeStyle = ShapeStyle::Open;
    }
    
    void VectorGraphic::closeShape()
    {
        myShapeStyle = ShapeStyle::Closed;
    }
    
    int VectorGraphic::getWidth() const
    {
		// returns iterators to the min and max element as a std::pair
		// uses the structured binding to make the access a little more clean
		auto [minIt, maxIt] =std::minmax_element(myPath.cbegin(), myPath.cend(),
			[](Point const& lhs, Point const& rhs) {return lhs.getX() < rhs.getX();  });        
        
        return myPath.size() > 0 ? maxIt->getX() - minIt->getX() : 0;
    }
    
    int VectorGraphic::getHeight() const
    {
		auto[minIt, maxIt] = std::minmax_element(myPath.cbegin(), myPath.cend(),
			[](Point const& lhs, Point const& rhs) {return lhs.getY() < rhs.getY();  });
        
		return myPath.size() > 0 ? maxIt->getY() - minIt->getY() : 0;
    }
    
    size_t VectorGraphic::getPointCount() const
    {
        return myPath.size();
    }

    const Point& VectorGraphic::getPoint(int index) const
    {	
        return myPath.at(index); // throws std::out_of_range if index out of range
    }
    
    void VectorGraphic::removePoint(const Point& p)
    {
		auto newEnd = std::remove(myPath.begin(), myPath.end(), p);

		if (newEnd == myPath.end())
		{
			throw std::invalid_argument("the point to remove does not appear in the vectorgraphic.");
		}

        myPath.erase(newEnd, myPath.end());
    }
    
    void VectorGraphic::erasePoint(int index)
    {
        if (index >= 0 && static_cast<std::size_t>(index) < myPath.size())
        {
            auto pos = myPath.begin() + index;
            myPath.erase(pos);
        }
        else
        {
            throw std::out_of_range{"index out of range"};
        }
    }
    
    bool VectorGraphic::operator==(const VectorGraphic& rhs) const
    {
        return (myPath == rhs.myPath) && (myShapeStyle == rhs.myShapeStyle);
    }
    
    bool VectorGraphic::operator!=(const VectorGraphic& rhs) const
    {
        return ! (*this == rhs);
    }	
	
	std::ostream& operator<<(std::ostream& os, const VectorGraphic& vectorGraphic)
	{
		os << vectorGraphic.getWidth() << vectorGraphic.getHeight();
		//vectorGraphic.write(os);
		return os;
	}
}
