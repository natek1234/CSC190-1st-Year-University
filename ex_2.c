#include <stdio.h>

int add_to_end(intlist *l,int val);
int add_to_start(intlist *l,int val);
int insert_after(intlist *l,int insert_val,int val);
int init(intlist *l, int len);

typedef struct intlist {

   int *x;
   int end;
   int len;

};

int init(intlist *l,int len) {

   if (l==NULL) { return -1; }

   (l->x) = (int *)malloc(len * sizeof(int));

   if ((l->x) == NULL) { return -1; }

   l->end = -1;
   l->len=len;
   return 0;
}

int add_to_end(intlist *l,int val)
{
   if(l==NULL) { return -1; }
   int *n = NULL;
   int i = 0;

   n  = (int*)malloc(((l->len)+1)*sizeof(int));
   for(i = 0; i < l->len; i = i+1)
   {
      n[i] = (l->x)[i];
   }
   n[l->len] = val;
   l->len = (l->len) + 1;
   l->x = n;
   
   return 0;
   
}

int add_to_start(intlist *l,int val)
{
   if(l==NULL) { return -1; }
   int *n = NULL;
   int i = 0;

   n  = (int*)malloc(((l->len)+1)*sizeof(int));
   n[0] = val;
   for(i = 0; i < l->len; i = i+1)
   {
      n[i+1] = (l->x)[i];
   }
   l->x = n;
   l->len = (l->len) + 1;

   return 0;

}

int insert_after(intlist *l,int insert_val,int val)
{
   if(l==NULL) { return -1; }
   
   int *n = NULL;
   int i = 0;
   int found = 0;

   n =(int*)malloc(((l->len)+1)*sizeof(int));
   for(i=0; i < l->len; i = i + 1)
   {
      if((l->x)[i] == insert_val && found != 1)
      {
         n[i] = (l->x)[i];
         n[i+1] = val;
         found = 1;  
      }
      else if(found == 1)
      {
         n[i+1] = (l->x)[i];
      }
      if(found == 0)
      {
         n[i] = (l->x)[i];
      }
   }
   l->x = n;
   l->len = (l->len) + 1;
   return 0;
}

int push(intlist *l, int val)
{
   int rvalue = 0;
   if(l==NULL) { return -1; }
   
   rvalue = add_to_end(l, val);
   return rvalue;
   
}

int pop(intlist*l, int *returnVal)
{
   int *n = NULL;
   int rvalue = 0;
   int i = 0;
   
   if(l==NULL){ return -1; }
   
   n = (int*)malloc(((l->len)-1)*sizeof(int));
   *returnVal = (l->x)[l->len-1]
   for(i = 0; i < (l->len) -1; i = i+1)
   {
      n[i] = (l->x)[i];
   }
   return 0;
}

  
