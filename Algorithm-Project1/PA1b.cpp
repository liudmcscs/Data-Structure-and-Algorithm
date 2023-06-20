#include<iostream>
#include <fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
int PARTITION(int [],int ,int );
void R_QUICKSORT(int [],int ,int );
int R_PARTITION(int [],int,int );

int main()
{
    ifstream fin("input.txt");
   	char filename[]="output.txt";
   	fstream fp;
   	fp.open(filename, ios::out);
   	if(!fp)
   	{
   	    cout<<"Fail to open file: "<<filename<<endl;
   	}
    int n;
    fin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    int p=1,r=n;
    R_QUICKSORT(a,p,r);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            fp<<a[i]<<" ";
        }
        else if(i==n)
        {
            fp<<a[i]<<endl;
        }
        else
        {
            fp<<a[i]<<" ";
        }
   }
   fp.close();
   return 0;
}

void R_QUICKSORT(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=R_PARTITION(a,p,r);
        R_QUICKSORT(a,p,q-1);
        R_QUICKSORT(a,q+1,r);
    }
}

int R_PARTITION(int a[],int p,int r)
{
    int b,c,d,med;
    srand ((unsigned)time(NULL));
    if((r-p)==1)
    {
        d=p;b=r;
    }
    else if((r-p)>1)
    {
        d=p+rand() %(r-p+1);
        //a =temp;
        b=p+rand() %(r-p+1);
        while(1)
        {

            if(d==b) b=p+rand() %(r-p+1);
            else break;

        }
        c=p+rand() %(r-p+1);
        while(1)
        {
            if(d==c||c==b)c=p+rand() %(r-p+1);
            else break;
        }
    }
    if((r-p)>1)
    {
        if((a[d]>a[b]&&a[c]>a[d])||(a[d]>a[c]&&a[b]>a[d]))
        {
            med=d;
        }

        else if((a[c]>a[b]&&a[b]>a[d])||(a[d]>a[b]&&a[b]>a[c]))
        {
            med=b;
        }

        else if((a[b]>a[c]&&a[c]>a[d])||(a[d]>a[c]&&a[c]>a[b]))
        {
            med=c;
        }
    }
    else
    {
        med=d;
    }
    int i=med;
    int temp;
    temp=a[r];
    a[r]=a[i];
    a[i]=temp;
    return PARTITION(a,p,r);
}
int PARTITION(int a[],int p,int r)
{
    int temp,temp1;
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp1=a[i+1];
    a[i+1]=a[r];
    a[r]=temp1;
    return i+1;
}
