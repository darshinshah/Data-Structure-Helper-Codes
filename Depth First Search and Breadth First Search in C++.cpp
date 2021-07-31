#include<iostream>
#include<queue> //pop push front empty
#include<stack> //pop push top empty

using namespace std;

void creategraph(int a[][100],int element1,int element2)
{
    for(int i=0;i<element1;i++)
    {
        for(int j=0;j<element2;j++)
        {
            cout<<"Does "<<i+1<<"  have any edge with "<<j+1;
            cout<<"    Enter 1 if Yes else 0";
            cin>>a[i][j];
        }
    }


}

void display(int a[][100],int element1,int element2)
{
    for(int i=0;i<element1;i++)
    {
        for(int j=0;j<element2;j++)
        {
            cout<<a[i][j]<<"   ";

        }
        cout<<"\n";
    }

}

void BFS(int a[][100],int element1,int element2)
{
    int v=0;
    cout<<"Enter Starting Point : ";
    cin>>v;
    int visited[100];
    for(int j=0;j<element1;j++)
    {
        visited[j]=0;
    }
    visited[v]=1;
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        cout<<v<<"---->";
        for(int i=0;i<element1;i++)
        {
            if(a[v][i]==1)
            {
                if(visited[i]==0)
                {
                    visited[i]=1;
                    q.push(i);
                }

            }
        }

    }
    cout<<"END";

}

void DFS(int a[][100],int element1,int element2)
{
    int v=0;
    cout<<"Enter Starting Point : ";
    cin>>v;
    int visited[100];
    for(int j=0;j<element1;j++)
    {
        visited[j]=0;
    }
    stack<int> S;
    S.push(v);
    while(!S.empty())
    {
        v=S.top();
        S.pop();
        if(visited[v]==0)
        {
            visited[v]=1;
            cout<<v<<"---->";
        for(int j=0;j<element1;j++)
        {
            if(a[v][j]==1)
            {
                S.push(j);
            }

        }
    }

}
cout<<"END";
}

int main()
{
    int array1[100][100];
    int no;

    cout<<"Enter How many Elements you want in the Graph :  ";
    cin>>no;

    creategraph(array1,no,no);
    cout<<"\n\n";
    cout<<"The Graph is : \n\n";

    display(array1,no,no);
    cout<<"\n\n";
    cout<<"The Breadth First Search is : \n";
    BFS(array1,no,no);
    cout<<"\n\n";

    DFS(array1,no,no);
    cout<<"\n\n";
}
