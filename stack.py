class stack:
   def __init__(self):
      self.stck = []

   def push(self, value):
      self.stck = [value] + self.stck
      return True
 
   def pop(self):
      if self.stck == []:
         return False
      x=(self.stck)[0]
      self.stck = self.stck[1:]
      return x
