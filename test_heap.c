#include <stdio.h>
#include <stdlib.h>
#include "heap.c"
int main(void)
{
   int rvalue;
   int i = 0;
   int l;
   int *m;
   HeapType x;
   rvalue = initHeap(&x,7);
   
   rvalue = addHeap(&x,7);
   rvalue = addHeap(&x,4);
   rvalue = addHeap(&x,5);
   rvalue = addHeap(&x,6);
   rvalue = addHeap(&x,2);
   rvalue = addHeap(&x,1);
   rvalue = addHeap(&x,3);
   for(i=0;i<x.size;i=i+1)
   {
      printf("%d\n",(x.store)[i]);
   }
   printf("\n\n");
   rvalue = inorder(&x, &m, &l);
   for(i=0;i<x.size;i=i+1)
   {
      printf("%d\n",m[i]);
   }
   printf("\n\n");
   
   m = NULL;

   rvalue = preorder(&x, &m, &l);
   for(i=0;i<x.size;i=i+1)
   {
      printf("%d\n",m[i]);
   }
   printf("\n\n");

   m = NULL;

   rvalue = postorder(&x, &m, &l);
   for(i=0;i<x.size;i=i+1)
   {
      printf("%d\n",m[i]);
   }
   printf("\n\n");

   m = NULL;

   return 0;  
}
