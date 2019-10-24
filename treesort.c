#include <stdio.h>
#include <stdlib.h>
struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;


int printTreeInOrder(bstNode *T);
int add_bst(bstNode **root,int val);


int add_bst(bstNode **root,int val) {
   int rvalue;
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root =(bstNode *)malloc(sizeof(bstNode)); 
      (*root)->val = val;
   } 
   else {
      if (val>(*root)->val)
      {
         rvalue = add_bst(&((*root)->r), val);
         return rvalue;
      }
      else
      {
         rvalue = add_bst(&((*root)->l), val);
         return rvalue;
      }
   }
   return 0;
}

int printTreeInOrder(bstNode *T) {
   if(T == NULL)
   {
      return -1;
   }
   printTreeInOrder(T->l);
   printf("%d\n", T->val);
   printTreeInOrder(T->r);
   return 0;
   }


int main(void) {
   int n=0;
   int value=0;
   int rvalue=0;
   bstNode *input_list=NULL;

   while (scanf("%d",&value) != EOF) {
      n=n+1;
      rvalue = add_bst(&input_list,value);
   }
   printTreeInOrder(input_list);
   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }

   return 0;
}


