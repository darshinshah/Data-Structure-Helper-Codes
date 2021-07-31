#include<iostream>

using namespace std;


struct node
{
    int data;
    node* next;
};

void display(node* top)
{
    node* current= top;
    if(current==NULL)
    {
        cout<<"\nNo Node to display\n";
    }
    while(current!=NULL)
    {
        cout<<current->data<<"------->"<<" ";
        current=current->next;
    }

    cout<<"END\n";
}

int isempty(node* top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
        return 0;
}

node* push(node* top)
{
    node* newtop=new node;
    int value;
    cout<<"Enter The value\n";
    cin>>value;

    newtop->data=value;
    newtop->next=NULL;

    if(top==NULL)
    {
       top=newtop;
       return top;
    }
    else
    {
       newtop->next=top;
       top=newtop;
       return top;
    }

}
void peep(node* top)
{
    if(top==NULL)
    {
        cout<<"No Node To Peep";
    }
    else
    {
    cout<<"The Peeped Value is : "<<top->data;
    }

}

node* pop(node* top)
{
    if(isempty(top)==1)
    {
        cout<<"\nNo Node To Pop left";
        return NULL;
    }
    else
    {
    int value;
    node* current=top;
    value=top->data;
    cout<<"\nThe Popped Value is : "<<value;
    top=top->next;
    delete current;
    return top;
    }
}
int main()
{
    int n;
    int n1;
    int i;
    int popp;
    node* top=new node;
    top=NULL;

    cout<<"How Many Elements You want to Push : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        top=push(top);
    }
    cout<<"\n----------------------------------------------------------------------------------\n";
    display(top);
    cout<<"----------------------------------------------------------------------------------\n\n";

    peep(top);



    cout<<"\n\nHow Many Elements You want to Pop :  ";
    cin>>n1;
    for(i=0;i<n1;i++)
    {
        top=pop(top);
    }
    cout<<"\n----------------------------------------------------------------------------------\n";
    cout<<"Remaining Stack is : ";
    display(top);
    cout<<"----------------------------------------------------------------------------------\n\n";

}
