#include "avlrot.h"
#include <stdio.h>
int main(void)
{
   int rvalue = 0;
   avlNode *root=NULL;
   add_avl(&root,5);
   add_avl(&root,3);
   add_avl(&root,1);
   add_avl(&root,4);
   add_avl(&root,7);
   add_avl(&root,6);
   add_avl(&root,8);
   printTreeInOrder(root);
   rvalue = rotate(&root, 0);
   printf("\n After left rotation \n");
   printTreeInOrder(root);
   rvalue = rotate(&root, 1);
   printf("\n After right rotation \n");
   printTreeInOrder(root);
   return 0;
}
