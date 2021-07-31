#include<string>
#include<iostream>

using namespace std;

void takedata(int x[],int m);
void showdata(int x[],int m);
void insertion (int x[],int len);


void takedata(int x[],int m)
{
    for(int i=0; i<m; i++)
    {
      cin>>x[i];
    }
}

void showdata(int x[],int m)
{
    for(int i=0; i<m; i++)
    {
      cout<<x[i]<<"\n";
    }
}


void insertion (int x[],int len)
{
    int loc;
    int len4;
    cout<<"Enter the Location of the Element you want to Add"<<"\n";
    cin>>loc;
    loc=loc-1; //Because For the computer length starts form 0
    len4=len+1; //Because Length of array increases by adding an element

    cout<<"Enter the Element you want to Add"<<"\n";
    int no;
    cin>>no;

    for(int i=len4; i>=loc; i--)
    {
        x[i+1]=x[i];

    }
    x[loc]=no;

    cout<<"The Final Array is : "<<"\n";
    showdata(x,len4);
}

int main()
{
    int a[100],len;
    cout<<"Enter The Length of First Array";
    cin>>len;
    cout<<"Enter The Elements Of First Array"<<"\n";
    takedata(a,len);
    insertion(a,len);
}








