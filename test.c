#include "bs.c"
#include <stdio.h>
#include "hs.c"
int main(void)
{
   int i=0;
   int vals[10];
   int rvalue;
   for (i=0;i<10;i=i+1){
      vals[i]=100-i;
   }
   for (i=0;i<10;i++){
      printf("in[%d]=%d\n",i,vals[i]);
   }
   rvalue = hs(vals,10,&gt);   
   for (i=0;i<10;i++){
      printf("out[%d]=%d\n",i,vals[i]);
   }
   return 0;
   
}
