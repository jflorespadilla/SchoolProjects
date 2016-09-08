class UnitAI:
   def __init__(self, ent):
      self.ent = ent
      self.command = None

   def tick(self, dtime):
      if(self.command):
         self.command.tick(dtime)

   def setCommand(self, commandType, target):
      self.command = commandType(self.ent, target)
		
	
