# Selection Manager tracks currently selected ent, selected group of ents, ...
import ogre.io.OIS as OIS # needed to check keyboard

class SelectionMgr:
    def __init__(self, engine):
        self.engine = engine
        pass

    def init(self):
        self.selectedEnt = self.engine.gameMgr.stumpy
        self.keyboard = self.engine.inputMgr.keyboard
        self.toggle = 0.1

    def tick(self, dtime):
        pass


 
    def stop(self):
        self.selectedEnt = None
        pass


