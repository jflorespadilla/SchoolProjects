import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS

class OverlayMgr:
    def __init__(self, engine):
        self.engine = engine

    def init(self):
        self.overlayManager = ogre.OverlayManager.getSingleton() 
        self.shipInfoOverlay = self.overlayManager.getByName("Example/WaterOverlay")
        self.shipInfoOverlay.show()

    
        self.overlayContainer = self.overlayManager.createOverlayElement("Panel", "ECSLENT/ShipInfoPanel")
        self.overlayContainer.setMetricsMode(ogre.GMM_PIXELS)
        self.overlayContainer.setPosition(10, 10)
        self.overlayContainer.setDimensions(500, 100)

        self.textArea1 = self.overlayManager.createOverlayElement("TextArea", "ECSLENT/testArea")
        self.textArea1.setMetricsMode(ogre.GMM_PIXELS)
        self.textArea1.setCaption("seed1")
        self.textArea1.setPosition(5, 5)
        self.textArea1.setDimensions(500, 20)
        self.textArea1.setFontName("BlueHighway")
        self.textArea1.setCharHeight(20)
        self.textArea1.setColourTop((1.0, 1.0, 0.7))
        self.textArea1.setColourBottom((1.0, 1.0, 0.7))
        self.overlayContainer.addChild(self.textArea1)
        self.textArea1.show()
        self.shipInfoOverlay.add2D(self.overlayContainer)
        self.overlayContainer.show()

    def tick(self, dt):
        self.textArea1.caption = "Blue Seed: " + str(self.engine.inventoryMgr.seed1) + "   Pink Seed: " + str(self.engine.inventoryMgr.seed2) + '\n' + "Purple Seed: " + str(self.engine.inventoryMgr.seed3) + " Yellow Seed: " + str(self.engine.inventoryMgr.seed4) + "\n" + "Happiness: " + str(self.engine.inventoryMgr.happiness)

    def stop(self):
        pass
