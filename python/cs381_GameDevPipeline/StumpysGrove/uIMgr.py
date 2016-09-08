class uiManager(OIS.KeyListener, OIS.MouseListener, OIS.JoyStickListener):
    def __init__(self, engine):

    def __init__(self, ent):
        # Setup a UI plane.
        self.uiPlane = ogre.Plane ((0, 0, 1), 0)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Interface', 'General', self.uiPlane,
                                     100, 600, 20, 20, True, 1, 5, 5, (1, 0, 0))
        uent = self.sceneManager.createEntity('UIEntity', 'Interface')
        self.uinode = self.gfxMgr.sceneManager.getRootSceneNode().createChildSceneNode ()
        self.uinode.attachObject (uent)
        uinode.setPosition(0, 300, -200)
        #ent.setMaterialName ('Examples/Chrome')
        
    def stop(self):
        pass
        
    def tick(self, dtime):
        #----------update scene node position and orientation-----------------------------------
        self.node.setPosition(self.ent.pos)
        self.node.resetOrientation()
        self.node.yaw(ogre.Radian(self.ent.heading))

