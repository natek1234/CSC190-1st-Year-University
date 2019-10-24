def sortr(L):
   table = [0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9]
   new = [[],[],[],[],[],[],[],[],[],[]]
   greatest = 0;
   for i in range(0,len(L),1):
      L[i] = str(L[i])
      if(greatest < len(L[i])):
         greatest = len(L[i])

   #print(str(L))
   #print(greatest)
   for i in range(0,greatest,1):
      for n in range(0,len(L),1):
         index = len(L[n])-i-1
         if(index < 0):
            num = 0
         else:
            num = int((L[n])[index])
            
         new[num] = new[num] + [L[n]]

      LN = []
      for n in new:
         LN = LN + n

      L = LN.copy()
      
      #print("L new: " + str(L))
      new = [[],[],[],[],[],[],[],[],[],[]]

   for i in range(0,len(L),1):
      L[i] = int(L[i])
 
   return L


#def main():

   #v1=[10,9,8,7,6,5,4,3,2,1,0]
   #v2=[100,1,1000,9,8,7,2,2000,10]
   #v3=[100,10,1000,9,8,7,2,6,5,2,3,1]

   #for i in [ v1,v2,v3 ]:
   #   x=list(i)
   #   x = sortr(x)
   #   print(str(x))

#main()


