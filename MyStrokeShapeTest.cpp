#include "CodecLibrary.h"
#include "XmlReader.h"
#include "XmlFactories.h"
#include "Element.h"
#include "Scene.h"
#include "SceneReader.h"
#include "BasicCanvas.h"
#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "TestHarness.h"
#include <memory>

const std::string SceneXml = R"(
<Scene width="800" height="800">
  <Layer alias="bottom">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Stroke tip="slash" size="7" color="FF0000" />
        <Point x="100" y="500" />
        <Point x="100" y="100" />
        <Point x="500" y="600" />
       </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="400" y="300">
      <VectorGraphic closed="true">
        <Stroke tip="square" size="9" color="00FF00" />
        <Point x="0" y="0" />
        <Point x="0" y="100" />
        <Point x="100" y="100" />
        <Point x="100" y="0" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="top">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Stroke tip="square" size="20" color="0000FF" />
        <Point x="0" y="0" />
        <Point x="0" y="100" />
        <Point x="100" y="100" />
        <Point x="100" y="0" />
      </VectorGraphic>
    </PlacedGraphic>
	<PlacedGraphic x="550" y="250">
      <VectorGraphic closed="false">
        <Stroke tip="round" size="12" color="AA0000" />
        <Point x="0" y="0" />
        <Point x="0" y="100" />
        <Point x="100" y="100" />
        <Point x="100" y="0" />
      </VectorGraphic>
    </PlacedGraphic>
	<PlacedGraphic x="600" y="600">
      <VectorGraphic closed="false">
        <Stroke tip="round" size="9" color="AA0000" />
        <Point x="0" y="0" /> 
		<Point x="0" y="100" />      
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";

const std::string MissingStrokeSceneXml = R"(
<Scene width="800" height="800">
  <Layer alias="bottom">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">       
        <Point x="100" y="500" />
        <Point x="100" y="100" />
        <Point x="500" y="600" />
       </VectorGraphic>
    </PlacedGraphic>    
  </Layer>
 </Scene>)";

const std::string UnsupportedStrokeSceneXml = R"(
<Scene width="800" height="800">
  <Layer alias="bottom">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true"> 
		<Stroke tip="soft" size="9" color="AA0000" />      
        <Point x="100" y="500" />
        <Point x="100" y="100" />
        <Point x="500" y="600" />
       </VectorGraphic>
    </PlacedGraphic>    
  </Layer>
 </Scene>)";


using namespace BitmapGraphics;

namespace
{
    class CodecLibrarySetup
    {
    public:
        CodecLibrarySetup()
        {
            myCodecLibrary.registerEncoder(std::make_unique<WindowsBitmapEncoder>());
            myCodecLibrary.registerDecoder(std::make_unique<WindowsBitmapDecoder>());
        }
        
        operator CodecLibrary&()
        {
            return myCodecLibrary;
        }
        
	private:
		CodecLibrary myCodecLibrary;
    
    };
}

TEST(toBitmapRoundStroke, SceneReader)
{
    std::stringstream xmlStream(SceneXml);
    
    // Parse the XML into a DOM    
	Xml::HElement root = Xml::ReaderFactory::getReader().loadXml(xmlStream);

    // Construct a vector graphic Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*root);
    
    // Create an empty Canvas
    Color backgroundColor(100, 100, 100);
    HCanvas canvas = std::make_shared<BasicCanvas>(scene.getWidth(), scene.getHeight(), backgroundColor);
    
    // Draw the Scene onto the Canvas
    scene.draw(canvas);
	
    // Create a WindowsBitmapFileProjector and give it an output file name to create
    // Also give it the CodecLibrary ("dependency injection").
    CodecLibrarySetup codecLibrary;
	
    HProjector projector = std::make_shared<WindowsBitmapFileProjector>("output_sceneMyTest.bmp", codecLibrary);
	
    // Project the Canvas into the bitmap file
   projector->projectCanvas(canvas);
   
}

TEST(MissingStroke, SceneReader)
{
	std::stringstream xmlStream(MissingStrokeSceneXml);

	// Parse the XML into a DOM    
	Xml::HElement root = Xml::ReaderFactory::getReader().loadXml(xmlStream); 
	
	// Construct a vector graphic Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*root); //should throw missing stroke

}

TEST(UnsupportedStroke, SceneReader)
{
	std::stringstream xmlStream(UnsupportedStrokeSceneXml);

	// Parse the XML into a DOM    
	Xml::HElement root = Xml::ReaderFactory::getReader().loadXml(xmlStream); 
	
	// Construct a vector graphic Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*root); //should throw unsupported stroke

}