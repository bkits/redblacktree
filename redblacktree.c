//2014509
#include"rbt.h"
#include"errors.h"
#include<stdio.h>
#include<stdlib.h>


main()
{
int c,type=4;
void *status;c='*';
printf("\n select data type for the tree");

while(type<0 || type>3)
{
printf("\n (0) integer\n (1) float\n (2) double \n (3) character\n");
type=inputi();
}

 while (c!=0)
 {printf("\n Insert (1), Delete (2), Print (3),Quit (0)\n");
 c=inputi();
 switch(c)
{
 case 1:
   do_insert(type);break;
  case 2:
   do_delete(type);break;
  case 3:
   do_print(type);break;
 }
}
}
