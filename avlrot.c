#include <stdio.h>
#include <stdlib.h>
struct avlNode {
   int balance; 
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;


int printTreeInOrder(avlNode *T);
int add_bst(avlNode **root,int val);
int isAVL(avlNode **root);
int findHeight(avlNode *root);
int rotate(avlNode **root, unsigned int Left0_Right1);
int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1);

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1)
{
   int rvalue = 0;
   if(root == NULL || *root == NULL)
   {
      return -1;
   }
   if(MajLMinR0_MajRMinL1 == 0)
   {
      rvalue = rotate(&((*root)->l),0);
      rvalue = rotate(root,1);         
   }
   else if(MajLMinR0_MajRMinL1 == 1)
   {
      rvalue = rotate(&((*root)->r),1);
      rvalue = rotate(root,0);
   }
   else
   {
      return -1;
   }
   return 0; 
}
int rotate(avlNode **root, unsigned int Left0_Right1)
{
   avlNode *temp = NULL;
   temp = (avlNode *)malloc(sizeof(avlNode));
   if(root == NULL || *root == NULL)
   {
      return -1;
   }
   if(Left0_Right1 == 0)
   {
      if((*root)->r == NULL)
      {
         return -1;
      }
      printf("\n rotate left \n");
      temp = *root;
      *root = (*root)->r;
      temp->r = (*root)->l;
      (*root)->l = temp;  
   }
   else if(Left0_Right1 == 1)
   {
      if((*root)->l == NULL)
      {
         return -1;
      }
      printf("\n rotate right \n");
      temp = *root;
      *root = (*root)->l;
      temp->l = (*root)->r;
      (*root)->r = temp;
   }
   else
   {
      return -1;
   }
   return 0;
}

int isAVL(avlNode **root)
{
   int heightDiff = 0;
   if(root == NULL)
   {
      return -1;
   }
   if(*root == NULL)
   {
      return -1;
   }
   heightDiff = findHeight((*root)->r) - findHeight((*root)->l);
   if (heightDiff > 1 || heightDiff < -1)
   {
      return -1;
   }
   return 0;
}

int findHeight(avlNode *root)
{
   int right = 0;
   int left = 0;

   if(root == NULL)
   {
      return 0;
   }
   right = findHeight(root->r);
   left = findHeight(root->l);
   if(left>right)
   {
      return left+1;
   }
   else
   {
      return right+1;
   }
}
int add_avl(avlNode **root,int val) {
   int rvalue;
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root =(avlNode *)malloc(sizeof(avlNode)); 
      (*root)->val = val;
   } 
   else {
      if (val>(*root)->val)
      {
         rvalue = add_avl(&((*root)->r), val);
         return rvalue;
      }
      else
      {
         rvalue = add_avl(&((*root)->l), val);
         return rvalue;
      }
   }
   return 0;
}

int printTreeInOrder(avlNode *T) {
   if(T == NULL)
   {
      return -1;
   }
   printTreeInOrder(T->l);
   printf("%d\n", T->val);
   printTreeInOrder(T->r);
   return 0;
}
