# Simple Keyboard arrows based manual Control Aspect for 38Engine
# Sushil Louis

#from vector import Vector3
import utils
import math
import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS

class ManualControl:
    toggleMax = 0.5
    def __init__(self, ent):
        self.ent = ent
        print "Rendering seting up for: ", str(self.ent)
        self.keyboard = self.ent.engine.inputMgr.keyboard
        self.toggle = 0
        
        
    def tick(self, dtime):
        #----------make selected ent respond to keyboard controls-----------------------------------
        selectedEnt != self.ent.engine.selectionMgr.selectedEnt:

        if not selectedEnt:
            return


        if self.toggle >= 0:
            self.toggle = self.toggle - dtime

        self.keyboard.capture()

        # Speed Up
        if  self.toggle < 0 and self.keyboard.isKeyDown(OIS.KC_UP):
            self.toggle = self.toggleMax
            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)
            print "Speeding UP", str(selectedEnt), selectedEnt.desiredSpeed

        # Slow down
        if  self.toggle < 0 and self.keyboard.isKeyDown(OIS.KC_DOWN):
            self.toggle = self.toggleMax
            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)
            print "Slowing down", str(selectedEnt), selectedEnt.desiredSpeed


        # Turn Left.
        if  self.toggle < 0 and self.keyboard.isKeyDown(OIS.KC_LEFT):
            self.toggle = self.toggleMax
            selectedEnt.desiredHeading += selectedEnt.deltaYaw
            selectedEnt.desiredHeading = utils.fixAngle(selectedEnt.desiredHeading)
            print "Turn left", str(selectedEnt), selectedEnt.desiredHeading

            
        # Turn Right.
        if  self.toggle < 0 and self.keyboard.isKeyDown(OIS.KC_RIGHT):
            self.toggle = self.toggleMax
            selectedEnt.desiredHeading -= selectedEnt.deltaYaw
            selectedEnt.desiredHeading = utils.fixAngle(selectedEnt.desiredHeading)
            print "Turn right", str(selectedEnt), selectedEnt.desiredHeading

