#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
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

node* createbeginning(node* head,int num)
{
    int value;
    node* newnode;

    if(num==0)
    {
        return NULL;
    }

    while(num!=0)
    {
        cout<<"Enter The Data : ";
        cin>>value;
    newnode=new node;
    newnode->data=value;

    if(head==NULL)
    {
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;
    }
    else
    {
        node* ptr=gettail(head);
        newnode->next=head;
        newnode->prev=ptr;
        head->prev=newnode;
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

    if(num==0)
    {
        return NULL;
    }

    while(num!=0)
    {
        cout<<"Enter The Data : ";
        cin>>value;
    newnode=new node;
    newnode->data=value;

    if(head==NULL)
    {
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;
    }
    else
    {
        node* ptr=gettail(head);
        newnode->next=head;
        newnode->prev=ptr;
        head->prev=newnode;
        ptr->next=newnode;
    }
    num--;
}
return head;
}

void displaynext(node* head)
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

void displayprev(node* head)
{
    node* current= gettail(head);
    node* tail=gettail(head);

    if(head==NULL)
    {
        cout<<"\nNo Node to display\n";
    }
    else
    {
    while(current->prev!=tail)
    {
        cout<<current->data<<"------->"<<" ";
        current=current->prev;
    }
    cout<<current->data<<"------->"<<" ";

    cout<<"END\n";
    }
}

node* insertstart(node* head,int value)
{
    node* newnodestart =new node;
    newnodestart->data=value;
    if(head==NULL)
    {
        newnodestart->next=newnodestart;
        newnodestart->prev=newnodestart;
        head=newnodestart;
    }
    else
    {
    node* ptr=gettail(head);
    newnodestart->next=head;
    newnodestart->prev=ptr;
    head->prev=newnodestart;
    ptr->next=newnodestart;
    head=newnodestart;
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
        newnodeend->prev=newnodeend;
        head=newnodeend;
    }
    else
    {
        head->prev=newnodeend;
        newnodeend->next=head;
        newnodeend->prev=ptr;
        ptr->next=newnodeend;
    }
    return head;
}

node* deletestart(node* head)
{
    int no=numberofnodes(head);
    if(no==1)
    {
        return NULL;
    }
    if(head==NULL)
    {
        return NULL;
    }

    else
    {
    node* headcopy=head;
    node* ptr=gettail(head);
    head=head->next;
    ptr->next=head;
    head->prev=ptr;
    delete headcopy;
    }
    return head;
}

node* insertspecific(node* head,int value,int pos)
{
    int no=numberofnodes(head);

    if(pos>no+1)
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
        newspecific->next=newspecific;
        newspecific->prev=newspecific;
        head=newspecific;
        return head;
    }

    else if(pos==1)
    {
        node* ptr=gettail(head);
        newspecific->next=head;
        head->prev=newspecific;
        newspecific->prev=ptr;
        ptr->next=newspecific;
        head=newspecific;
        return head;

    }
    if(pos==no+1)
    {
        node* ptr=gettail(head);
        ptr->next=newspecific;
        newspecific->prev=ptr;
        newspecific->next=head;
        head->prev=newspecific;
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
        current->prev=newspecific;
        newspecific->next=current;
        current1->next=newspecific;
        newspecific->prev=current1;
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

    if(head==NULL)
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
        head->prev=ptr;
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
    current->next->prev=current1;
    delete current;
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
    head->prev=current1;
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
    head2->prev=ptr;
    return head2;
    }

    else if(head2==NULL)
    {
        node* ptr1=gettail(head);
        ptr1->next=head;
        head->prev=ptr1;
        return head;
    }

    else
    {
    node* ptr=gettail(head2);
    node* current=head;
    current->prev=ptr;
    ptr->next=current;
    node* ptr2=gettail(head);
    ptr2->next=head2;
    head2->prev=ptr2;
    return head;
    }

}

node* searchll(node* head) //using tail
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
//..........................................................................................................
    cout<<"Create Linked List Using Create At Beginning  : \n";
    head=createbeginning(head,no);
    cout<<"\n\n";
    cout<<"Display Using Next Pointer : \n";
    displaynext(head);
    cout<<"Display Using Previous Pointer : \n";
    displayprev(head);
//..........................................................................................................
    cout<<"\n\nCreate Linked List Using Create At End  : \n";
    head=createend(head,no);
    cout<<"\n\n";
    cout<<"Display Using Next Pointer : \n";
    displaynext(head);
    cout<<"Display Using Previous Pointer : \n";
    displayprev(head);
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
    displaynext(head); //can also use displayprev(head);
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
    displaynext(head); //can also use displayprev(head);
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
    displaynext(head); //can also use displayprev(head);
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
    displaynext(head);  //can also use displayprev(head);
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
    displaynext(head); //can also use displayprev(head);
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
    displaynext(head); //can also use displayprev(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n\nEnter The No of Nodes You want to Enter in the Second Linked List ";
    cin>>no1;
    head2=createend(head2,no1);
    cout<<"------------------------------------------------------------------------------";
    cout<<"\nSecond Created Linked List is :\n";
    displaynext(head2); //can also use displayprev(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n\n------------------------------------------------------------------------------";
    cout<<"\nThe Concatnated Linked List is : \n";
    head=concat(head,head2);
    displaynext(head); //can also use displayprev(head);
    cout<<"------------------------------------------------------------------------------";

//..........................................................................................................

    cout<<"\n";
    searchll(head);


}

