import ogre.renderer.OGRE as ogre

class CameraMgr:
    def __init__(self, engine):
        self.engine = engine
        #print "starting Game mgr"
        pass

    def init(self):
        self.camera = self.engine.gfxMgr.camera
        self.camYawNode = self.engine.gameMgr.stumpy.aspects[1].node.createChildSceneNode("camYawNode", (0,800,0))
        self.camPitchNode = self.camYawNode.createChildSceneNode("camPitchNode", (2000, 0, 2000))
        self.camera.parentSceneNode.detachObject(self.camera)
        self.camPitchNode.attachObject(self.camera)
        self.camYawNode.resetOrientation()
        self.camPitchNode.resetOrientation()
        self.camPitchNode.lookAt(ogre.Vector3(0, 0, 0), ogre.Node.TS_PARENT)
        self.camYawNode.yaw(ogre.Degree(-135))

    def tick(self, dt):
        pass

    def stop(self):
        pass
