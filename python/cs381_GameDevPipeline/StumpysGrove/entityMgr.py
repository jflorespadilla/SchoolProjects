from vector import Vector3


class EntityMgr:
    def __init__(self, engine):
        print "starting ent mgr"
        self.engine = engine
        self.entName = None
                
    def init(self):
        self.ents = {}
        self.nEnts = 0
        import ent



    def createEnt(self, entType, pos = (0,0,0), yaw = 0):
        ent = entType(self.engine, self.nEnts, pos = pos, yaw = yaw)
        #print "EntMgr created: ", ent.uiname, ent.eid, self.nEnts
        self.entName = ent.uiname
        ent.init()
        self.ents[self.nEnts] = ent;
        self.nEnts = self.nEnts + 1
        return ent


    def tick(self, dt):
        for eid, ent in self.ents.iteritems():
            ent.tick(dt)
            ent.setGrow()

