#include<iostream>
#include<string>

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
    while(current->next!=NULL)
    {
        ctr++;
        current=current->next;
    }
    return ctr;
}


node* gettail(node* head)
{
    node* tail=head;
    if(head==NULL)
    {
        return NULL;
    }
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    return tail;
}

void displaynext(node* head)
{
    node* current= head;
    if(current==NULL)
    {
        cout<<"\nNo Node to display\n";
    }
    else
    {
    while(current!=NULL)
    {
        cout<<current->data<<"------->"<<" ";
        current=current->next;
    }
    }

    cout<<"END\n";
}

void displayprev(node* head)
{
    node* ptr=gettail(head);
    if(head==NULL)
    {
        cout<<"\nNo Node to display\n";
    }
    else
    {
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"------->"<<" ";
        ptr=ptr->prev;
    }
    }

    cout<<"END\n";
}

node* createbeginning(node* head,int num)
{
    int value;
    node* newnode;
    while(num!=0)
    {
        cout<<"Enter The Data : ";
        cin>>value;
        newnode=new node;
        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->data=value;
            newnode->next=NULL;
            head=newnode;
        }
        else
        {
            newnode->data=value;
            newnode->prev=NULL;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        num--;
    }
    return head;
}


node* createend(node* head,int num)
{
    int value;
    node* newnode;
    while(num!=0)
    {
        cout<<"Enter The Data : ";
        cin>>value;
        newnode=new node;

        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->data=value;
            newnode->next=NULL;
            head=newnode;
        }
        else
        {
            node* ptr=gettail(head);
            newnode->data=value;
            newnode->prev=ptr;
            newnode->next=NULL;
            ptr->next=newnode;
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
        newnodestart->prev=NULL;
        newnodestart->next=NULL;
        head=newnodestart;
        return head;
    }
    newnodestart->data=value;
    newnodestart->next=head;
    head->prev=newnodestart;
    newnodestart->prev=NULL;
    head=newnodestart;
    return head;
}

node* insertend(node* head,int value)
{
    node* newnodeend =new node;
    node* ptr=gettail(head);
    newnodeend->data=value;

    if(head==NULL)
    {
        newnodeend->next=NULL;
        newnodeend->prev=NULL;
        head=newnodeend;
        return head;
    }

    else
    {
    ptr->next=newnodeend;
    newnodeend->prev=ptr;
    newnodeend->next=NULL;
    return head;
    }
}

node* deletestart(node* head)
{
     if(head==NULL || head->next==NULL) //why?? Neeche bhi hai na ???
    {
        cout<<"No Node To Display";
        return NULL;
    }
    else
    {
    node* current=head;
    head=head->next;
    head->prev=NULL;
    delete current;
    }
    return head;
}

node* deleteend(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        cout<<"No Node To Display";
        return NULL;
    }
    node* ptr=gettail(head);
    node* current1=ptr->prev;

    current1->next=NULL;
    delete ptr;
    return head;

}



node* insertspecific(node* head,int value,int pos)
{
    node* newspecific=new node;
    node* current=head;
    node* current1=head;

    newspecific->data=value;
    newspecific->next=NULL;
    newspecific->prev=NULL;

    if(head==NULL)
    {
        head=newspecific;
        return head;
    }

    if(pos==1)
    {
        newspecific->next=current;
        newspecific->prev=NULL;
        head->prev=newspecific;
        head=newspecific;
    }

    else
    {
        while(pos!=1)
        {
        pos--;
        if(current->next==NULL)
        {
        cout<<"You've Entered An Invalid Location for Insertion, Now the data will be added to End of The Linked List\n";
        head=insertend(head,value);
        return head;
        break;
        }
        current1=current;
        current=current->next;
        }

            current->prev=newspecific;
            current1->next=newspecific;
            newspecific->prev=current1;
            newspecific->next=current;
        }


    return head;
}


node* deletespecific(node* head , int pos)
{
    int no=numberofnodes(head);
    //cout<<no;

if(head==NULL)
{
        cout<<"No Node to Delete\n";
        return NULL;
}

else
{
    node* current=head;
    node* current1=head;

    if(pos==no)
    {
        while(current->next!=NULL)
        {
            current1=current;
            current=current->next;
        }
        current1->next=NULL;
        delete current;
    }

    else if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        delete current;
        return head;
    }

    else
    {
    while(pos!=1)
    {
    pos--;
    if(current==NULL || current->next==NULL)
    {
        cout<<"No Node to Delete\n";
        return NULL;
    }
        current1=current;
        current=current->next;
    }
    node* tobedeleted=current;
    current1->next=current->next;
    current=current->next;
    current->prev=current1;
    delete tobedeleted;
    }


}
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
    return head2;
    }

    if(head2==NULL)
    {
        return head;
    }

   else
{

 node* ptr=gettail(head);
 ptr->next=head2;
 ptr=ptr->next;
 ptr->prev=gettail(head);
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
    cout<<"\nEnter The Value to be Searched\n";
    cin>>value;

    while(current->next!=NULL)
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
    int no;
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

    cout<<"Enter The No of Nodes You Want : ";
    cin>>no;
    cout<<"Double Linked List Using Create At Start Function\n";
    head=createbeginning(head,no);


    cout<<"\n\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"The Double Linked List Display Using Next Pointer is : \n";
    displaynext(head);
    cout<<"---------------------------------------------------------------------------\n";

//------------------------------------------------------------------------------------------------------
    cout<<"\n\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"The Double Linked List Display Using Previous Pointer is : \n";
    displayprev(head);
    cout<<"---------------------------------------------------------------------------\n";
//------------------------------------------------------------------------------------------------------

    cout<<"Double Linked List Using Create At End Function\n";
    head=createend(head,no);


    cout<<"\n\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"The Double Linked List Display Using Next Pointer is : \n";
    displaynext(head);
    cout<<"---------------------------------------------------------------------------\n";

//------------------------------------------------------------------------------------------------------
    cout<<"\n\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"The Double Linked List Display Using Previous Pointer is : \n";
    displayprev(head);
    cout<<"---------------------------------------------------------------------------\n";
//------------------------------------------------------------------------------------------------------

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
//------------------------------------------------------------------------------------------------------

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
    displaynext(head); //can also use displayprev(head);
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

    searchll(head);


}
