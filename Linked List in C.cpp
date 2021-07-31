#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
}
*head=NULL;
*head2=NULL;

void display(struct node *head)
{
    struct node* current=head;
    if(current==NULL)
    {
    printf("\nNO NODE TO DISPLAY");
    }
    while(current!=NULL)
    {
        printf("%d-------> ",current->data," ");
        current=current->next;
    }
    printf("END\n");
}

struct node* create(struct node* head,int num)
{
    int value;
    struct node* newnode;
    struct node* current;

    do
    {
    num--;
    newnode=(struct node*)malloc(sizeof(struct node)); //we create memory space here for every iteration

    printf("Enter The Value  "); //we accept the data
    scanf("%d",&value);

    newnode->data=value; //we make the node ready first
    newnode->next=NULL;

    if(head==NULL)
    {
    head=newnode;
    current=head; //current=newnode; is also workable
    }

    current->next=newnode;
    current=newnode;
}
    while(num!=0);
    return head;
}

struct node* insertstart(struct node *head,int value)
{
    struct node* newnodestart=(struct node*)malloc(sizeof(struct node*));
    newnodestart->data=value;
    newnodestart->next=head;
    head=newnodestart;
    return head;
}

struct node* insertend(struct node *head,int value)
{
    struct node* newnodelast=(struct node*)malloc(sizeof(struct node*));
    struct node* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    newnodelast->data=value;
    newnodelast->next=NULL;
    current->next=newnodelast;
    return head;
}

struct node* deletestart(struct node *head)
{
struct node *current;
if(head==NULL)
{
printf("No Node To Delete\n");
}
else
{
current=head;
head=head->next;
}
return head;
}

struct node* insertspecific(struct node *head,int value,int pos)
{
    struct node* newspecific=(struct node*)malloc(sizeof(struct node*));
    struct node* current=head;
    struct node* current1=head;
    if(pos==1)
    {
        newspecific->data=value;
        newspecific->next=current;
        head=newspecific;
    }
    else
    {
    while(pos!=1)
    {
        if(current==NULL)
        {
        printf("You've Entered An Invalid Location for Insertion");
        break;
        }
        pos--;
        current1=current;
        current=current->next;
    }
    newspecific->data=value;
    newspecific->next=current;
    current1->next=newspecific;
}
    return head;
}


struct node* deleteend(struct node *head)
{
struct node *current=head;
struct node *current2=head;

while(current->next!=NULL)
{
current2=current;
current=current->next;
}
current2->next=NULL;
free(current);
return head;
}



struct node* concat(struct node *head,struct node *head2)
{
 struct node* current=head;
 while(current->next!=NULL)
 {
     current=current->next;
 }
 current->next=head2;
 return head;
 }

int main()
{
    int no=0;
    int no1=0;
    int i=0;
    int start=0;
    int startelements=0;
    int endelements=0;
    int end=0;
    int startdelete=0;
    int enddelete=0;
    int specific=0;
    int dataspecific;
    int loc;
    int deletend;
    //..................................................................................................
    printf("\nEnter The No of Nodes You want to Enter  ");
    scanf("%d",&no);
    head=create(head,no);
    printf("------------------------------------------------------------------------------");
    printf("\nCreated Linked List is :\n");
    display(head);
    printf("------------------------------------------------------------------------------");
 //..................................................................................................
    printf("\n\n\nEnter The No of Nodes You want to Add at The start ");
    scanf("%d",&startelements);
    for(i=0;i<startelements;i++)
    {
    printf("Enter The Data you want to Enter at Start  ");
    scanf("%d",&start);
    head=insertstart(head,start);
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("Inserted data At Start Linked List is :\n");
    display(head);
    printf("------------------------------------------------------------------------------");
     //..................................................................................................

    printf("\n\n\nEnter The No of Nodes You want to Add at The End ");
    scanf("%d",&endelements);
    for(i=0;i<endelements;i++)
    {
    printf("Enter The Data you want to Enter at End  ");
    scanf("%d",&end);
    head=insertend(head,end);
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("Inserted data At End Linked List is :\n");
    display(head);
    printf("------------------------------------------------------------------------------");
 //..................................................................................................
    printf("\n\n\nHow many Elements you want to delete from Start\n");
    scanf("%d",&startdelete);
    for(i=0;i<startdelete;i++)
    {
    head=deletestart(head);
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("Delete At Start is : \n");
    display(head);
    printf("------------------------------------------------------------------------------\n");
     //..................................................................................................


    printf("\n\n\nHow many Elements you want to Insert Specifically\n");
    scanf("%d",&specific);

    for(i=0;i<specific;i++)
    {
    printf("Enter The Data \n");
    scanf("%d",&dataspecific);
    printf("Enter The Location \n");
    scanf("%d",&loc);
    head=insertspecific(head,dataspecific,loc);
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("Inserted Data Specifically is  : \n");
    display(head);
    printf("------------------------------------------------------------------------------\n");

 //..................................................................................................

    printf("\n\n\nHow many Elements you want to delete from End\n");
    scanf("%d",&deletend);
    for(i=0;i<deletend;i++)
    {
    head=deleteend(head);
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("Delete At End is : \n");
    display(head);
    printf("------------------------------------------------------------------------------\n");

 //..................................................................................................

    printf("\nEnter The No of Nodes You want to Enter for Second Linked List ");
    scanf("%d",&no1);
    head2=create(head2,no1);
    printf("------------------------------------------------------------------------------");
    printf("\nCreated Linked List is :\n");
    display(head2);
    printf("------------------------------------------------------------------------------");

 //..................................................................................................


    printf("\n\n------------------------------------------------------------------------------");
    printf("\nThe Concatnated Linked List is : \n");
    head=concat(head,head2);
    display(head);
    printf("------------------------------------------------------------------------------");


 //..................................................................................................

}
