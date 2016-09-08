# Graphics manager
import ogre.renderer.OGRE as ogre
import math
import utils

# Manages graphics. Creates graphics, scene, scene nodes, renders scene
class GfxMgr:
    def __init__(self, engine):
        self.engine = engine
        pass

    def init(self):
        self.createRoot()
        self.defineResources()
        self.setupRenderSystem()
        self.createRenderWindow()
        self.initializeResourceGroups()
        self.setupScene()


    def tick(self, dtime):
#        self.camYawNode.position = (self.engine.gameMgr.stumpy.pos.x, self.engine.gameMgr.stumpy.pos.y, self.engine.gameMgr.stumpy.pos.z)
#        timeScaledRotation = self.engine.gameMgr.stumpy.turningRate * dtime
#        angleDiff = utils.diffAngle(self.engine.gameMgr.stumpy.desiredHeading, self.engine.gameMgr.stumpy.heading)
#        dheading = utils.clamp(angleDiff, -timeScaledRotation, timeScaledRotation)
#        self.camYawNode.yaw(dheading)
        self.root.renderOneFrame()
        #self.uinode.yaw(ogre.Degree(-90))

    # The Root constructor for the ogre
    def createRoot(self):
        self.root = ogre.Root()
 
    # Here the resources are read from the resources.cfg
    def defineResources(self):
        cf = ogre.ConfigFile()
        cf.load("resources.cfg")
 
        seci = cf.getSectionIterator()
        while seci.hasMoreElements():
            secName = seci.peekNextKey()
            settings = seci.getNext()
 
            for item in settings:
                typeName = item.key
                archName = item.value
                ogre.ResourceGroupManager.getSingleton().addResourceLocation(archName, typeName, secName)
 
    # Create and configure the rendering system (either DirectX or OpenGL) here
    def setupRenderSystem(self):
        if not self.root.restoreConfig() and not self.root.showConfigDialog():
            raise Exception("User canceled the config dialog -> Application.setupRenderSystem()")
 
 
    # Create the render window
    def createRenderWindow(self):
        self.root.initialise(True, "CS 381 Spring 2012 Engine Version 1.0")
 
    # Initialize the resources here (which were read from resources.cfg in defineResources()
    def initializeResourceGroups(self):
        ogre.TextureManager.getSingleton().setDefaultNumMipmaps(5)
        ogre.ResourceGroupManager.getSingleton().initialiseAllResourceGroups()

    # Now, create a scene here. Three things that MUST BE done are sceneManager, camera and
    # viewport initializations 
    def setupScene(self):
        self.sceneManager = self.root.createSceneManager(ogre.ST_GENERIC, "Default SceneManager")

        self.camera = self.sceneManager.createCamera("Camera")
        self.camera.nearClipDistance = 5

        self.viewPort = self.root.getAutoCreatedWindow().addViewport(self.camera)
        self.sceneManager.ambientLight = 1, 1, 1

        #Setup a title plane
        self.titlePlane = ogre.Plane((1, 0, 1), 2)
        meshManager = ogre.MeshManager.getSingleton()
        meshManager.createPlane('Title', 'General', self.titlePlane,
                                      750, 800, 20, 20, True, 1, 1, 1, (1, 0, 0))
        self.tent = self.sceneManager.createEntity('TitleEntity', 'Title')
        self.titlenode = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.titlenode.attachObject(self.tent)
        self.tent.setMaterialName('Examples/TitleScreen')
        self.titlenode.setPosition(0,250,0)
     
        #Setup an story plane
        self.sPlane = ogre.Plane((1, 0, 1), 1)
        meshManager = ogre.MeshManager.getSingleton()
        meshManager.createPlane('Story', 'General', self.sPlane,
                                      750, 800, 20, 20, True, 1, 1, 1, (1, 0, 0))
        self.stent = self.sceneManager.createEntity('StoryEntity', 'Story')
        self.stnode = self.sceneManager.getRootSceneNode().createChildSceneNode("stnode", (0,200,-10))
        self.stnode.attachObject(self.stent)
        self.stent.setMaterialName('Examples/StoryScreen')
        self.stnode.setPosition(0,250,0)

        #Setup an instruction plane
        self.inPlane = ogre.Plane((1, 0, 1), 0)
        meshManager = ogre.MeshManager.getSingleton()
        meshManager.createPlane('Instructions', 'General', self.inPlane,
                                      750, 800, 20, 20, True, 1, 1, 1, (1, 0, 0))
        self.ient = self.sceneManager.createEntity('InstructionEntity', 'Instructions')
        self.ientnode = self.sceneManager.getRootSceneNode().createChildSceneNode("ientnode", (0,200,-10))
        self.ientnode.attachObject(self.ient)
        self.ient.setMaterialName('Examples/InstructionsScreen')
        self.ientnode.setPosition(0,250,0)

        # Setup a ground plane.
        #plane = ogre.Plane ((0, 1, 0), -100)
        self.groundPlane = ogre.Plane ((0, 1, 0), 0)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Ground', 'General', self.groundPlane,
                                     12000, 12000, 20, 20, True, 1, 1, 1, (0, 0, 1))
        ent = self.sceneManager.createEntity('GroundEntity', 'Ground')
        self.sceneManager.getRootSceneNode().createChildSceneNode ().attachObject (ent)
        ent.setMaterialName ('Examples/GrassPatern')

        #setup tree plane shows up
        self.treePlane = ogre.Plane((0, 0, -1), -6000)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Trees', 'General', self.treePlane,
                                     1500, 12000, 20, 20, True, 1, 1, 1, (1, 0, 0))
        trent = self.sceneManager.createEntity('treesEntity', 'Trees')
        self.boundnode = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.boundnode.attachObject(trent)
        trent.setMaterialName ('Examples/treebox2')
        self.boundnode.setPosition(0,700,0)

 
        self.tree1Plane = ogre.Plane((0, 0, 1), -6000)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Trees1', 'General', self.tree1Plane,
                                     1500, 12000, 20, 20, True, 1, 1, 1, (1, 0, 0))
        trent1 = self.sceneManager.createEntity('trees1Entity', 'Trees1')
        self.bound1node = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.bound1node.attachObject(trent1)
        trent1.setMaterialName ('Examples/treebox')
        self.bound1node.setPosition(0,700,0)


        self.tree2Plane = ogre.Plane((1, 0, 0), -6000)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Trees2', 'General', self.tree2Plane,
                                     1500, 12000, 20, 20, True, 1, 1, 1, (0, 0, 1))
        trent2 = self.sceneManager.createEntity('trees2Entity', 'Trees2')
        self.boundnode2 = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.boundnode2.attachObject(trent2)
        trent2.setMaterialName ('Examples/treebox2')
        self.boundnode2.setPosition(0,700,0)

        self.tree3Plane = ogre.Plane((-1, 0, 0), -6000)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Trees3', 'General', self.tree3Plane,
                                     1500, 12000, 20, 20, True, 1, 1, 1, (0, 0, 1))
        trent3 = self.sceneManager.createEntity('trees3Entity', 'Trees3')
        self.boundnode3 = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.boundnode3.attachObject(trent3)
        trent3.setMaterialName ('Examples/treebox')
        self.boundnode3.setPosition(0,700,0)

        # Setup a UI plane.
        self.uiPlane = ogre.Plane ((0, 0, 1), 0)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Interface', 'General', self.uiPlane,
                                     750, 800, 20, 20, True, 1, 1, 1, (1, 0, 0))
        uent = self.sceneManager.createEntity('UIEntity', 'Interface')
        self.uinode = self.sceneManager.getRootSceneNode().createChildSceneNode()
        self.uinode.attachObject(uent)
        uent.setMaterialName ('Examples/InstructionsScreen')
        self.uinode.setPosition(0,2000,100)
        self.uinode.yaw(ogre.Degree(40))               

        # environmental stuff
        ent.castShadows = False
        self.sceneManager.setSkyBox (True, "Examples/CloudyNoonSkyBox", 5000, False)
        self.camYawNode = self.sceneManager.getRootSceneNode().createChildSceneNode('CamNode1',
                                                                    (0, 200, 500))

        #node.yaw(ogre.Degree(-45))
        self.camYawNode.yaw(ogre.Degree(0))
        self.camera.lookAt((0,0,0))
        self.camPitchNode = self.camYawNode.createChildSceneNode('PitchNode1')
        self.camPitchNode.attachObject(self.camera)
 
 
     # In the end, clean everything up (= delete)
    #def cleanUp(self):
    def stop(self):
        del self.root

