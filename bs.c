int bs(int *x, int size, int (*compare)(int x, int y));
int lt(int x, int y);
int gt(int x, int y);


int bs(int *x, int size, int (*compare)(int x, int y))
{
   int swapped = 1;
   int i = 0;
   int temp = 0;
   while(swapped == 1)
   {
      swapped = 0;
      for(i=0;i<size-1;i=i+1)
      {
         if(compare(x[i],x[i+1]) == 1)
         {
            temp = x[i+1]; 
            x[i+1] = x[i];
            x[i] = temp;
            swapped = 1;    
         }
      }
   }
}

int lt(int x, int y)
{
   if(x < y)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int gt(int x, int y)
{
   if(x>y)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

