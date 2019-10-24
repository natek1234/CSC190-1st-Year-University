class stack:
   def __init__(self):
      self.store = []

   def push(self,item):
      self.store = [item] + self.store
      return True

   def pop(self):
      if(len(self.store) == 1):
         item = self.store[0]
         self.store = []
         return item
      elif(len(self.store) < 1):
         return -1
      else:
         item = self.store[0]
         self.store = self.store[1:]
         return item
