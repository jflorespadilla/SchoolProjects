# Simple ORIENTED Physics for 38Engine
# vel is rate of change of pos
# Sushil Louis

#from vector import Vector3
import utils
import math

class Physics:
    def __init__(self, ent):
        self.ent = ent
        self.gravity = -22
        self.collisonDetected = False
        self.collisionList = []


    #def detectCollision(self, obj):
        #distance = obj.pos.length() - self.ent.pos.length()
        #radiusDist = obj.radius - self.ent.radius
        #if distance < radiusDist:
            #self.collisionDetected = True
            #self.collisionList.append(obj)
        #pass

    #def collison(self, detection):
        #if detection:
            #for ent in self.collisionList:
                #if ent.pos.x - self.ent.pos.x < ent.radius + self.ent.radius
        #pass

        
    def tick(self, dtime):
        #----------position-----------------------------------
#        if self.ent.pos.y > self.ent.radius and self.ent.inAir == True:
#            self.ent.desiredVertical = self.ent.desiredVertical + (self.gravity * dtime)
#        elif self.ent.pos.y < self.ent.radius and self.ent.inAir == True:
#            self.ent.inAir = False
#            self.ent.desiredVertical = 0
#            self.ent.pos.y = self.ent.radius

        timeScaledAcceleration = self.ent.acceleration * dtime
        self.ent.speed += utils.clamp( self.ent.desiredSpeed - self.ent.speed, -timeScaledAcceleration, timeScaledAcceleration)


        self.ent.vel.x = math.cos(-self.ent.heading) * self.ent.speed
        self.ent.vel.z = math.sin(-self.ent.heading) * self.ent.speed
        self.ent.vel.x = math.cos(self.ent.heading) * self.ent.speed
        self.ent.vel.z = -math.sin(self.ent.heading) * self.ent.speed
        self.ent.vel.y = self.ent.desiredVertical
        
        self.ent.pos = self.ent.pos + (self.ent.vel * dtime)

        #------------heading----------------------------------

        timeScaledRotation = self.ent.turningRate * dtime
        angleDiff = utils.diffAngle(self.ent.desiredHeading, self.ent.heading)
        dheading = utils.clamp(angleDiff, -timeScaledRotation, timeScaledRotation)

        self.ent.heading += dheading

        
