from vector import Vector3
import ent
import random

class GameMgr:
    def __init__(self, engine):
        self.engine = engine
        #print "starting Game mgr"
        pass

    def init(self):
        self.loadLevel()


    def loadLevel(self):
        self.game1()
        

    def game1(self):
       x = 0
       for x in range(0,35):
          #print "Flower1 Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx > 2000:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER1, pos = Vector3(numx, 0, numz))
                #print "Flower1 Created: ", thing.uiname, thing.eid

          if numz > 2000:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER1, pos = Vector3(numx, 0, numz))
                #print "Flower1 Created: ", thing.uiname, thing.eid
               
 
       for x in range(0,40):
          #print "Flower2 Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx < -2000:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER2, pos = Vector3(numx, 0, numz))
                #print "Flower2 Created: ", thing.uiname, thing.eid

          if numz > 2000 or numz < -2000:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER2, pos = Vector3(numx, 0, numz))
                #print "Flower2 Created: ", thing.uiname, thing.eid

       for x in range(0,50):
          #print "Flower3 Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx > 1500 or numx < -1500:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER3, pos = Vector3(numx, 0, numz))
                #print "Flower3 Created: ", thing.uiname, thing.eid

          if numz > 1500 or numz < -1500:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER3, pos = Vector3(numx, 0, numz))
                #print "Flower3 Created: ", thing.uiname, thing.eid

       for x in range(0,100):
          #print "Flower4 Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx > 1200 or numx < -1200:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER4, pos = Vector3(numx, 0, numz))
                #print "Flower4 Created: ", thing.uiname, thing.eid

          if numz > 1200 or numz < -1200:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER4, pos = Vector3(numx, 0, numz))
                #print "Flower4 Created: ", thing.uiname, thing.eid

       for x in range(0,40):
          #print "Flower5 Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx > 2500 or numx < -2500:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER5, pos = Vector3(numx, 0, numz))
                #print "Flower5 Created: ", thing.uiname, thing.eid

          if numz > 2500 or numz < -2500:
                thing = self.engine.entityMgr.createEnt( ent.FLOWER5, pos = Vector3(numx, 0, numz))
                #print "Flower5 Created: ", thing.uiname, thing.eid

       for x in range(0,320):
          #print "Tree Creating", str(self.engine.entityMgr.entName)
          numx = random.triangular(-10000, 10000)
          numz = random.triangular(-10000, 10000)
          if numx > 1200 or numx < -1200:
                thing = self.engine.entityMgr.createEnt( ent.TREE, pos = Vector3(numx, 0, numz))
                #print "Tree Created: ", thing.uiname, thing.eid

          if numz > 1200 or numz < -1200:
                thing = self.engine.entityMgr.createEnt( ent.TREE, pos = Vector3(numx, 0, numz))
                #print "Tree Created: ", thing.uiname, thing.eid
        
       #print "Stumpy Creating", str(self.engine.entityMgr.entName)
       self.stumpy = self.engine.entityMgr.createEnt( ent.STUMPY, pos = Vector3(-20, 0, 805), yaw = 0)
       #print "Stumpy Created: ", self.stumpy.uiname, self.stumpy.eid
       self.stumpy.desiredHeading = -80
       self.stumpy.heading = -80


    def tick(self, dt):
        pass

    def stop(self):
        pass
        

