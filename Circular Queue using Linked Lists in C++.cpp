#include<iostream>
#include<string>

using namespace std;

struct node
{
    int data;
    node* next;
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
        if((*front1)==NULL)
        {
            newnode->next=newnode;
            (*front1)=newnode;
            (*rear1)=(*front1);
        }
        else
        {
            newnode->next=(*front1);
            (*rear1)->next=newnode;
            (*rear1)=newnode;
        }
    num--;
    }

}

void display(node* front1,node* rear1)
{
    cout<<"\n-----------------------------------------------------------------\n";
    cout<<"The Queue is :\n";

    node* frontcopy=front1;

    if (front1 == NULL && rear1 == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
    while(front1->next!=frontcopy)
    {
        cout<<front1->data<<"------>";
        front1=front1->next;
    }
    if(front1==rear1)
    {
         cout<<front1->data<<"------>";
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

        if((*rear1)==NULL && (*front1)==NULL)
        {
            (*front1)=newnode;
            (*rear1)=(*front1);
            (*front1)->next=(*front1);
        }
        else
        {
            (*rear1)->next=newnode;
            (*rear1)=newnode;
            (*rear1)->next=(*front1);
        }
}

void Dequeue(node** front1,node** rear1)
{
    node* frontcopy=(*front1);

    if(frontcopy==NULL || (*rear1)==NULL)
    {
        cout<<"No Element To Delete\n";
        return;
    }
    else
    {
        if(frontcopy->next==frontcopy)
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
            (*front1)=frontcopy;
            (*rear1)->next=(*front1);
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
    display(front1,rear1);
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
    display(front1,rear1);

    //===================================================================================================================
    cout<<"\n\n";
    cout<<"Enter No Of Elements You Want to Dequeue : ";
    cin>>dequeueelements;
    for(int i=0;i<dequeueelements;i++)
    {
        Dequeue(&front1,&rear1);
    }
    display(front1,rear1);

}
