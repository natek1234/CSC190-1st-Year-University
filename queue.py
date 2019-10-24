class queue:
   def __init__(self):
      self.store = []

   def enqueue(self,item):
      self.store = self.store + [item]
      return True
    
   def dequeue(self):
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
         

