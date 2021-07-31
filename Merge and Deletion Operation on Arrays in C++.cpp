#include<string>
#include<iostream>

using namespace std;

void takedata(int x[],int m);
void showdata(int x[],int m);
double average(int x[],int m);
void maxmin(int x[],int m);
void Merge(int y[],int len1,int x[],int len);
void delet (int x[],int len);

int main()  //Should Be declared below all functions if above statements arent declared
{
    int a[100],len;
    int b[100],len1;

    cout<<"Enter The Length of First Array";
    cin>>len;
    cout<<"Enter The Elements Of First Array"<<"\n";
    takedata(a,len);

    cout<<"Enter The Length of The Second Array";
    cin>>len1;
    cout<<"Enter The Elements Of Second Array"<<"\n";
    takedata(b,len1);

    cout<<"\n";
    cout<<"The Elements Of First Array Are"<<"\n";
    showdata(a,len);
    cout<<"The Elements Of Second Array Are"<<"\n";
    showdata(b,len1);

    cout<<"\n";
    double ans=average(a,len);
    cout<<"The Average is :  "<<ans;

    cout<<"\n";
    cout<<"\n";
    maxmin(a,len);

    cout<<"\n";
    Merge(b,len1,a,len);

    cout<<"\n";
    delet(a,len);
}


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



double average(int x[],int m)
{
  double sum=0;
  for(int i=0; i<m ; i++)
  {
      sum=sum+x[i];
  }
  double avg = sum/m;
  return avg;
  }


void maxmin(int x[],int m)
{
    int pmax=0;
    int pmin=0;
    int maximum=x[0];
    int minimum=x[0];
    //For Maximum
    for (int i=0; i<m; i++)
    {
        if(x[i]>=maximum)
        {
            maximum=x[i];
            pmax=i+1;
        }
    }
    //For Minimum
    for (int i=0; i<m; i++)
    {
        if(x[i]<=minimum)
        {
            minimum=x[i];
            pmin=i+1;
        }
    }
    cout<<"The Maximum is :  "<<maximum<<"\n";
    cout<<"The Maximum Position is :  "<<pmax<<"\n";
    cout<<"The Minimum is :  "<<minimum<<"\n";
    cout<<"The Minimum Position is :  "<<pmin<<"\n";
    }

void Merge(int y[],int len1,int x[],int len)
{
    int c[200];
    int len2=len+len1;
    for(int i=0; i<len ;i++)
    {
    c[i]=x[i];
    }
    int j=0; //For Second Array Position starts from 1 unlike the bigger array
    for(int k=len; k<len2 ;k++)
    {
    c[k]=y[j];
    j++;
    }

    cout<<"The Merged Array is : "<<"\n";
    showdata(c,len2);
}

void delet (int x[],int len)
{
    int loc;
    cout<<"Enter the Location of the Element you want to Delete"<<"\n";
    cin>>loc;
    loc=loc-1; //Because For the computer length starts form 0

    for(int i=loc; i<len-1; i++)
    {
        x[i]=x[i+1];
    }
    cout<<"The Deleted Array is : "<<"\n";
    showdata(x,len-1);
}


