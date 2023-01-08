#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1, i;
char stack[50];char array1[50];char array2[50];

void reverse();
void main()
{
    printf("Enter string:\n");
    fgets(array1,sizeof(array1),stdin);

    for(i=0;array1[i]!='\0';i++)
    {
        top=top+1;
        stack[top]=array1[i];
    }
    reverse();

    printf("\n\nReversed String :\n");
    puts(array2);
}

void reverse()
{
    for(i=0;top>0;i++)
    {
        top=top-1;
        array2[i]=stack[top];
    }
}