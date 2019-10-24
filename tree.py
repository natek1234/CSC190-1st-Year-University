from queue import queue
from Realqueue import Rqueue
from binary_tree import *
class tree:
   def __init__(self,x):
      self.store = [x,[]]

   def AddSuccessor(self,x):
      self.store[1] = self.store[1] + [x]
      return True

   def Print_DepthFirst(self):
      print(str(self.store[0]))
      if(self.store[1] == []):         
         return True
      else:
         for i in range(0,len((self.store)[1])):
            x = self.store[1][i]
            print("   ", end = '')
            x.Print_DepthHelper("   ")            
         return True
   
   def Print_DepthHelper(self, y):
      print(str(self.store[0]))
      if(self.store[1] == []):
         return True
      else:
         y = y + "   "
         for i in range(0,len((self.store)[1])):
            x = self.store[1][i]
            print(y, end = '')
            x.Print_DepthHelper(y)
         return True   

   def Get_LevelOrder(self):
      x=queue()
      lin = []
      lin = lin + [self.store[0]]
      x.enqueue(self.store[1])
      while x.empty() == False:
         r = x.dequeue()
         for i in r:
            lin = lin + [i.store[0]]
            x.enqueue(i.store[1]) 
            x.q = enqHelp(x.q)
      print(lin)
      return True

   def ConvertToBinaryTree(self):
      head = self.ConvertBinaryHelper([])
      return head      
          
   def ConvertBinaryHelper(self,S):
      x = self.store[1]
      head = self.store[0]
      if len(x) == 0:
          L = []
      else:
          if len(x) <= 1:
              LS = []
          else:
              LS = (self.store[1])[1:]
          L = (self.store[1])[0].ConvertBinaryHelper(LS)
      if S == []:
          R = []
      else:
          if len(S) <= 1:
              RS = []
          else:
              RS = S[1:]
          R = S[0].ConvertBinaryHelper(RS)
      r=tree(head)

      if L != []:
          r.AddSuccessor(L)

      if R != []:
          r.AddSuccessor(R)
      return r         
            

def enqHelp(y):
   n = []
   for l in y:
      if type(l) == list:
         for z in l:
            n = n + [z]      
   return [n]
                      
      


      
