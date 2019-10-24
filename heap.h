#include <stdio.h>
#include <stdlib.h>
typedef struct {
   int key;
   unsigned int valid;
} keyType;

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap (HeapType *pHeap,int size);
int inorder  (HeapType *pHeap, int **output, int *o_size);
int preorder (HeapType *pHeap, int **output, int *o_size);
int postorder(HeapType *pHeap, int **output, int *o_size);
int inHelp(int index, HeapType *pHeap, int *output, int size, int current);
int preHelp(int index, HeapType *pHeap, int *output, int size, int current);
int postHelp(int index, HeapType *pHeap, int *output, int size, int current);
int getDepth (int size);
int addHeap(HeapType *pHeap, int key);
int findHeap(HeapType *pHeap, int key);
int delHeap(HeapType *pHeap, int *key);

int initHeap (HeapType *pHeap,int size)
{
   int i = 0;
   if(pHeap == NULL)
   {
      return -1;
   }
   pHeap->size = size;
   pHeap->store =(int*)malloc(size*sizeof(int));
   pHeap->end = 0;
   return 0;
}

int findHeap(HeapType *pHeap, int key)
{
   int i = 0;
   if (pHeap == NULL)
   {
      return -1;
   }
   for(i = 0; i <= pHeap->end; i = i+1)
   {
      if((pHeap->store)[i] == key)
      {
         return 1;
      }
   }
   return 0;
}

int delHeap(HeapType *pHeap, int *key)
{
   int *temp;
   int i = 0;
   int index = 0;
   int maxSize = pHeap->end -1;
   int L = 0;
   int R = 0;
   int tempVal;

   temp =(int*)malloc((pHeap->end)*sizeof(int));
   *key = (pHeap->store)[0];
   for(i = 0; i<pHeap->end; i = i+1)
   {
      temp[i] = (pHeap->store)[i+1];
   }
   while(index < maxSize)
   {
      L = (2*index)+1;
      R = (2*index)+2;
      if(L < maxSize && R < maxSize)
      {
         if(temp[L] > temp[R])
         {
            tempVal = temp[L];
            temp[L] = temp[index];
            temp[index] = tempVal;
            index = L;
         }
         else
         {
            tempVal = temp[R];
            temp[R] = temp[index];
            temp[index] = tempVal;
            index = R;
         }
      }
      else if(L < maxSize)
      {
         tempVal = temp[L];
         temp[L] = temp[index];
         temp[index] = tempVal;
         index = L;
      }
      else if(R < maxSize)
      {
         tempVal = temp[R];
         temp[R] = temp[index];
         temp[index] = tempVal;
         index = L;
      }
      else
      {
         break;
      }
   }
   pHeap->store = temp;
   return 0;  
   
}

int addHeap(HeapType *pHeap, int key)
{
   int check = 0;
   int temp = 0;
   int index = pHeap -> end +1;
   int tempVal = 0;
   if(pHeap == NULL)
   {
      return -1;
   }
   if(pHeap->end >= (pHeap->size)-1)
   {
      return -1;
   }
   ((*pHeap).store)[pHeap->end + 1] = key;
   while(check == 0)
   {
      temp = index/2;
      if((pHeap->store)[temp]<key)
      {
         tempVal = (pHeap->store)[temp];
         (pHeap->store)[temp] = key;
         (pHeap->store)[index] = tempVal;    
      }    
      else
      {
         check = 1;
      }
   }
   return 0; 
}
int inorder  (HeapType *pHeap, int **output, int *o_size)
{
   int i = 0;
   int rvalue = 0;
   if(pHeap == NULL)
   {
      return -1;
   }
   if(&(pHeap->store)[0] == NULL)
   {
      return -1;
   }
   else
   {
      *o_size = pHeap->end + 1;
   }
   *output =(int*)malloc((*o_size)*sizeof(int));
   rvalue = inHelp(0, pHeap, *output, pHeap->size, 0);
   return 0;
}

int preorder (HeapType *pHeap, int **output, int *o_size)
{

   int i = 0;
   int rvalue = 0;
   if(pHeap == NULL)
   {
      return -1;
   }
   if(&(pHeap->store)[0] == NULL)
   {
      return -1;
   }
   else
   {
      *o_size = pHeap->end + 1;
   }
   *output =(int*)malloc((*o_size)*sizeof(int));
   rvalue = preHelp(0, pHeap, *output, pHeap->size, 0);
   return 0;
}

int postorder(HeapType *pHeap, int **output, int *o_size)
{
   int i = 0;
   int rvalue = 0;
   if(pHeap == NULL)
   {
      return -1;
   }
   if(&(pHeap->store)[0] == NULL)
   {
      return -1;
   }
   else
   {
      *o_size = pHeap->end + 1;
   }
   *output =(int*)malloc((*o_size)*sizeof(int));
   rvalue = postHelp(0, pHeap, *output, pHeap->size, 0);
   return 0;

}
 
int getDepth(int size)
{
   int counter = 0;
   while(size > 1)
   {
      size = size/2;
      counter = counter + 1;
   }
   if(size != 0)
   {
      counter = counter + 1;
   }
   return counter;
}

int inHelp(int index, HeapType *pHeap, int *output, int size, int current)
{
    int rvalue = 0;
    int temp = (index*2)+1;
    int maxSize  = size-1;
   
    if(pHeap == NULL || output == NULL)
    {
       return -1;
    }
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);  
    }
    
    output[current] = (pHeap->store)[index];
    current = current + 1;

    temp = (index*2)+2;
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);
    } 

    return 0;      
} 

int preHelp(int index, HeapType *pHeap, int *output, int size, int current)
{
    int rvalue = 0;
    int temp = (index*2)+1;
    int maxSize = size-1;

    output[current] = (pHeap->store)[index];
    current = current + 1;

    if(pHeap == NULL || output == NULL)
    {
       return -1;
    }
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);
    }


    temp = (index*2)+2;
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);
    }

    return 0;

}
int postHelp(int index, HeapType *pHeap, int *output, int size, int current)
{
    int rvalue = 0;
    int temp = (index*2)+1;
    int maxSize  = size-1;

    if(pHeap == NULL || output == NULL)
    {
       return -1;
    }
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);
    }

    temp = (index*2)+2;
    if(temp < maxSize)
    {
       rvalue = inHelp(temp, pHeap, output, size, current);
    }

    output[current] = (pHeap->store)[index];
    current = current + 1;

    return 0;
}
