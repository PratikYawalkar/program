#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int eval(int [],int,int);
void main()
{
    int a[20]={0},i,deg1,s,x;
    
    printf("Enter degree of polynomial equation : \n");
    scanf("%d",&deg1);
    printf("\nEnter your equation (Coefficient only):\n");
    for(i=deg1;i>=0;i--)
    {
        	scanf("%d",&a[i]);
    }

    // printing equation.

    printf("\nEquation : ");
    for(i=deg1;i>=0;i--)
    {
	        if(a[i]>=0)
        	{
            	printf("+");
	        }
	        else
	        {
	            printf("-");
         }

	        printf("%dx^%d",abs(a[i]),i);
    }
    printf("\nEnter value of x :\n");
    scanf("%d",&x);
    s=eval(a,deg1,x);
    printf("Evaluation of polynomial :%d",s);
}
int eval(int a[],int n,int x)
{
    int sum=0,i;
    for(i=0;i<=n;i++)
    {
        sum=sum+(a[i]*pow(x,i));
    }
    return sum;
    
}