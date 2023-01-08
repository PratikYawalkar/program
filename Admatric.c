#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct n
{
    int data;
    struct n *link;
};

typedef struct n NODE;
NODE *getnode(int);
NODE *findlast(NODE *);
void display(NODE *[]);

# define V 100
int adj[V][V];
int n;

void init()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
}

void addEdge()
{
    int i,max_edges,u,v;
    max_edges = n*(n-1)/2;
    
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter edge [%d] (-1 -1 to quit): ",i);
        scanf("%d%d",&u,&v);

        if((u==-1)&&(v==-1))
        {
            break;
        }
        else if(u>=n || v>=n || u<0 || v<0)
        {
            printf("Invalid vertex\n");
            i--;
        }
        else
        {
            adj[u][v]=1;    
            adj[v][u]=1;
            
        }
    }
}

void printadjmatrix()
{
    int i,j;
    printf("\nAdjacency matrix :\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    NODE *ptr,*temp,*h[10];
    int i,j;
    printf("Enter number of vertices :\n");
    scanf("%d",&n);

    init();
    addEdge();
    printadjmatrix();

    for(i=0;i<n;i++)
    {
        h[i]=NULL;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==1)
            {
                temp=getnode(j);
                if(h[i]==NULL)
                {
                    h[i]=temp;
                }
                else
                {
                ptr=findlast(h[i]);
                ptr->link=temp;
                }
            }
        }
    }

    printf("\nAdjacency list :\n");
    display(h);
    return 0;
}

NODE *getnode(int j)
{
    NODE * temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=j;
    temp->link=NULL;
    return(temp);
}

NODE *findlast(NODE *h)
{
    NODE *ptr;
    for(ptr=h;ptr->link!=NULL;ptr=ptr->link);
    return(ptr);
}

void display(NODE *h[10])
{
    NODE *ptr;
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n V%d ",i);
        ptr=h[i];
        if(ptr==NULL)
        printf(" NULL");
        while(ptr!=NULL)
        {
            printf(" ->V%d",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
