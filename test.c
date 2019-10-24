int main(void)
{

   unsigned char pattern = 0xb8;
   unsigned char x = 18;
   unsigned char rvalue;
   int size = 0;
   int i = 0;
   char data[6];
   int *output;

   scanf("%s",data);
   printf("%s\n",data);
   
   rvalue = crypt(data,5,0x9);

   printf("%s\n",data);

   rvalue = crypt(data,5,0x9);

   printf("%s\n",data);

   rvalue =  FSR(x);
   printf("%x\n",rvalue);
   printf("%d\n",rvalue);
   size = convertItoB(&output,9);
   
   for(i=0;i<size;i=i+1)
   {
      printf("%d",output[i]);
   }
   printf("\n");

   rvalue = prng(rvalue,pattern);

   printf("%x\n",rvalue);
   printf("%d\n",rvalue);

   size = convertItoB(&output,177);

   for(i=0;i<size;i=i+1)
   {
      printf("%d",output[i]);
   }
   printf("\n");

}


