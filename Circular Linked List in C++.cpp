#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

int numberofnodes(node* head)
{
    int ctr=1;
    if(head==NULL)
    {
        return 0;
    }
    node* current=head;
    while(current->next!=head)
    {
        ctr++;
        current=current->next;
    }
    return ctr;
}


node* gettail(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    return tail;
}


void display(node* head)
{
    node* current= head;
    if(head==NULL)
    {
        cout<<"\nNo Node to display\n";
    }
    else
    {
    while(current->next!=head)
    {
        cout<<current->data<<"------->"<<" ";
        current=current->next;
    }
    cout<<current->data<<"------->"<<" ";

    cout<<"END\n";
    }
}

node* createbeginning(node* head,int num)
{
    int value;
    node* newnode;
    node* ptr;

    if(num==0)
    {
        return NULL;
    }
    while(num!=0)
    {
        cout<<"Enter Data : \n";
        cin>>value;
        newnode = new node;
        newnode->data=value;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else
        {
        ptr=gettail(head);
        newnode->next=head;
        head=newnode;
        ptr->next=head;
        }
        num--;
    }
    return head;

}


node* createend(node* head,int num)
{
    int value;
    node* newnode;
    node* ptr;

    if(num==0)
    {
        return NULL;
    }
    while(num!=0)
    {
        cout<<"Enter Data : \n";
        cin>>value;
        newnode = new node;
        newnode->data=value;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else
        {
        ptr=gettail(head);
        ptr->next=newnode;
        newnode->next=head;
        }
        num--;
    }

    return head;
}

node* insertstart(node* head,int value)
{

    node* newnodestart =new node;
    newnodestart->data=value;
    if(head==NULL)
    {
        head=newnodestart;
        head->next=head;
    }
    else
    {
    node* ptr=gettail(head);
    newnodestart->next=head;
    head=newnodestart;
    ptr->next=head;
    }

    return head;
}


node* insertend(node* head,int value)
{
    node* newnodeend =new node;
    node* ptr=gettail(head);
    newnodeend->data=value;

    if(head==NULL)
    {
        newnodeend->next=newnodeend;
        head=newnodeend;
        return head;
    }
    else
    {
    ptr->next=newnodeend;
    newnodeend->next=head;
    }
    return head;
}

node* deletestart(node* head)
{
    if(head==NULL)
    {
        cout<<"No Node To Display";
        return NULL;
    }
    else
    {
    node* headcopy=head;
    node* ptr=gettail(head);
    head=head->next;
    ptr->next=head;
    delete headcopy;
    }
    return head;
}

node* deleteend(node* head)
{
    if(head==NULL || head->next==head)
    {
        cout<<"No Node To Display";
        return NULL;
    }

    node* current=gettail(head);
    node* current1=head;

    while(current1->next!=current)
    {
        current1=current1->next;
    }

    current1->next=head;
    delete current;
    return head;

}

node* insertspecific(node* head,int value,int pos)
{
    int no=numberofnodes(head);
    if(pos>no)
    {
    cout<<"No Insertion Possible\n";
    return head;
    }
    node* newspecific=new node;
    node* current=head;
    node* current1=head;
    node* ptr=gettail(head);

    newspecific->data=value;

    if(head==NULL)
    {
        head=newspecific;
        head->next=head;
        return head;
    }

    else if(pos==1)
    {
        node* ptr=gettail(head);
        newspecific->next=head;
        ptr->next=newspecific;
        head=newspecific;
        return head;
    }
    else
    {
        while(pos!=1)
        {
        pos--;
        current1=current;
        current=current->next;
        }
        current1->next=newspecific;
        newspecific->next=current;
    }

    return head;
}

node* deletespecific(node* head , int pos)
{
    int no=numberofnodes(head);
    if(pos>no || pos<0)
    {
        cout<<"No Deletion Possible \n";
        return head;
    }
    if(head==NULL || head->next==head)
    {
        cout<<"No Node to Delete\n";
        return NULL;
    }

    node* current=head;
    node* current1=head;

    if(pos==1)
    {
        node* ptr=gettail(head);
        head=head->next;
        ptr->next=head;
        delete current;
        return head;
    }

    while(pos!=1)
    {
        pos=pos-1;
        current1=current;
        current=current->next;
    }

    current1->next=current->next;
    delete current;
    return head;
}

node* concat(node *head,node *head2)
{
    if(head==NULL && head2==NULL)
    {
        return NULL;
    }

    if(head==NULL)
    {
    node* ptr=gettail(head2);
    ptr->next=head2;
    return head2;
    }

    else if(head2==NULL)
    {
        node* ptr1=gettail(head);
        ptr1->next=head;
        return head;
    }

    else
    {
    node* current=head;
    node* ptr2=gettail(head);
    ptr2->next=head2;
    node* ptr3=gettail(head2);
    ptr3->next=head;
    return head;
 }

}

node* searchll(node* head)
{

if(head==NULL)
{
    cout<<"No Element Found\n";
    return NULL;
}
    node* current=head;
    int value=0;
    int pos=0;
    int ctr=0;
    cout<<"Enter The Value to be Searched\n";
    cin>>value;

    while(current->next!=head)
    {
        pos++;
        if(current->data==value)
        {
            ctr++;
            cout<<"The Data is Found at Position : "<<pos<<"\n";
        }
        current=current->next;

    }
    if(current->data==value)
    {
        ctr++;
        pos++;
        cout<<"The Data is Found at Position : "<<pos<<"\n";
    }
    if(ctr==0)
    {
        cout<<"Element Not Found";
    }
}



int main()
{
    int no=0;
    int no1=0;
    int i=0;
    int start=0;
    int startelements=0;
    int endelements=0;
    int endinsert=0;
    int delspecific=0;
    int startdelete=0;
    int enddelete=0;
    int specific=0;
    int dataspecific;
    int loc=0;
    int location=0;
    int deletend;

    node* head=NULL;
    node* head2=NULL;

    cout<<"Enter No of Elements you want : ";
    cin>>no;
    cout<<"\n\n";
    cout<<"Create Linked List Using Create At Beginning  : \n";
    head=createbeginning(head,no);
    cout<<"\n\n";
    display(head);
    cout<<"\n\nCreate Linked List Using Create At End  : \n";
    head=createend(head,no);
    cout<<"\n\n";
    display(head);

    //..........................................................................................................

    cout<<"\n\n\nEnter The No of Nodes You want to Add at The start ";
    cin>>startelements;
    for(i=0;i<startelements;i++)
    {
    cout<<"Enter The Data you want to Enter at Start";
    cin>>start;
    head=insertstart(head,start);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Inserted data At Start Linked List is :\n";
    display(head);
    cout<<"------------------------------------------------------------------------------";
 //..........................................................................................................

    cout<<"\n\n\nEnter The No of Nodes You want to Add at The End ";
    cin>>endelements;
    for(i=0;i<endelements;i++)
    {
    cout<<"Enter The Data you want to Enter at End";
    cin>>endinsert;
    head=insertend(head,endinsert);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Inserted data At End of Linked List is :\n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n\nEnter The No of Nodes You want to Delete at The Start ";
    cin>>startdelete;
    for(i=0;i<startdelete;i++)
    {
        head=deletestart(head);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Deleted data At Start of Linked List is :\n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................


    cout<<"\n\n\nHow many Elements you want to Insert Specifically ";
    cin>>specific;
    for(i=0;i<specific;i++)
    {
    cout<<"Enter The Data \n";
    cin>>dataspecific;
    cout<<"Enter The Location \n";
    cin>>loc;
    head=insertspecific(head,dataspecific,loc);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Inserted Data Specifically is  : \n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n\nHow many Elements you want to Delete Specifically ";
    cin>>delspecific;
    for(i=0;i<delspecific;i++)
    {
    cout<<"Enter The Location \n";
    cin>>location;
    head=deletespecific(head,location);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Deleted Data Specifically is  : \n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................


    cout<<"\n\n\nEnter The No of Nodes You want to Delete at The End ";
    cin>>enddelete;
    for(i=0;i<enddelete;i++)
    {
        head=deleteend(head);
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"Deleted data At End of Linked List is :\n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n\nEnter The No of Nodes You want to Enter in the Second Linked List ";
    cin>>no1;
    head2=createend(head2,no1);
    cout<<"------------------------------------------------------------------------------";
    cout<<"\nSecond Created Linked List is :\n";
    display(head2);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n------------------------------------------------------------------------------";
    cout<<"\nThe Concatnated Linked List is : \n";
    head=concat(head,head2);
    display(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n";
    searchll(head);
}

