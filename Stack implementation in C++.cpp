#include<iostream>

using namespace std;

void createstack(int x[],int num,int *maxi,int *top)
{
    if(num==0)
    {
        *top=-1;
        cout<<"Invalid, No Stack To Create\n";
    }
    else if(*top==*maxi-1)
    {
        cout<<"Stack Full";
    }
    else
        if(num>*maxi)
    {
        cout<<"Invalid";
    }
    else
    {
    int i=0;
    cout<<"Enter Values for Stack\n";
    for(i=0;i<num;i++)
    {
        cin>>x[i];
        (*top)++;
    }
    }
    }


int peep (int x[],int top)
{
    return x[top];
}

void push(int x[],int value,int *maxi,int *top)
{
    if(*top==*maxi-1)
    {
        cout<<"OverFlow";
    }
    else
    {
        (*top)++;
        x[(*top)]=value;
    }

}


int pop(int x[],int *maxi, int *top)
{
    int value=0;
    if((*top)==-1)
    {
        cout<<"UnderFlow";
    }
    else
    {
        value=x[(*top)];
        (*top)=(*top)-1;
    }

    return value;

}
void displaystack(int x[],int *top)
{
    int i=0;
    for(i=(*top);i>-1;i--)
    {
    cout<<peep(x,i)<<"----->";
    }
    cout<<"END";
}


int main()
{
int top=-1;
int maxi;
int a[100];
int n;
int i=0;
int value;

cout<<"Enter Maximum No of elements you want";
cin>>maxi;
cout<<"\n";
cout<<"Enter No of Elements you want to add now ";
cin>>n;
cout<<"\n";
createstack(a,n,&maxi,&top);
cout<<"\n";
cout<<"The Stack Is :\n";
displaystack(a,&top);
cout<<"\n";

cout<<"\nPushed Element on Stack is :";

push(a,10,&maxi,&top);
cout<<"\n";
displaystack(a,&top);
cout<<"\n";
value=pop(a,&maxi,&top);
cout<<"\nPopped Value is : "<<value;
cout<<"\n";
cout<<"\nRemaining Stack is : \n";
displaystack(a,&top);

}
