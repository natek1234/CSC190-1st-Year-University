#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_head(llnode **x, char value);
int push(llnode **x, char value);
int pop(llnode **x, char *return_value);

int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
	 return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
	 return 0;
      }
   }
}

int llnode_add_to_head(llnode **x, char value)
{
   llnode *old_head;
   if (x==NULL) { return -1; }
   if (*x==NULL) {
   *x = (llnode *) malloc(sizeof(llnode));
   (*x)->value = value;
   (*x)->next = NULL;
   return 0;
   }
   else 
   {
      old_head = *x;
      *x =(llnode*)malloc(sizeof(llnode));
      (*x)-> value = value;
      (*x)-> next = old_head;
      return 0;
   }
} 

int push(llnode **x, char value)
{  
   if(x==NULL) { return -1; }
   return llnode_add_to_head(x,value);
}        


int pop(llnode **x, char *return_value)
{  
   llnode *old_head;
   if(x==NULL) { return -1; }
   *return_value = (*x)->value;
   old_head = *x;
   *x = (*x)->next; 
   free(old_head);
   return 0;   
}
int main(void) {
   int n=0;
   int x=0;
   char value;
   int rvalue = 0;
   char returnVal;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      push(&input_list,value);
   }
   printf("INFO: you entered %d items\n",n);
   for(x = 0; x < n; x = x+ 1)
   {
   rvalue = pop(&input_list, &returnVal);
   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
   printf("%c\n",returnVal);
   }
   return 0;
}

