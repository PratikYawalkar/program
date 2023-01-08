#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node * prev,*next;
};
struct node *head=NULL;

struct node * cn()
{
    struct node * n;
    n=(struct node *)malloc(sizeof(struct node));
    return (n);
}

void createnode()
{
    int i,n,x;
    struct node *temp,*newnode;
    printf("Enter size of linked list:\n");
    scanf("%d",&n);
    printf("Enter elements of linked list:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(head==NULL)
        {
            head=cn();
            head->data=x;
            head->next=head;
            head->prev=head;
            temp=head;
        }
        else
        {
            newnode=cn();
            newnode->data=x;
            newnode->prev=temp;
            newnode->next=head;
            temp->next=newnode;
            head->prev=newnode;
            temp=newnode;
        }
        
    }

}


void display()
{
    struct node * temp;
    printf("\n");
    if(head==NULL)
    {
        printf("List is empt.\n");   
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
     

void main()
{
    int choice,a=0;
    while(choice!=3)
    {
        printf("\n\n1. Create Linked list.\n");
        printf("2. Display.\n");
        printf("3. Exit.\n\n");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1: if(a==1)
                    {
                        printf("You have already created a Linked list.\n");
                    }
                 else
                    {   createnode();
                        a++;
                    }
                    break;

            case 2: display();
                    break;

            case 4: exit(0);

            defalut: printf("Enter a valid choice\n");
        }
    }
}