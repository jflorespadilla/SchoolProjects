import math


class Command:
   def __init__(self, ent, target):
      self.ent = ent
      self.target = target

   def tick(self, dtime):
      pass


class move(Command):
   def __init__(self, ent, target):
      Command.__init__(self, ent, target)
      direction = target - self.ent.pos
      self.ent.desiredHeading = math.atan2(-direction.z, direction.x)
      self.ent.desiredSpeed = self.ent.maxSpeed

   def tick(self, dtime):
      distance = (self.target - self.ent.pos).length()
      if distance < 100:
         self.ent.desiredSpeed = 0

class intercept(Command):
   def __init__(self, ent, target):
      Command.__init__(self, ent, target)
		

   def tick(self, dtime):
      relativeVel = self.target.vel - self.ent.vel
      relativeSpeed = relativeVel.length()
      direction = self.target.pos - self.ent.pos
      distance = direction.length()
      time = distance / relativeSpeed
      interceptionPoint = self.target.pos + self.target.vel*time
      diff = interceptionPoint - self.ent.pos
      self.ent.desiredHeading = math.atan2(-direction.z, direction.x)
      self.ent.desiredSpeed = self.ent.maxSpeed

class follow(Command):
   def __init__(self, ent, target):
      Command.__init__(self, ent, target)
		

   def tick(self, dtime):
      direction = self.target.pos - self.ent.pos
      self.ent.desiredHeading = math.atan2(-direction.z, direction.x)
      if( direction.length() >= 100 ):
         self.ent.desiredSpeed = self.ent.maxSpeed
      else:
         self.ent.desiredSpeed = self.target.speed


