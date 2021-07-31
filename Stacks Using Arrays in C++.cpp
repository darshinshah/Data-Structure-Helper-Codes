#include<iostream>

using namespace std;

int isempty(int top)
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull(int top,int maxi)
{
    if(top==maxi-1)
    {
        return 1;
    }
    else
        return 0;
}

int push(int x[],int maxi,int top)
{
    int value;
    if(isfull(top,maxi)==1)
    {
        cout<<"OverFlow";
    }
    else
    {
        cout<<"Enter The Value : ";
        cin>>value;
        top+=1;
        x[top]=value;
    }
return top;
}

int pop(int x[],int top)
    if(isempty(top)==1)
{
    {
        cout<<"UnderFlow\n";
        return -1;
    }
    else
    {
    int value=0;
    value=x[top];
    cout<<"\nThe Value Popped is : "<<value;
    top-=1;
    }
    return top;
}

void peep(int x[],int top)
{
    cout<<x[top]<<"----->";
}

void display(int x[],int top)
{
    for(int i=top;i>=0;i--)
    {
        peep(x,i);
    }
    cout<<"END";
}

int main()
{
  int stacks[100];
  int maxi;
  int pushelements;
  int popelements;
  int i=0;
  int top=-1;

  cout<<"Enter Maximum no of Array Elements you want to Allocate to The Memory : ";
  cin>>maxi;

  cout<<"How many elements you want to Push : ";
  cin>>pushelements;
  for(i=0;i<pushelements;i++)
  {
      if(pushelements>maxi)
      {
          cout<<"OverFlow\n";
          break;
      }
      else
      {
       top=push(stacks,maxi,top);
      }
  }
  cout<<"The stack is : ";

  display(stacks,top);
  //-------------------------------------------------------

  cout<<"\n\nHow many elements you want to Pop : ";
  cin>>popelements;
  for(i=0;i<popelements;i++)
  {
      if(isempty(top)==1)
      {
          cout<<"\nUnderFlow\n";
          break;
      }
      else
      {
      top=pop(stacks,top);
      }
  }
  cout<<"\n\nThe stack is : ";

  display(stacks,top);
}
