//2014509
#include"errors.h"
#include<stdio.h>




int inputi() //diabasma kai epali8eusi enos akeraiou apo to xristi
{int a1,a2,r;
a2=scanf("%d",&a1);getchar();
while(a2!=1) 
{printf("prepei na einai ari8mos\n");
a2=scanf(" %d",&a1);while((r = getchar()) != '\n');
}
/*
while (a1<=0)
{printf("prepei na einai 8etikos ari8mos\n");
 a1=input_dim();
}
*/
return a1;
}



char inputc() //diabasma kai epali8eusi enos character apo to xristi
{int a2,r;char a1;
a2=scanf("%c",&a1);getchar();
while(a2!=1) 
{printf("prepei na einai character\n");
a2=scanf(" %c",&a1);while((r = getchar()) != '\n');
}
/*
while (a1<=0)
{printf("prepei na einai 8etikos ari8mos\n");
 a1=input_dim();
}
*/
return a1;
}


