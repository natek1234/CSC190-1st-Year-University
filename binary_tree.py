from queue import queue
from tree import *
class binary_tree:
   def __init__(self, val):
      self.t = [val]


   def AddLeft(self, val):
      if type(val) == int:
         val = binary_tree(val)
      if(len(self.t) == 3):
         self.t = [self.t[0]] + [val] + [self.t[2]]
      elif(len(self.t) == 1):
         self.t = [self.t[0]] + [val] + [None]
      else:
         return False 
      return True

   def AddRight(self, val):
      if type(val) == int:
         val = binary_tree(val)
      if(len(self.t) == 3):
         self.t = [self.t[0]] + [self.t[1]] + [val]
      elif(len(self.t) == 1):
         self.t = [self.t[0]] + [None] + [val]
      else:
         return False
      return True

   def Get_LevelOrder(self):
      x=queue()
      lin = []
      lin = lin + [self.t[0]]
      if len(self.t) > 1:
         x.enqueue(self.t[1:]) 
      while x.empty() == False:
         r = x.dequeue()
         for i in r:
            lin = lin + [i.t[0]]
            if len(i.t) > 1:
               x.enqueue(i.t[1:])
               x.q = enqHelp(x.q)
      print(lin)
      return True

   def ConvertToTree(self):
      if self.t[2] != None:
         return [False, None]

      head = self.t[0]
      r = tree(head)

      if len(self.t)>1:
         x=self.t[1:]

      else:
         x = []

      if len(x) != 0:
         S = x[0] 

         while True:
            i = S.ConvertToTree()
            SS = S.t[1:]
            r.AddSuccessor(i)
            if len(SS) == 2:
               S = SS[1]
            else:
               break

      return [True, r]

def enqHelp(y):
   n = []
   for l in y:
      if type(l) == list:
         for z in l:
            n = n + [z]
   return [n]

