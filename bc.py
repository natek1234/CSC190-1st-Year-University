from stackLib import *

def bc(input):
   x = stack()
   TorF = True
   for i in range(0,len(input),1):
      if (input[i] == '(' or input[i] == '{' or input[i] == '['):
         x.push(input[i])
      elif (input[i] == ')' or input[i] == '}' or input[i] == ']'):
         TorF = (x.pop())
         if(TorF == False):
            return [False,i]
   if (len(x.stck) == 0):
      return [True, -1]
   else:
      return [False, 0]
     
