# Entity class to hold information about entities for 38Engine
# Sushil Louis

from vector        import Vector3
from physics       import Physics
from render        import Renderer
from unitAI			 import UnitAI
import ogre.renderer.OGRE as ogre

#-----------------------------------------------------------------------------------------
class Entity:
    pos  = Vector3(0, 0, 0)
    vel  = Vector3(0, 0, 0)
    yaw  = 0

    aspectTypes = [Physics, Renderer, UnitAI]
    
    def __init__(self, engine, id, pos = Vector3(0,0,0), mesh = 'robot.mesh', vel = Vector3(0, 0, 0), yaw = 0):
        self.engine = engine
        self.uiname = "Robot" + str(id)
        self.eid = id
        self.pos = pos
        self.vel = vel
        self.mesh = mesh
        self.deltaSpeed = 10
        self.deltaJump = 75
        self.deltaYaw   = 0.075
        self.speed = 0.0
        self.heading = 0.0
        self.aspects = []
        self.isSelected = False
        self.desiredVertical = 0
        self.maxVertical = 200

    def init(self):
        self.initAspects()

    def initAspects(self):
        for aspType in self.aspectTypes:
            self.aspects.append(aspType(self))
        
    def tick(self, dtime):
        for aspect in self.aspects:
            aspect.tick(dtime)

    def __str__(self):
        x = "--------------------\nEntity: %s \nPos: %s, Vel: %s,  mesh = %s\nSpeed: %f, Heading: %f, desiredSpeed: %f, desiredHeading: %f" % (self.uiname, str(self.pos), str(self.vel), self.mesh, self.speed, self.heading, self.desiredSpeed, self.desiredHeading)
        return x
#----------------------------Grandpa-------------------------------------------------------------
class STUMPY(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'stumpy.mesh'
        self.uiname = 'STUMPY' + str(id)
        self.acceleration = 40
        self.turningRate  = 0.6
        self.maxSpeed = 120
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/stumpy'
        self.maxGrowth = .1
        self.scale = .1
        self.maxRad = 110
        self.radius = 110
        self.inAir = True
        self.pos.y = 0

    def setGrow(self):        
        self.scale += .005
        self.radius += .5

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth

        if self.radius > self.maxRad:
            self.radius = self.maxRad

        self.aspects[1].node.setScale(self.scale,self.scale,self.scale)

#-----------------------------------------------------------------------------------------
class FLOWER1(Entity):
    def __init__(self, engine, id, pos = Vector3(0,50,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'blueflower.mesh'
        self.uiname = 'FLOWER1' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/color2'
        self.maxGrowth = 100
        self.scale = 35
        self.radius = 50
        self.inAir = True
        self.isSolid = False
        self.blossomed = False
        self.hasSeed = False

    def setGrow(self):
        self.scale += .1

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True
        elif self.scale == self.maxGrowth: 
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True

        self.aspects[1].node.setScale(self.scale,self.scale,self.scale)

#-----------------------------------------------------------------------------------------
class FLOWER2(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'flower2.mesh'
        self.uiname = 'FLOWER2' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/color'
        self.maxGrowth = 160
        self.scale = 70
        self.radius = 50
        self.inAir = True
        self.isSolid = False
        self.blossomed = False
        self.hasSeed = False

    def setGrow(self):
        self.scale += .2

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True
        elif self.scale == self.maxGrowth: 
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True

        self.aspects[1].node.setScale(self.scale*.8,self.scale*.6,self.scale*.8)
#-----------------------------------------------------------------------------------------
class FLOWER3(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'flower3.mesh'
        self.uiname = 'FLOWER3' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/color3'
        self.maxGrowth = 160
        self.scale = 60
        self.radius = 50
        self.inAir = True
        self.isSolid = False
        self.blossomed = False
        self.hasSeed = False

    def setGrow(self):
        self.scale += .3

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True
        elif self.scale == self.maxGrowth: 
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True

        self.aspects[1].node.setScale(self.scale,self.scale,self.scale)
#-----------------------------------------------------------------------------------------
class FLOWER4(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'flower4.mesh'
        self.uiname = 'FLOWER4' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/color4'
        self.maxGrowth = 160
        self.scale = 70
        self.radius = 50
        self.inAir = True
        self.isSolid = False
        self.blossomed = False
        self.hasSeed = False

    def setGrow(self):
        self.scale += .5

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True
        elif self.scale == self.maxGrowth: 
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True

        self.aspects[1].node.setScale(self.scale,self.scale,self.scale)
#-----------------------------------------------------------------------------------------
class FLOWER5(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'mean.mesh'
        self.uiname = 'FLOWER5' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/color'
        self.maxGrowth = 180
        self.scale = 70
        self.radius = 50
        self.inAir = True
        self.isSolid = False
        self.blossomed = False
        self.hasSeed = False

    def setGrow(self):
        self.scale += .5

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True
        elif self.scale == self.maxGrowth: 
            if self.blossomed == False:
                self.hasSeed = True
                self.blossomed = True

        self.aspects[1].node.setScale(self.scale,self.scale,self.scale)
#-----------------------------------------------------------------------------------------
class TREE(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'tree1.mesh'
        self.uiname = 'TREE' + str(id)
        self.acceleration  = 0
        self.turningRate   = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.material = 'SOLID/TEX/colorG'
        self.maxGrowth = 250
        self.scale = 200
        self.radius = 50
        self.inAir = True
        self.isSolid = True
        self.pos.y = -50

    def setGrow(self):
        self.scale += .02

        if self.scale > self.maxGrowth:
            self.scale = self.maxGrowth

        self.aspects[1].node.setScale(self.scale*.6,self.scale*1,self.scale*.6)
#-----------------------------------------------------------------------------------------
class GRANDPA(Entity):
    def __init__(self, engine, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, engine, id, pos = pos, vel = vel, yaw = yaw)
        self.mesh = 'cube.mesh'
        self.uiname = 'GRANDPA' + str(id)
        self.acceleration = 4
        self.turningRate = 0.2
        self.maxSpeed = 30
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.maxGrowth = 1
        self.scale = 1
        self.radius = 50
        self.inAir = True
        self.isSolid = True

    def setGrow(self):
        pass
#-----------------------------------------------------------------------------------------

