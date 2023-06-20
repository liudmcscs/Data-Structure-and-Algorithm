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
    int b[5]={0},c[5]={0},d[5]={0},e[5]={0},med,sp;
    int f[5]={0};
    sp=(r-p)/8;
    b[0]=p;
    b[1]=p+sp;
    b[2]=p+2*sp;
    c[0]=p+3*sp;
    c[1]=p+4*sp;
    c[2]=p+5*sp;
    d[0]=p+6*sp;
    d[1]=p+7*sp;
    d[2]=r;
    f[0]=p;
    f[1]=p+(r-p)/2;
    f[2]=r;
    if((r-p)>=8)
    {
        if((a[b[1]]>a[b[0]]&&a[b[0]]>a[b[2]])||(a[b[2]]>a[b[0]]&&a[b[0]]>a[b[1]]))
        {
            e[0]=b[0];
        }
        else if((a[b[0]]>a[b[1]]&&a[b[1]]>a[b[2]])||(a[b[2]]>a[b[1]]&&a[b[1]]>a[b[0]]))
        {
            e[0]=b[1];
        }
        else if((a[b[0]]>a[b[2]]&&a[b[2]]>a[b[1]])||(a[b[1]]>a[b[2]]&&a[b[2]]>a[b[0]]))
        {
            e[0]=b[2];
        }
        if((a[c[1]]>a[c[0]]&&a[c[0]]>a[c[2]])||(a[c[2]]>a[c[0]]&&a[c[0]]>a[c[1]]))
        {
            e[1]=c[0];
        }
        else if((a[c[0]]>a[c[1]]&&a[c[1]]>a[c[2]])||(a[c[2]]>a[c[1]]&&a[c[1]]>a[c[0]]))
        {
            e[1]=c[1];
        }
        else if((a[c[0]]>a[c[2]]&&a[c[2]]>a[c[1]])||(a[c[1]]>a[c[2]]&&a[c[2]]>a[c[0]]))
        {
            e[1]=c[2];
        }
        if((a[d[1]]>a[d[0]]&&a[d[0]]>a[d[2]])||(a[d[2]]>a[d[0]]&&a[d[0]]>a[d[1]]))
        {
            e[2]=d[0];
        }

        else if((a[d[0]]>a[d[1]]&&a[d[1]]>a[d[2]])||(a[d[2]]>a[d[1]]&&a[d[1]]>a[d[0]]))
        {
            e[2]=d[1];
        }

        else if((a[d[0]]>a[d[2]]&&a[d[2]]>a[d[1]])||(a[d[1]]>a[d[2]]&&a[d[2]]>a[d[0]]))
        {
            e[2]=d[2];
        }
        if((a[e[1]]>a[e[0]]&&a[e[0]]>a[e[2]])||(a[e[2]]>a[e[0]]&&a[e[0]]>a[e[1]]))
        {
            med=e[0];
        }
        else if((a[e[0]]>a[e[1]]&&a[e[1]]>a[e[2]])||(a[e[2]]>a[e[1]]&&a[e[1]]>a[e[0]]))
        {
            med=e[1];
        }

        else if((a[e[0]]>a[e[2]]&&a[e[2]]>a[e[1]])||(a[e[1]]>a[e[2]]&&a[e[2]]>a[e[0]]))
        {
            med=e[2];
        }
    }
    else if((r-p)>1&&8>(r-p))
    {
        if((a[f[1]]>a[f[0]]&&a[f[0]]>a[f[2]])||(a[f[2]]>a[f[0]]&&a[f[0]]>a[f[1]]))
        {
            med=f[0];
        }

        else if((a[f[0]]>a[f[1]]&&a[f[1]]>a[f[2]])||(a[f[2]]>a[f[1]]&&a[f[1]]>a[f[0]]))
        {
            med=f[1];
        }

        else if((a[f[0]]>a[f[2]]&&a[f[2]]>a[f[1]])||(a[f[1]]>a[f[2]]&&a[f[2]]>a[f[0]]))
        {
            med=f[2];
        }
    }
    else if((r-p)==1)
    {
        med=p;
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
