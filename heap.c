typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
   int (*compare)(int x,int y);
} intHeap_T;


int store(intHeap_T *heap,int value);
int retrieve(intHeap_T *heap,int *rvalue);

int store(intHeap_T *heap,int value)
{
   int swapped = 1;
   int indCur = heap->end;
   int index = (heap->end-1)/2;
   int temp = 0;
   if(heap->end >= heap->size)
   {
      return -1;
   }
   if(heap->end == 0)
   {
      (heap->store)[0] = value;
      heap->end = heap->end + 1;
      return 0;
   }
   (heap->store)[heap->end] = value;
   heap->end = heap->end + 1;
   while(swapped == 1)
   {
      swapped = 0;
      if(index < 0)
      {
         break;
      }
      if(heap->compare((heap->store)[index], (heap->store)[indCur]) == 1)
      {
         temp = (heap->store)[index];
         (heap->store)[index] = (heap->store)[indCur];
         (heap->store)[indCur] = temp;
         swapped = 1;
      }
      indCur = index;
      index = (index-1)/2;
   }
   return 0;
}


int retrieve(intHeap_T* heap,int *rvalue)
{

   int swapped = 1;
   int indCur;
   int indL = 1;
   int indR = 2;
   int temp = 0;
   int greatest;
   if(heap->end < 0)
   {
      return -1;
   }
   *rvalue = (heap->store)[0];
   temp = (heap->store)[heap->end-1];
   (heap->store)[heap->end-1] = 0;
   (heap->store)[0] = temp;
   heap->end = heap->end-1;
   indCur = 0;
   while(swapped == 1)
   {
      swapped = 0;
      if(indR < 0 || indL < 0)
      {
         break;
      }
      if(indL >= heap->end && indR >= heap->end)
      {
         break;
      }
      else if(indL >= heap->end)
      {
         greatest = indR;
      }
      else if(indR >= heap->end)
      {
         greatest = indL;
      }
      else
      {
         if(heap->compare((heap->store)[indL],(heap->store)[indR])==1)
         {
            greatest = indR;
         }
         else
         {
            greatest = indL;
         }
      }
      if(heap->compare((heap->store)[indCur], (heap->store)[greatest])  == 1)
      {
         temp = (heap->store)[greatest];
         (heap->store)[greatest] = (heap->store)[indCur];
         (heap->store)[indCur] = temp;
         swapped = 1;
      }
      indCur = greatest;
      indL = (greatest*2)+1;
      indR = (greatest*2)+2;
   }
   return 0;
}



