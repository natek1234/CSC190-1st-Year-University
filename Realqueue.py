class Rqueue:
   def __init__(self):
      self.q = []

   def enqueue(self, value):
      self.q =  [value] + self.q
      return True
 
   def dequeue(self):
      if self.q == []:
         return False
      x=(self.q)[len(self.q)-1]
      self.q = self.q[0:len(self.q)-1]
      return x

   def empty(self):
      if self.q == [] or self.q == [[]]:
         return True
      else:
         return False
