#include<iostream>
#define max 6
using namespace std;

int isempty(int* rear1,int* front1)
{
    if((*front1)==-1 && (*rear1)==-1)
        return 1;
    else
        return 0;
}

int isfull(int* rear1,int* front1)
{
    if(((*rear1)+1)%max==(*front1))
        return 1;
    else
        return 0;
}

void Enqueue(int x[max],int* rear1,int* front1,int value)
{
    if(isfull((&(*rear1)),(&(*front1)))==1)
    {
        cout<<"The Queue is Full. OVERFLOW\n";
        return;
    }
    else if(isempty((&(*rear1)),(&(*front1)))==1)
    {
        (*rear1)=(*front1)=0;
        x[*rear1]=value;
    }
    else
    {
        (*rear1)=((*rear1)+1)%max;
        x[*rear1]=value;
    }
}

void create(int x[max],int* rear1,int* front1,int num)
{
    int data;
    for(int i=0;i<num;i++)
    {
        cout<<"Enter Data : ";
        cin>>data;
        Enqueue(x,&(*rear1),&(*front1),data);
    }
}

void Dequeue(int x[max],int* rear1,int* front1)
{
    int value;
    if(isempty((&(*rear1)),(&(*front1)))==1)
    {
        cout<<"The Queue is Empty. UNDERFLOW\n";
    }
    else if((*front1)==(*rear1))
    {
        value=x[*front1];
        (*front1)=(*rear1)=-1;
    }
    else
    {
        value=x[*front1];
        (*front1)=((*front1)+1)%max;
    }
}

void display(int x[max],int *rear1,int* front1)
{
    cout<<"\n----------------------------------------------------------------------\n";
    cout<<"The Queue is : \n";
    if(isempty((&(*rear1)),(&(*front1)))==1)
    {
        cout<<"The Queue is Empty. UNDERFLOW\n";
    }
    else
    {
        int i=0;
        for(i=(*front1);i!=(*rear1);i=((i+1)%max))
        {
            cout<<"Value at Position : "<<i+1<<" ---> "<<x[i]<<"\n";
        }
        cout<<"Value at Position : "<<i+1<<" ---> "<<x[i]<<"\n";

    }
    cout<<"----------------------------------------------------------------------\n";

}

int main()
{
    int Queue[20];
    int rear1=-1;
    int front1=-1;
    int addqueue;
    int adddata;
    int no;
    int deletequeue;
    int addelements;
    cout<<"How Many Queue Elements Do You Want : ";
    cin>>no;

    create(Queue,&rear1,&front1,no);
    display(Queue,&rear1,&front1);

    cout<<"How Many Elements You want to Add To Queue : ";
    cin>>addqueue;
    for(int i=0;i<addqueue;i++)
    {
        cout<<"Enter Data To Add : ";
        cin>>adddata;
        Enqueue(Queue,&rear1,&front1,adddata);
    }
    display(Queue,&rear1,&front1);

//-------------------------------------------------------------------------------------------------

    cout<<"How Many Elements You want to Delete From Queue : ";
    cin>>deletequeue;

    for(int i=0;i<deletequeue;i++)
    {
        Dequeue(Queue,&rear1,&front1);
    }
    display(Queue,&rear1,&front1);

//-------------------------------------------------------------------------------------------------

    cout<<"How Many Elements you want to Add : ";
    cin>>addelements;
    for(int i=0;i<addelements;i++)
    {
        int data;
        cout<<"Enter The Data : ";
        cin>>data;
        Enqueue(Queue,&rear1,&front1,data);

    }
    display(Queue,&rear1,&front1);
}









