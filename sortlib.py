def selection_sort(u):
   temp = float('Inf')
   index = 0
   for n in range(0,len(u),1):
      temp = u[n]
      for i in range(n,len(u),1):
         if u[i]<temp:
            temp = u[i]
            index = i
      temp2 = u[n]
      u[n] = temp
      u[index] = temp2
   return True

def heapify(u):
   swap = True
   while swap == True:
      swap = False
      for i in range(0,len(u),1):
         LC = 2*i + 1
         RC = 2*i + 2
         if(LC < len(u)):
            if(u[i]<u[LC]):
               temp = u[LC]
               u[LC] = u[i]
               u[i] = temp
               swap = True
         if(RC < len(u)):
            if(u[i]<u[RC]):
               temp = u[RC]
               u[RC] = u[i]
               u[i] = temp
               swap = True 
   return True

def reheapify(u,end):
   for i in range(0,end+1,1):
      LC = 2*i + 1
      RC = 2*i + 2
      if(LC < end+1):
         if(u[i]<u[LC]):
            temp = u[LC]
            u[LC] = u[i]
            u[i] = temp
      if(RC < end+1):
         if(u[i]<u[RC]):
            temp = u[RC]
            u[RC] = u[i]
            u[i] = temp
   return True

def heap_sort(u):
   x = heapify(u)
   length = len(u)-1
   for i in range(0,len(u),1):
      temp = u[0]
      u[0] = u[length]
      u[length] = temp
      length = length - 1
      x = reheapify(u,length)
#      print("re ;" + str(u))
   return True

def merge_sort(u):
   length = len(u)
   if len(u) <= 1:
      return True
   M = length//2
   UL = u[M:]
   LL = u[:M]
   rval = merge_sort(UL)
   rval = merge_sort(LL)
   rval = merge(UL,LL,u)
   return True

def merge(UL,LL,u):
   count = 0
   L1 = 0
   L2 = 0
   while count < len(u):
      if(L1 < len(UL) and L2 < len(LL)):
         if(UL[L1] < LL[L2]):
            u[count] = UL[L1]
            L1 = L1 + 1
         else:
            u[count] = LL[L2]
            L2 = L2 + 1
      elif(L1 >= len(UL) and L2 < len(LL)):
         u[count] = LL[L2]
         L2 = L2 + 1
      elif(L1 < len(UL) and L2 >= len(LL)):
         u[count] = UL[L1]
         L1 = L1 + 1
      count = count + 1
           
#   print("merge " + str(u))
   return True

#def main():
#   v1=[10,9,8,7,6,5,4,3,2,1,0]
#   v2=[100,1,1000,9,8,7,2,2000,10]
#   v3=[100,10,1000,9,8,7,2,6,5,2,3,1]

#   for i in [ v1,v2,v3 ]:
#      x=list(i)
#      selection_sort(x)
#      print("Selection  sort: " + str(x))

#      x=list(i)
#      heapify(x)
#      print("Heapify: " + str(x))

#      x=list(i)
#      heap_sort(x)
#      print("Heap Sort: " + str(x))

#      x=list(i)
#      merge_sort(x)
#      print("Merge Sort: " + str(x))

#      x=list(i)
#      quick_sort(x,0,len(x)-1)
#      print(x)



#main()

