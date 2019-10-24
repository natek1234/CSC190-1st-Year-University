#include <stdio.h>
#include <stdlib.h>
unsigned char prng(unsigned char x, unsigned char pattern);
unsigned char FSR(unsigned char x);
int convertItoB(int **output, int input);

int convertItoB(int **output, int input)
{
   int temp;
   int remainder;
   int size = 0;
   int count = 0;
   
   temp = input;
   while(temp>0)
   {
      remainder = temp%2;
      temp = temp/2;
      size = size + 1;
   }

   *output =(int*)malloc(size*sizeof(int));
   
   if(size == 1)
   {
      (*output)[0] = input%2;
      return size;
   }  
   temp = input;
   for(count = 0;count<size;count=count+1)
   {
      remainder = temp%2;
      temp = temp/2;
      (*output)[count] = remainder; 
   }    
   return size;

}

unsigned char FSR(unsigned char x) {
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   return r;
}

unsigned char prng(unsigned char x, unsigned char pattern) 
{
   unsigned char val;
   val = x ^ pattern;
   return val;
}

int crypt(char *data,unsigned int size,unsigned char password)
{
   unsigned char prngVal = password;
   int i = 0;
   unsigned char new;
   if(password == 0)
   {
      return -1;
   }
   for(i=0;i<size;i=i+1)
   {
      prngVal = prng(prngVal,0xb8);
      data[i] = data[i] ^ prngVal;  
   }
   return 0;
}
