from tree import *
from binary_tree import *

def main():
   x = tree(1)
   y = tree(2)
   z = tree(3)
   a = tree(4)
   b = tree(5)
   c = tree(6)
   d = tree(7)
   e = tree(8)
   f = tree(9)
   g = tree(10)
  
   #x.AddSuccessor(y)
   #x.AddSuccessor(d)
   #y.AddSuccessor(z)
   #y.AddSuccessor(c)
   #z.AddSuccessor(a)
   #z.AddSuccessor(b)
   #b.AddSuccessor(e)
   #b.AddSuccessor(f)
   #b.AddSuccessor(g)


      
   #x.AddSuccessor(y)
   #x.AddSuccessor(z)
   #x.AddSuccessor(a)
   #y.AddSuccessor(b)
   #y.AddSuccessor(c)
   #z.AddSuccessor(d)
   #a.AddSuccessor(e)
   #a.AddSuccessor(f)
   #a.AddSuccessor(g)

   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)
   #x.AddSuccessor(d)

   x=binary_tree(1)
   z = binary_tree(2)
   x.AddLeft(z)
   z.AddLeft(7)
   z.AddRight(8)
   y=binary_tree(3)
   y.AddLeft(binary_tree(4))
   y.AddRight(binary_tree(5))
   x.AddRight(y)

   x.Get_LevelOrder()
   
   r = x.ConvertToTree()
   print(r)

   r[1].Get_LevelOrder()

main()
