#include<iostream>
#include<string>

using namespace std;

struct node
{
    int data;
    node* next;
};

void display(node* head)
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

node* create(node* head,int num)
{
 int value;
 struct node* newnode;
 struct node* current;

 if(num==0)
 {
     return NULL;
 }

 do
 {
  num--;
  newnode=new node;

  cout<<"Enter The Value  ";
  cin>>value;

  newnode->data=value;
  newnode->next=NULL;

  if(head==NULL)
  {
      head=newnode;
      current=head;
  }
  else
  {
   current->next=newnode;
   current=newnode;
  }
 }
  while(num!=0);
  return head;
}

node* insertstart(node* head,int value)
{
    node* newnodestart =new node;
    newnodestart->data=value;
    newnodestart->next=head;
    head=newnodestart;
    return head;
}

node* insertend(node* head,int value)
{
    node* newnodeend =new node;
    node* current=head;
    newnodeend->data=value;
    newnodeend->next=NULL;

    if(head==NULL)
    {
        head=newnodeend;
        return head;
    }

else
    {
    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=newnodeend;
    return head;
    }
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
    node* current=head;
    head=head->next;
    delete current;
    }
    return head;
}

node* deleteend(node* head)
{
    if(head==NULL)
    {
        cout<<"No Node To Display";
        return NULL;
    }
    node* current=head;
    node* current1=head;

    while(current->next!=NULL)
    {
        current1=current;
        current=current->next;
    }

    current1->next=NULL;
    delete current;
    return head;

}


node* insertspecific(node* head,int value,int pos)
{
    node* newspecific=new node;
    node* current=head;
    node* current1=head;
    newspecific->data=value;
    newspecific->next=NULL;

    if(head==NULL)
    {
        head=newspecific;
        return head;
    }


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
        pos--;
        if(current==NULL)
        {
        cout<<"You've Entered An Invalid Location for Insertion, Now the data will be added to End of The Linked List";
        break;
        }
        current1=current;
        current=current->next;
        }

            newspecific->data=value;
            current1->next=newspecific;
            newspecific->next=current;
        }


    return head;
}

node* deletespecific(node* head , int pos)
{
    if(head==NULL)
    {
        cout<<"No Node to Delete\n";
        return NULL;
    }

    node* current=head;
    node* current1=head;

    if(pos==1)
    {
        head=head->next;
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
    if(head==NULL)
    {
    return head2;
    }

    if(head2==NULL)
    {
        return head;
    }

    if(head==NULL && head2==NULL)
    {
        return NULL;
    }

    else
{


 node* current=head;
 while(current->next!=NULL)
 {
     current=current->next;
 }
 current->next=head2;
 return head;
 }

}


node* searchll(node* head)
{
    node* current=head;
    int value=0;
    int pos=0;
    int ctr=0;
    cout<<"Enter The Value to be Searched\n";
    cin>>value;

    while(current!=NULL)
    {
        pos++;
        if(current->data==value)
        {
            ctr++;
            cout<<"The Data is Found at Position : "<<pos<<"\n";
        }
        current=current->next;

    }
    if(ctr==0)
    {
        cout<<"Element Not Found";
    }
}


int main()
 {

     node* head = new node;
     head=NULL;
     node* head2 = new node;
     head2=NULL;

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

//..........................................................................................................
    cout<<"\nEnter The No of Nodes You want to Enter  ";
    cin>>no;
    head=create(head,no);
    cout<<"------------------------------------------------------------------------------";
    cout<<"\nCreated Linked List is :\n";
    display(head);
    cout<<"------------------------------------------------------------------------------";

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

    cout<<"\n\n\nEnter The No of Nodes You want to Enter in the Second Linked List ";
    cin>>no1;
    head2=create(head2,no1);
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




