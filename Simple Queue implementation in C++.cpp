#include<iostream>
#define max 6 //Maximum Size of Queue
using namespace std;

void Enqueue(int x[max],int* rear1,int* front1,int value)
{
    if((*rear1)==max-1)
    {
        cout<<"The Queue is Full. OVERFLOW\n";
    }
    else if((*front1)==-1 && (*rear1)==-1)
    {
        (*rear1)=(*front1)=0;
        x[*rear1]=value;
    }
    else
    {
        (*rear1)++;
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
    if((*front1)==-1 ||(*rear1)<(*front1))
    {
        cout<<"The Queue is Empty. UNDERFLOW\n";
    }
    else
    {
        value=x[*front1];
        (*front1)++;
    }
}

void display(int x[max],int *rear1,int* front1)
{
    cout<<"\n----------------------------------------------------------------------\n";
    cout<<"The Queue is : \n";
    if((*front1)==-1 ||(*rear1)<(*front1))
    {
        cout<<"The Queue is Empty. UNDERFLOW\n";
    }
    else
    {
        for(int i=(*front1);i<=(*rear1);i++)
        {
            cout<<"Value at Position : "<<i+1<<" ---> "<<x[i]<<"\n";
        }
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
    int queuesize;
    int deletequeue;
    cout<<"How Many Queue Elements Do You Want : ";
    cin>>no;

    create(Queue,&rear1,&front1,no);
    queuesize=no;
    display(Queue,&rear1,&front1);

    cout<<"How Many Elements You want to Add To Queue : ";
    cin>>addqueue;
    queuesize+=addqueue;
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
    queuesize-=deletequeue;
    for(int i=0;i<deletequeue;i++)
    {
        Dequeue(Queue,&rear1,&front1);
    }
    display(Queue,&rear1,&front1);
}









