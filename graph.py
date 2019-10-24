from queue import *
from stack import *

class graph:
   def __init__(self):
      self.store = []

   def addVertex(self,n):
      if(n<1):
         return -1
      else:
         for i in range(0,n,1):
            self.store = self.store + [[]]
         return len(self.store)

   def addEdge(self,from_idx,to_idx,directed,weight):
      if(from_idx >= len(self.store) or from_idx < 0 or to_idx >= len(self.store) or to_idx < 0 or weight < 0):
         return False
      else:
         if(directed == True):
            self.store[from_idx] = self.store[from_idx] + [[to_idx,weight]]
            return True
         elif(directed == False):
            self.store[from_idx] = self.store[from_idx] + [[to_idx,weight]]
            self.store[to_idx] = self.store[to_idx] + [[from_idx,weight]]
            return True

   def traverse(self,start,typeBreadth):
      traversal = []
      discovered = len(self.store)*[False]
      processed = len(self.store)*[False]
      if(typeBreadth == True):
         q = queue()
         if(start == None):
            vertices = range(0,len(self.store))
         else:
            vertices = [start]
            #print("in if")
         for i in vertices:
           # print("in for")
            accum = []
            if discovered[i] == False:
            #   print("in if 2")
               q.enqueue(i)
               discovered[i] = True
             #  print(len(q.store))
            while len(q.store) > 0:
             #  print("in while")
               x = q.dequeue()
               if (processed[x] == False):
                  accum = accum + [x]
              #    print("processing")
                  #print(x)
                  processed[x] = True
               for m in self.store[x]:
                  #print("x: " + str(x))
                  #print("m: " + str(m))
                  if discovered[m[0]] == False:
                     q.enqueue(m[0])
                     discovered[m[0]] = True
            if(accum != []):
               traversal = traversal + [accum]
         if start == None:
            return traversal
         else:
            return traversal[0]
      if(typeBreadth == False):
         s = stack()
         if(start == None):
            vertices = range(0,len(self.store))
         else:
            vertices = [start]
            #print("in if")
         for i in vertices:
           # print("in for")
            accum = []
            if discovered[i] == False:
            #   print("in if 2")
               s.push(i)
               discovered[i] = True
             #  print(len(q.store))
            while len(s.store) > 0:
             #  print("in while")
               x = s.pop()
               if (processed[x] == False):
                  accum = accum + [x]
              #    print("processing")
                  #print(x)
                  processed[x] = True
               for m in self.store[x]:
                  #print("x: " + str(x))
                  #print("m: " + str(m))
                  if discovered[m[0]] == False:
                     s.push(m[0])
                     discovered[m[0]] = True
            if(accum != []):
               traversal = traversal + [accum]
         if start == None:
            return traversal
         else:
            return traversal[0]

   def connectivity(self, vx, vy):
      connected = False
      depthF = self.traverse(None,False)
      path = [False,False]
      for i in depthF:
         found1 = False
         found2 = False
         found3 = False
         found4 = False
         for x in i:
            if(x == vx):
               found1 = True
            if(x == vy and found1 == True):
               found2 = True

         for x in i:
            if(x == vy):
               found3 = True
            if(x == vx and found3 == True):
               found4 = True

         if(found1 == True and found2 == True):
            path[0] = True

         if(found3 == True and found4 == True):
            path[1] = True

         if(path[0] == True and path[1] == True):
            return path
   
      return path
       
   def path(self,vx,vy):
      path = [[],[]]
      found1 = False
      child = False
      found2 = False
      depthFirst1 = self.traverse(vx,False)    
      depthFirst2 = self.traverse(vy,False)
      #print("depth1: " + str(depthFirst1))
      #print("depth2: " + str(depthFirst2))
      connected = self.connectivity(vx,vy)
      if(connected == [False,False]):
         return [[],[]]
      if(connected[0] == True):
         for i in range(0,len(depthFirst1),1):
            #print("depth[i]: " + str(depthFirst1[i]))
            if(depthFirst1[i] == vy):
               path[0] = path[0] + [depthFirst1[i]]
               found1 = True
               break
            children = self.store[depthFirst1[i]]
            #print("children: " + str(children))
            for x in children:
               if(i < len(depthFirst1)-1):
                  #print("x[0]: " + str(x[0]))
                  #print("depthFirst1[i+1] " + str(depthFirst1[i+1]))
                  if(x[0] == depthFirst1[i+1]):
                     child = True
                     path[0] = path[0] + [depthFirst1[i]]
                     #print("added in between " + str(path[0]))
                     break
            if(child == False):
               path[0] = [vx]
            child = False 
      if(found1 == False):
         path[0] == []

      if(connected[1] == True):
         for i in range(0,len(depthFirst2),1):
            #print("depth[i]: " + str(depthFirst1[i]))
            if(depthFirst2[i] == vx):
               path[1] = path[1] + [depthFirst2[i]]
               found1 = True
               break
            children = self.store[depthFirst2[i]]
            #print("children: " + str(children))
            for x in children:
               if(i < len(depthFirst2)-1):
                  #print("x[0]: " + str(x[0]))
                  #print("depthFirst1[i+1] " + str(depthFirst1[i+1]))
                  if(x[0] == depthFirst2[i+1]):
                     child = True
                     path[1] = path[1] + [depthFirst2[i]]
                     #print("added in between " + str(path[0]))
                     break
            if(child == False):
               path[1] = [vy]
            child = False
      if(found1 == False):
         path[1] == []

      return path    
      
#def main():
#   x = graph()
#   m = x.addVertex(8)
   #print(m)

#   x.addEdge(0,1,True,1)
#   x.addEdge(0,2,True,1)
#   x.addEdge(0,3,True,1)
#   x.addEdge(1,4,True,1)
#   x.addEdge(1,5,True,1)
#   x.addEdge(3,7,True,1)
#   x.addEdge(5,4,True,1)
#   x.addEdge(6,5,True,1)
#   x.addEdge(6,0,True,1)

   #print(x.store)

#   traversal = x.traverse(6,True)

   #print(traversal)

#   traversal = x.traverse(6,False)

   #print(traversal)

#   y = x.connectivity(0,6)

   #print(y)

#   y = x.path(4,0)

   #print(y)

#main()      
