# 381 main engine

class Engine(object):
    '''
    The root of the global manager tree
    '''

    def __init__(self):
        pass

    def init(self):
        import entityMgr
        self.entityMgr = entityMgr.EntityMgr(self)
        self.entityMgr.init()
        self.keepRunning = True;

        import gfxMgr
        self.gfxMgr = gfxMgr.GfxMgr(self)
        self.gfxMgr.init()

        import netMgr
        self.netMgr = netMgr.NetMgr(self)
        self.netMgr.init()

        import inputMgr
        self.inputMgr = inputMgr.InputMgr(self)
        self.inputMgr.init()

        import controlMgr
        self.controlMgr = controlMgr.ControlMgr(self)
        self.controlMgr.init()

        import gameMgr
        self.gameMgr = gameMgr.GameMgr(self)
        self.gameMgr.init()

        import selectionMgr
        self.selectionMgr = selectionMgr.SelectionMgr(self)
        self.selectionMgr.init()

        import collisionMgr
        self.collisionMgr = collisionMgr.CollisionMgr(self)
        self.collisionMgr.init()

        import inventoryMgr
        self.inventoryMgr = inventoryMgr.InventoryMgr(self)
        self.inventoryMgr.init()

        import cameraMgr
        self.cameraMgr = cameraMgr.CameraMgr(self)
        self.cameraMgr.init()

        import overlayMgr
        self.overlayMgr = overlayMgr.OverlayMgr(self)
        self.overlayMgr.init()

    def stop(self):
        self.gfxMgr.stop()
        self.inputMgr.stop()
        self.selectionMgr.stop()
        self.gameMgr.stop()
        self.controlMgr.stop()
        self.collisionMgr.stop()
        self.inventoryMgr.stop()
        self.cameraMgr.stop()
        self.overlayMgr.stop()
        self.keepRunning = False

    def run(self):
        import time
        import ogre.renderer.OGRE as ogre
        weu = ogre.WindowEventUtilities() # Needed for linux/mac
        weu.messagePump()                 # Needed for linux/mac

        self.oldTime = time.time()        
        self.runTime = 0
        while (self.keepRunning):
            now = time.time() # Change to time.clock() for windows
            dtime = now - self.oldTime
            dtime *= 2
            self.oldTime = now

            self.entityMgr.tick(dtime)
            self.gfxMgr.tick(dtime)
            self.netMgr.tick(dtime)
            self.inputMgr.tick(dtime)
            self.selectionMgr.tick(dtime)
            self.controlMgr.tick(dtime)
            self.collisionMgr.tick(dtime)
            self.inventoryMgr.tick(dtime)
            self.gameMgr.tick(dtime)
            self.cameraMgr.tick(dtime)
            self.overlayMgr.tick(dtime)
            
            self.runTime += dtime
        
            weu.messagePump()             # Needed for linux/mac
            time.sleep(0.001)

        print "381 Engine exiting..."
    
