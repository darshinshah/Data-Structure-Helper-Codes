#include<iostream>
#include<string>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

node* create(node** front1,node** rear1,int num)
{
    int value;
    if(num==0)
    {
        (*front1)=(*rear1)=NULL;
    }
    while(num!=0)
    {
        cout<<"Enter Data : ";
        cin>>value;

        node* newnode=new node;

        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;

        if((*front1)==NULL)
        {
            (*front1)=newnode;
            (*rear1)=(*front1);
        }
        else
        {
            (*rear1)->next=newnode;
            newnode->prev=(*rear1);
            (*rear1)=newnode;
        }
    num--;
    }

}

void displayreverse(node** front1,node** rear1)
{
    cout<<"\n-----------------------------------------------------------------\n";
    cout<<"The Queue is :\n";
    node* rearcopy=(*rear1);

    if (((*front1) == NULL) && ((*rear1) == NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
    while(rearcopy!=(*front1))
    {
        cout<<rearcopy->data<<"------>";
        rearcopy=rearcopy->prev;
    }
    if(rearcopy==(*front1))
    {
         cout<<rearcopy->data<<"------>";
    }
    }
    cout<<"END\n";
    cout<<"-----------------------------------------------------------------\n";

}

void display(node** front1,node** rear1)
{
    cout<<"\n-----------------------------------------------------------------\n";
    cout<<"The Queue is :\n";
    node* frontcopy=(*front1);

    if (((*front1) == NULL) && ((*rear1) == NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
    while(frontcopy!=(*rear1))
    {
        cout<<frontcopy->data<<"------>";
        frontcopy=frontcopy->next;
    }
    if(frontcopy==(*rear1))
    {
         cout<<frontcopy->data<<"------>";
    }
    }
    cout<<"END\n";
    cout<<"-----------------------------------------------------------------\n";

}

void Enqueue(node** front1,node** rear1,int value)
{
        node* newnode=new node;

        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;

        if((*rear1)==NULL)
        {
            (*front1)=newnode;
            (*rear1)=(*front1);
        }
        else
        {
            (*rear1)->next=newnode;
            newnode->prev=(*rear1);
            (*rear1)=newnode;
        }
}

void Dequeue(node** front1,node** rear1)
{
    node* frontcopy=(*front1);

    if(frontcopy==NULL)
    {
        cout<<"No Element To Delete\n";
        return;
    }
    else
    {
        if(frontcopy->next==NULL)
        {
            cout<<"Dequeued Value is : "<<(*front1)->data<<"\n";
            (*front1)=(*rear1)=NULL;
            delete (frontcopy);
            return;
        }
        else
        {
            cout<<"Dequeued Value is : "<<frontcopy->data<<"\n";
            frontcopy=frontcopy->next;
            frontcopy->prev=NULL;
            (*front1)=frontcopy;
        }
    }

}

int main()
{
    int no;
    int enqueueelements;
    int data;
    int dequeueelements;
    node* front1=NULL;
    node* rear1=NULL;
    cout<<"Enter No Of Elements You Want : ";
    cin>>no;
    create(&front1,&rear1,no);
    displayreverse(&front1,&rear1);
    display(&front1,&rear1);
   //===================================================================================================================
    cout<<"\n\n";
    cout<<"Enter No Of Elements You Want to Enqueue : ";
    cin>>enqueueelements;
    for(int i=0;i<enqueueelements;i++)
    {
        cout<<"Enter Data : ";
        cin>>data;
        Enqueue(&front1,&rear1,data);
    }
    displayreverse(&front1,&rear1);
    display(&front1,&rear1);

    //===================================================================================================================
    cout<<"\n\n";
    cout<<"Enter No Of Elements You Want to Dequeue : ";
    cin>>dequeueelements;
    for(int i=0;i<dequeueelements;i++)
    {
        Dequeue(&front1,&rear1);
    }
    displayreverse(&front1,&rear1);
    display(&front1,&rear1);

}
