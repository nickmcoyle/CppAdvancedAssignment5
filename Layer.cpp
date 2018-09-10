#include "Layer.h"

namespace Framework
{
    
    Layer::Layer(const std::string& alias) :
    myAlias(alias)
    {
    }
    
	void Layer::draw(const BitmapGraphics::HCanvas& canvas)
	{
	}

    void Layer::remove(const PlacedGraphic& placedGraphic)
    {
		PlacedGraphicIterator it = myGraphics.begin();

		while (it != myGraphics.end())
		{
			if ((*it) == placedGraphic)
			{
				myGraphics.erase(it);
				return;
			}
			else
			{
				it++;
			}
		}
		throw std::invalid_argument("the placed graphic to remove does not appear in the layer.");
    }
    
    Layer::PlacedGraphicIterator Layer::begin() const
    {
        return myGraphics.begin();
    }
    
    Layer::PlacedGraphicIterator Layer::end() const
    {
        return myGraphics.end();
    }
    
    std::string Layer::getAlias() const
    {
        return myAlias;
    }
    
    bool Layer::operator==(const Layer& rhs) const
    {
        return (myAlias == rhs.myAlias) && (myGraphics == rhs.myGraphics);
    }
    
    bool Layer::operator!=(const Layer& rhs) const
    {
        return !operator==(rhs);
    }
    
}
