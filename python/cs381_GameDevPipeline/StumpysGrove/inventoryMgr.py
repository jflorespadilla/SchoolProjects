class InventoryMgr:
    def __init__(self, engine):
        self.engine = engine
        self.grow1 = True
        self.grow2 = True
        self.grow3 = True
        self.grow4 = True
        self.grow5 = True
        #print "starting Game mgr"
        pass

    def init(self):
        self.seed1 = 0
        self.seed2 = 0
        self.seed3 = 0
        self.seed4 = 0
        self.seed5 = 0

        self.happiness = 1

    def tick(self, dt):
        if self.happiness >= 20 and self.grow1 == True:
            self.engine.gameMgr.stumpy.maxGrowth *= 1.2
            self.engine.gameMgr.stumpy.maxRad *= 1.1
            self.grow1 = False
        if self.happiness >= 50 and self.grow2 == True:
            self.engine.gameMgr.stumpy.maxGrowth *= 1.5
            self.engine.gameMgr.stumpy.maxRad *= 1.15
            self.grow2 = False
        if self.happiness >= 100 and self.grow3 == True:
            self.engine.gameMgr.stumpy.maxGrowth *= 2.5
            self.engine.gameMgr.stumpy.maxRad *= 1.2
            self.grow3 = False
        if self.happiness >= 200 and self.grow4 == True:
            self.engine.gameMgr.stumpy.maxGrowth *= 4
            self.engine.gameMgr.stumpy.maxRad *= 1.4
            self.grow4 = False
    def stop(self):
        pass
