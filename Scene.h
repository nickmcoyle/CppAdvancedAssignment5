#pragma once

#include "Layer.h"
#include <list>

namespace Framework
{
    class Scene
    {
    private:
        using LayerCollection = std::list<Layer>;
        
    public:
        Scene(const int& width, const int& height);

		Scene(const Scene&) = default;
		Scene(Scene&& other) = default;

		Scene& operator=(const Scene&) = default;
		Scene& operator=(Scene&&) = default;
        
		void draw(const BitmapGraphics::HCanvas& canvas) const;

        using LayerIterator = LayerCollection::const_iterator;

        void pushBack(const Layer& layer);
        void remove(const Layer& layer);
        LayerIterator begin() const;
        LayerIterator end() const;
        
        int getWidth() const;
        int getHeight() const;
        
    private:
        LayerCollection myLayers;
        int myWidth;
        int myHeight;
    };
}
