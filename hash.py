def f(x):
   l = x%11
   l = l*10
   if l == 10:
      l = l + 1;
   if l == 100:
      l = l - 1
   return l;
