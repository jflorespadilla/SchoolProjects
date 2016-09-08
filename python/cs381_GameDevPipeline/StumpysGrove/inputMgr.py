# Input manager. Initialize and manage keyboard and mouse. Buffered and unbuffered input
import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS

import command
from vector import Vector3
import os


class InputMgr(OIS.KeyListener, OIS.MouseListener, OIS.JoyStickListener):
    def __init__(self, engine):
        self.engine = engine
        OIS.KeyListener.__init__(self)
        OIS.MouseListener.__init__(self)
        OIS.JoyStickListener.__init__(self)
        self.move = 250
        self.rotate = 0.03
        self.yawRot = 0.0
        self.pitchRot = 0.0
        self.transVector = ogre.Vector3(0, 0, 0)
        self.toggle = 0.1
        self.selectionRadius = 100
        self.leftCtrlDown = False
        self.lookedAtNums = False


    def init(self):
        self.creditsExist = False
        self.creditCounter = 0;

        windowHandle = 0
        renderWindow = self.engine.gfxMgr.root.getAutoCreatedWindow()
        windowHandle = renderWindow.getCustomAttributeUnsignedLong("WINDOW")
        paramList = [("WINDOW", str(windowHandle))]

        if os.name == "nt":
            t = [("w32_mouse","DISCL_FOREGROUND"), ("w32_mouse", "DISCL_NONEXCLUSIVE")]
        else:
            t = [("x11_mouse_grab", "false"), ("x11_mouse_hide", "false")]
            #t = [("x11_mouse_grab", "false"), ("x11_mouse_hide", "true")]

        paramList.extend(t)

        self.inputManager = OIS.createPythonInputSystem(paramList)
 
        # Now InputManager is initialized for use. Keyboard and Mouse objects
        # must still be initialized separately
        self.keyboard = None
        self.mouse    = None
        try:
            self.keyboard = self.inputManager.createInputObjectKeyboard(OIS.OISKeyboard, True)
            self.mouse = self.inputManager.createInputObjectMouse(OIS.OISMouse, True)
        except Exception, e:
            print "No Keyboard or mouse!!!!"
            raise e
        if self.keyboard:
            self.keyboard.setEventCallback(self)
        if self.mouse:
            self.mouse.setEventCallback(self)
 
        self.transVector = ogre.Vector3(0, 0, 0)
        import random
        self.randomizer = random
        self.randomizer.seed(None)
        print "Initialized Input Manager"
        self.crosslink()

    def crosslink(self):
        self.camera = self.engine.gfxMgr.camera
        self.camYawNode = self.engine.gfxMgr.camYawNode
        self.camPitchNode = self.engine.gfxMgr.camPitchNode

    def getNewCams(self):
        self.camera = self.engine.cameraMgr.camera
        self.camYawNode = self.engine.cameraMgr.camYawNode
        self.camPitchNode = self.engine.cameraMgr.camPitchNode

    #def releaseLevel(self):
    def stop(self):
        self.inputManager.destroyInputObjectKeyboard(self.keyboard)
        self.inputManager.destroyInputObjectMouse(self.mouse)
        OIS.InputManager.destroyInputSystem(self.inputManager)
        self.inputManager = None
        
    def tick(self, dtime):
        self.keyboard.capture()
        self.mouse.capture()

        self.keyPressed(dtime)
        
        self.getNewCams()

        #self.camNode.yaw(ogre.Degree(-self.yawRot)
        self.camYawNode.yaw(ogre.Radian(self.yawRot))
        self.camPitchNode.pitch(ogre.Radian(self.pitchRot))

        # Translate the camera based on time.
        self.camYawNode.translate(self.camYawNode.orientation
                               * self.transVector
                               * dtime)
        self.handleModifiers(dtime)
        self.handleCreateEnt(dtime)
        pass

    def handleModifiers(self, dtime):
        self.leftShiftDown = self.keyboard.isKeyDown(OIS.KC_LSHIFT)
        self.leftCtrlDown = self.keyboard.isKeyDown(OIS.KC_LCONTROL)
        pass

    def handleCreateEnt(self, dt):
        self.toggle = self.toggle - dt
        if self.keyboard.isKeyDown(OIS.KC_EQUALS) and self.toggle < 0.0:
            ent = self.engine.entityMgr.createEnt(self.randomizer.choice(self.engine.entityMgr.entTypes), pos = Vector3(0,0,0))
            self.toggle = 0.1

    def keyPressed(self, evt):
        # Move the camera using keyboard input.
        self.transVector = ogre.Vector3(0, 0, 0)
        self.yawRot = 0.0
        self.pitchRot = 0.0
        # Forward.
#        if self.keyboard.isKeyDown(OIS.KC_W):
#            self.transVector.z -= self.move
        # Backward.
#        if self.keyboard.isKeyDown(OIS.KC_S):
#            self.transVector.z += self.move
        # Left.
#        if self.keyboard.isKeyDown(OIS.KC_A):
#            self.transVector.x -= self.move
        # Right.
#        if  self.keyboard.isKeyDown(OIS.KC_D):
#            self.transVector.x += self.move
        # Up.        
        if self.keyboard.isKeyDown(OIS.KC_PGUP):
            self.transVector.y += self.move
        # Down.
        if self.keyboard.isKeyDown(OIS.KC_PGDOWN):
            self.transVector.y -= self.move          

        if self.keyboard.isKeyDown(OIS.KC_Q):
            self.yawRot = self.rotate

        if self.keyboard.isKeyDown(OIS.KC_E):
            self.yawRot = -self.rotate

        if self.keyboard.isKeyDown(OIS.KC_Z):
            self.pitchRot = self.rotate

        if self.keyboard.isKeyDown(OIS.KC_X):
            self.pitchRot = -self.rotate            
             
        if self.keyboard.isKeyDown(OIS.KC_TAB) and self.engine.controlMgr.pastMenu:
            if self.lookedAtNums == False:
                self.lookedAtNums = True
                self.camYawNode = self.engine.gfxMgr.camYawNode
                self.camPitchNode = self.engine.gfxMgr.camPitchNode

                self.camera.parentSceneNode.detachObject(self.camera)
                self.camPitchNode.attachObject(self.camera)
                self.camYawNode.setPosition(0,2000,0)
                self.camPitchNode.setPosition(800,0,800)
                self.camera.lookAt((0,2000,100))


        if not(self.keyboard.isKeyDown(OIS.KC_TAB)) and self.lookedAtNums:
           self.lookedAtNums = False
           self.camYawNode.resetOrientation()
           self.camPitchNode.resetOrientation()
           self.camera = self.engine.cameraMgr.camera
           self.camYawNode = self.engine.cameraMgr.camYawNode
           self.camera.parentSceneNode.detachObject(self.camera)
           self.camPitchNode.attachObject(self.camera)
           self.camYawNode.yaw(ogre.Degree(-135))                

        if self.keyboard.isKeyDown(OIS.KC_ESCAPE) and self.creditCounter < 5 and self.engine.controlMgr.pastMenu:
             self.creditCounter+=1;
             if self.creditsExist == False:
                 self.creditPlane = ogre.Plane((0, 0, 1), 0)
                 meshManager = ogre.MeshManager.getSingleton()
                 meshManager.createPlane('Credits', 'General', self.creditPlane,
                                      750, 800, 20, 20, True, 1, 1, 1, (1, 0, 0))
                 self.cent = self.engine.gfxMgr.sceneManager.createEntity('CreditsEntity', 'Credits')
                 self.credNode = self.engine.gfxMgr.sceneManager.getRootSceneNode().createChildSceneNode()
                 self.credNode.attachObject(self.cent)
                 self.credNode.setPosition(0,400,0)
                 self.cent.setMaterialName('Examples/Credits')
                 self.creditsExist = True;
 
                 self.camYawNode = self.engine.gfxMgr.camYawNode
                 self.camPitchNode = self.engine.gfxMgr.camPitchNode

                 self.camera.parentSceneNode.detachObject(self.camera)
                 self.camPitchNode.attachObject(self.camera)
                 self.camYawNode.setPosition(0,400,0)
                 self.camPitchNode.setPosition(800,0,800)
                 self.camera.lookAt((0,400,-10))
                 self.camYawNode.yaw(ogre.Degree(-35)) 

        if self.keyboard.isKeyDown(OIS.KC_ESCAPE) and self.creditCounter >= 5:
                self.engine.stop()

        return True

    def keyReleased(self, evt):
        return True
    
       # MouseListener
    def mouseMoved(self, evt):
        return True

    def mousePressed(self, evt, id):
        self.handleMouseSelection(evt,id)
        return True


    def handleMouseSelection(self, evt,id):
        self.mouse.capture()
        self.ms = self.mouse.getMouseState()
        print str(self.ms)

        self.ms.width = self.engine.gfxMgr.viewPort.actualWidth 
        self.ms.height = self.engine.gfxMgr.viewPort.actualHeight
        self.mousePos = (self.ms.X.abs/float(self.ms.width), self.ms.Y.abs/float(self.ms.height))
        mouseRay = self.engine.gfxMgr.camera.getCameraToViewportRay(*self.mousePos)
        result  =  mouseRay.intersects(self.engine.gfxMgr.groundPlane)

        if result.first:
            pos =  mouseRay.getPoint(result.second)
            self.mousePosWorld = pos

            closest = None
            closestDistance = self.selectionRadius * self.selectionRadius
            for ent in self.engine.entityMgr.ents.values():
                distSquared =  ent.pos.squaredDistance(pos)
                if distSquared < closestDistance:
                    closest = ent
                    closestDistance = distSquared

            # if the left mouse button is pressed							
            if id == OIS.MB_Left:
                if closest: # One level deep
                    if self.leftShiftDown:
                        self.engine.selectionMgr.addSelectedEnt(closest)
                    else:
                        self.engine.selectionMgr.selectedEnt(closest)


            # if right mouse button is pressed
            elif id == OIS.MB_Right:
                self.selectedEnt = self.engine.gameMgr.stumpy
                #if control and right mouse pressed intercept target
                if closest:
                    if self.leftCtrlDown:
                        ent.aspects[2].setCommand(command.intercept, closest)
                        # if pressed over an entity
                    else:
                        ent.aspects[2].setCommand(command.follow, closest)
                    # if just right mouse pressed over nothing move
                else:
                    ent.aspects[2].setCommand(command.move, pos)


    def mouseReleased(self, evt, id):
        return True
    
       # JoystickListener
    def buttonPressed(self, evt, button):
        return True
    def buttonReleased(self, evt, button):
        return True
    def axisMoved(self, evt, axis):
        return True

#---------------------------------------------------------------------------------------------------


    # def handleCameraMovement(self, dtime):

    #     #print "handling camera"w

    #     # Move the camera using keyboard input.
    #     transVector = ogre.Vector3 (0, 0, 0)
    #     # Move Forward.
    #     if self.keyboard.isKeyDown(OIS.KC_W):
    #        transVector.z -= self.move
    #     # Move Backward.
    #     if self.keyboard.isKeyDown(OIS.KC_S):
    #         transVector.z += self.move
    #     # Strafe Left.
    #     if self.keyboard.isKeyDown(OIS.KC_A):
    #         transVector.x -= self.move
    #     # Strafe Right.
    #     if  self.keyboard.isKeyDown(OIS.KC_D):
    #        transVector.x += self.move
    #     # Move Up.        
    #     if self.keyboard.isKeyDown(OIS.KC_PGUP):
    #         transVector.y += self.move
    #     # Move Down.
    #     if self.keyboard.isKeyDown(OIS.KC_PGDOWN):
    #         transVector.y -= self.move
    #     # Translate the camera based on time.
    #     self.camYawNode.translate(self.camYawNode.orientation
    #                               * transVector
    #                               * dtime)

    #     # Pitch Up.        
    #     if self.keyboard.isKeyDown(OIS.KC_Z):
    #         self.camPitchNode.pitch(ogre.Radian(0.3 * dtime))
    #     # Pitch Down.
    #     if self.keyboard.isKeyDown(OIS.KC_X):
    #         self.camPitchNode.pitch(ogre.Radian(-0.3 * dtime))

    #     # Pitch Up.        
    #     if self.keyboard.isKeyDown(OIS.KC_Q):
    #         self.camYawNode.yaw(ogre.Radian(0.3 * dtime))
    #     # Pitch Down.
    #     if self.keyboard.isKeyDown(OIS.KC_E):
    #         self.camYawNode.yaw(ogre.Radian(-0.3 * dtime))



    # def handleQuit(self, dtime):

    #     if (self.keyboard.isKeyDown(OIS.KC_ESCAPE)):
    #         self.engine.stop()

    
        
        


