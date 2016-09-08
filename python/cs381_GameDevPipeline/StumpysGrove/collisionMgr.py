import utils
import math

class CollisionMgr:
    def __init__(self, engine):
        self.engine = engine
        pass

    def init(self):
        self.entityMgr = self.engine.entityMgr
        self.selectedEnt = self.engine.selectionMgr.selectedEnt
        pass

    def checkForCollision(self, obj1, obj2):
        diffVec = obj1.pos - obj2.pos
        sumRadius = obj1.radius + obj2.radius
        if diffVec.length() < sumRadius and obj1 != obj2:
            return True
        else:
            return False
        
    def tick(self, dt):
        for eid, ent in self.entityMgr.ents.iteritems():
            diffVec = self.selectedEnt.pos - ent.pos
            sumRadius = self.selectedEnt.radius  + ent.radius
            if self.checkForCollision(self.selectedEnt, ent) and ent.isSolid:
                self.selectedEnt.pos.x -= self.selectedEnt.pos.x / diffVec.length()
                self.selectedEnt.pos.z -= self.selectedEnt.pos.z / diffVec.length()
            elif self.checkForCollision(self.selectedEnt, ent) and ent.isSolid == False:
                if ent.mesh == 'blueflower.mesh' and ent.hasSeed == True:
                    ent.hasSeed = False
                    self.engine.inventoryMgr.seed1 += 1

                elif ent.mesh == 'flower2.mesh' and ent.hasSeed == True:
                    ent.hasSeed = False
                    self.engine.inventoryMgr.seed2 += 1

                elif ent.mesh == 'flower3.mesh' and ent.hasSeed == True:
                    ent.hasSeed = False
                    self.engine.inventoryMgr.seed3 += 1

                elif ent.mesh == 'flower4.mesh' and ent.hasSeed == True:
                    ent.hasSeed = False
                    self.engine.inventoryMgr.seed4 += 1

                elif ent.mesh == 'mean.mesh' and ent.hasSeed == True:
                    ent.hasSeed = False
                    self.engine.inventoryMgr.seed5 += 1
                    self.engine.inventoryMgr.happiness -= 5

    def stop(self):
        pass
