#include<iostream>

using namespace std;

//function declaration
void takedata(int x[][100],int r,int c);
void showdata (int x[][100],int r,int c);
void addition (int x[][100],int r,int c,int y[][100],int r2,int c2);
void transpose(int x[][100],int r,int c);
void multiplication (int x[][100],int r,int c,int y[][100],int r2,int c2);

void takedata(int x[][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>x[i][j];
        }

    }

}
void showdata (int x[][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<x[i][j]<<" ";
        }
            cout<<"\n";
    }

}

void addition (int x[][100],int r,int c,int y[][100],int r2,int c2)
{
    int add[100][100];
    if(r==r2 && c==c2) //condition checking
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                add[i][j]=x[i][j]+y[i][j];
            }
        }

       showdata(add,r,c);
    }
    else
    {
     cout<<"The Addition is not Possible"<<"\n";
    }
}

void transpose(int x[][100],int r,int c)
{
    int trans[100][100];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {

            trans[j][i]=x[i][j];

        }

    }

  showdata(trans,c,r);
}

void multiplication (int x[][100],int r,int c,int y[][100],int r2,int c2)
{
    int multi[100][100];
    if(c==r2)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c2;j++)
            {
                multi[i][j]=0;
                for(int k=0; k<c;k++)
                {
                    multi[i][j]=multi[i][j] + (x[i][k]*y[k][j]) ;
                }

            }
        }
      cout<<"Multiplied Matrix is : "<<"\n";
      showdata(multi,r,c2);
    }
    else
    cout<<"Multiplication is not possible"<<"\n";
}

int main()
{
    int array1[100][100],row,col;
    int array2[100][100],row2,col2;

    cout<<"Enter The Row and Column of Matrix"<<"\n";
    cin>>row>>col;
    cout<<"Enter The Matrix"<<"\n";
    takedata(array1,row,col);
    cout<<"\n";

    cout<<"The Matrix is "<<"\n";
    showdata(array1,row,col);
    cout<<"\n";

    cout<<"Enter The Row and Column of Second Matrix for Addition"<<"\n";
    cin>>row2>>col2;
    cout<<"\n";
    cout<<"Enter The Second Matrix for Addition"<<"\n";
    takedata(array2,row2,col2);
    cout<<"\n";

    cout<<"The Second Matrix is "<<"\n";
    showdata(array2,row2,col2);
    cout<<"\n";

    cout<<"The Added Matrix is :"<<"\n";
    addition(array1,row,col,array2,row2,col2);

    cout<<"\n"<<"The Transpose is : "<<"\n";
    transpose(array1,row,col);

    cout<<"\n";
    multiplication(array1,row,col,array2,row2,col2);
}
