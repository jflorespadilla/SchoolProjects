# Simple Keyboard arrows based manual Control Aspect for 38Engine
# Sushil Louis

#from vector import Vector3
import utils
import math
import ent
from vector import Vector3
import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS

class ControlMgr:
    toggleMax = 0.1
    plantToggleMax = 0.5
    def __init__(self, engine):
        self.engine = engine
        print "Control Manager Constructed "
        
    def init(self):
        self.keyboard = self.engine.inputMgr.keyboard
        self.toggle = self.toggleMax
        self.plantToggle = self.plantToggleMax
        self.pastMenu = False
        self.menuCounter = 0
        self.menuExists = True;
        self.InstExists = True;
        self.storyExists = True;

    def stop(self):
        pass
        
    def tick(self, dtime):
        #----------make selected ent respond to keyboard controls-----------------------------------
        if self.toggle >= 0:
            self.toggle = self.toggle - dtime

        if self.plantToggle >= 0:
            self.plantToggle = self.plantToggle - dtime

        if  self.toggle < 0:
            self.keyboard.capture()
            self.selectedEnt = self.engine.gameMgr.stumpy

            # Speed Up
            if self.keyboard.isKeyDown(OIS.KC_UP) and self.pastMenu:
                self.toggle = self.toggleMax
                self.selectedEnt.desiredSpeed = utils.clamp(self.selectedEnt.desiredSpeed + self.selectedEnt.deltaSpeed, 0, self.selectedEnt.maxSpeed)
                print "Speeding UP", str(self.selectedEnt), self.selectedEnt.desiredSpeed

            if not(self.keyboard.isKeyDown(OIS.KC_UP)) and self.selectedEnt.desiredSpeed > 0:
                self.selectedEnt.desiredSpeed = 0

            # Slow down
            if  self.keyboard.isKeyDown(OIS.KC_DOWN) and self.pastMenu:
                self.toggle = self.toggleMax
                self.selectedEnt.desiredSpeed = utils.clamp(self.selectedEnt.desiredSpeed - self.selectedEnt.deltaSpeed, -self.selectedEnt.maxSpeed, 0)
                print "Slowing down", str(self.selectedEnt), self.selectedEnt.desiredSpeed

            if not(self.keyboard.isKeyDown(OIS.KC_DOWN)) and self.selectedEnt.desiredSpeed < 0 and self.pastMenu:
                self.selectedEnt.desiredSpeed = 0

            # Turn Left.
            if  self.keyboard.isKeyDown(OIS.KC_LEFT) and self.pastMenu:
                self.toggle = self.toggleMax
                self.selectedEnt.desiredHeading += self.selectedEnt.deltaYaw
                self.selectedEnt.desiredHeading = utils.fixAngle(self.selectedEnt.desiredHeading)
                print "Turn left", str(self.selectedEnt), self.selectedEnt.desiredHeading
            # Turn Right.
            if  self.keyboard.isKeyDown(OIS.KC_RIGHT) and self.pastMenu:
                self.toggle = self.toggleMax
                self.selectedEnt.desiredHeading -= self.selectedEnt.deltaYaw
                self.selectedEnt.desiredHeading = utils.fixAngle(self.selectedEnt.desiredHeading)
                print "Turn right", str(self.selectedEnt), self.selectedEnt.desiredHeading

            # Plant flower1
            if  self.keyboard.isKeyDown(OIS.KC_1) and self.engine.inventoryMgr.seed1 > 0 and self.pastMenu and self.engine.inventoryMgr.happiness < 400:
                self.toggle = self.toggleMax
                if self.plantToggle < 0:
                    thing = self.engine.entityMgr.createEnt( ent.FLOWER1, pos = Vector3(self.selectedEnt.pos.x+50, self.selectedEnt.pos.y-0, self.selectedEnt.pos.z))
                    thing2 = self.engine.entityMgr.createEnt(ent.FLOWER1, pos = Vector3(self.selectedEnt.pos.x-150, thing.pos.y-0, thing.pos.z))
                    self.engine.inventoryMgr.seed1 -= 1
                    if (self.engine.gameMgr.stumpy.pos.length() < 1400):
                          self.engine.inventoryMgr.happiness += 10
                    self.plantToggle = self.plantToggleMax

            # Plant flower2
            if  self.keyboard.isKeyDown(OIS.KC_2) and self.engine.inventoryMgr.seed2 > 0 and self.pastMenu and self.engine.inventoryMgr.happiness < 400:
                self.toggle = self.toggleMax
                if self.plantToggle < 0:
                    thing = self.engine.entityMgr.createEnt( ent.FLOWER2, pos = Vector3(self.selectedEnt.pos.x+100, self.selectedEnt.pos.y-0, self.selectedEnt.pos.z))
                    thing2 = self.engine.entityMgr.createEnt(ent.FLOWER2, pos = Vector3(thing.pos.x+50, thing.pos.y-0, thing.pos.z+50))
                    self.engine.inventoryMgr.seed2 -= 1
                    if (self.engine.gameMgr.stumpy.pos.length() < 1400):
                          self.engine.inventoryMgr.happiness += 8
                    self.plantToggle = self.plantToggleMax

            # Plant flower3
            if  self.keyboard.isKeyDown(OIS.KC_3) and self.engine.inventoryMgr.seed3 > 0 and self.pastMenu and self.engine.inventoryMgr.happiness < 400:
                self.toggle = self.toggleMax
                if self.plantToggle < 0:
                    thing = self.engine.entityMgr.createEnt( ent.FLOWER3, pos = Vector3(self.selectedEnt.pos.x+50, self.selectedEnt.pos.y-0, self.selectedEnt.pos.z))
                    thing2 = self.engine.entityMgr.createEnt(ent.FLOWER3, pos = Vector3(thing.pos.x+100, thing.pos.y-0, thing.pos.z+50))
                    self.engine.inventoryMgr.seed3 -= 1
                    if (self.engine.gameMgr.stumpy.pos.length() < 1400):
                          self.engine.inventoryMgr.happiness += 5
                    self.plantToggle = self.plantToggleMax

            # Plant flower4
            if  self.keyboard.isKeyDown(OIS.KC_4) and self.engine.inventoryMgr.seed4 > 0 and self.pastMenu and self.engine.inventoryMgr.happiness < 400:
                self.toggle = self.toggleMax
                if self.plantToggle < 0:
                    thing = self.engine.entityMgr.createEnt( ent.FLOWER4, pos = Vector3(self.selectedEnt.pos.x+50, self.selectedEnt.pos.y-0, self.selectedEnt.pos.z))
                    thing2 = self.engine.entityMgr.createEnt(ent.FLOWER4, pos = Vector3(thing.pos.x+100, thing.pos.y-0, thing.pos.z+50))
                    thing3 = self.engine.entityMgr.createEnt(ent.FLOWER4, pos = Vector3(thing.pos.x+150, thing.pos.y-0, thing.pos.z+50))
                    self.engine.inventoryMgr.seed4 -= 1
                    if (self.engine.gameMgr.stumpy.pos.length() < 1400):
                          self.engine.inventoryMgr.happiness += 1
                    self.plantToggle = self.plantToggleMax

            # Plant flower5
            if  self.keyboard.isKeyDown(OIS.KC_5) and self.engine.inventoryMgr.seed5 > 0 and self.pastMenu and self.engine.inventoryMgr.happiness < 350:
                self.toggle = self.toggleMax
                if self.plantToggle < 0:
                    thing = self.engine.entityMgr.createEnt( ent.FLOWER5, pos = Vector3(self.selectedEnt.pos.x+50, self.selectedEnt.pos.y-0, self.selectedEnt.pos.z))
                    thing2 = self.engine.entityMgr.createEnt(ent.FLOWER5, pos = Vector3(thing.pos.x+100, thing.pos.y-0, thing.pos.z+50))
                    self.engine.inventoryMgr.seed5 -= 1
                    if (self.engine.gameMgr.stumpy.pos.length() < 1400):
                          self.engine.inventoryMgr.happiness += 1
                    self.plantToggle = self.plantToggleMax

            # return for title screen
            if  self.keyboard.isKeyDown(OIS.KC_RETURN) and self.menuCounter < 3 and self.pastMenu == False:
                self.toggle = self.toggleMax
                if self.menuExists:
                    self.parent = self.engine.gfxMgr.tent.getParentSceneNode()
                    self.parent.detachObject(self.engine.gfxMgr.tent)
                    self.menuExists = False
                self.menuCounter+= 1

            #return for instrcions screen
            if self.keyboard.isKeyDown(OIS.KC_RETURN) and self.menuCounter >= 3 and self.pastMenu == False:
                self.toggle = self.toggleMax
                if self.storyExists:
                   self.parent = self.engine.gfxMgr.stent.getParentSceneNode()
                   self.parent.detachObject(self.engine.gfxMgr.stent)
                   self.storyExists = False
                self.menuCounter += 1

            #return for instrcions screen
            if self.keyboard.isKeyDown(OIS.KC_RETURN) and self.menuCounter >= 6 and self.pastMenu == False:
                self.toggle = self.toggleMax
                if self.InstExists:
                   self.parent = self.engine.gfxMgr.ient.getParentSceneNode()
                   self.parent.detachObject(self.engine.gfxMgr.ient)
                   self.InstExists = False
                self.menuCounter = 2
                self.pastMenu = True











