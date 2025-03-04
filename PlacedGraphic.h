#pragma once

#include "Point.h"
#include "VectorGraphic.h"

namespace Framework
{
    
    class PlacedGraphic
    {
    public:
        PlacedGraphic(const VG::Point& placement, const VG::HVectorGraphic graphic);
        
        PlacedGraphic();

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic & operator=(const PlacedGraphic&) = default;
		PlacedGraphic & operator=(PlacedGraphic&&) = default;			
        
		void draw(const BitmapGraphics::HCanvas& canvas) const;

        void setPlacementPoint(const VG::Point& placement);
		void setPlacementPoint(VG::Point&& placement);

        const VG::Point& getPlacementPoint() const;
        
        void setGraphic(const VG::HVectorGraphic graphic);
        const VG::HVectorGraphic getGraphic() const;		
        
    private:
        VG::Point myPlacementPoint;
        VG::HVectorGraphic myGraphic;
    };
    
    bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
    bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
}
