#include <iostream>
#include <fstream>
#include<cstdlib>
#include<vector>
using namespace std;

void quicksort(int *ar1,int left,int right)
{
    int pivot, i, j,temp1,temp2,k;
    if(left>=right)return;
    pivot=ar1[left];
    i=left+1;
    j=right;
    while(1)
    {
        while(i<=right)
        {
            if(ar1[i]>pivot)
            {
                break;
            }
            i+=1;
        }
        while(j>left)
        {
            if(ar1[j]<pivot)
            {
                break;
            }
            j-=1;
        }
        if(i>j)
        {
            break;
        }
        temp1=ar1[j];
        ar1[j]=ar1[i];
        ar1[i]=temp1;
    }

    temp2=ar1[left];
    ar1[left]=ar1[j];
    ar1[j]=temp2;
    quicksort(ar1, left, j - 1);
    quicksort(ar1,j + 1, right);
}
int main(void)
{
    int n,m;
    ifstream fin("input.txt");
    char filename[]="output.txt";
    fstream fp;
    fp.open(filename, ios::out);
    if(!fp)
    {
        cout<<"Fail to open file: "<<filename<<endl;
    }

    fin>>n;
    int ar[n];
    {
        for(int qq=0;qq<=n-1;qq++)
        {
            fin>>ar[qq];
        }
    }
    quicksort(ar, 0, n-1 );
    for(int ll=0;ll<=(n-1);ll++)
    {
        if(ll==0)fp<<ar[ll];
        else if(ll==n)fp<<" "<<ar[ll]<<endl;
        else fp<<" "<<ar[ll];
    }
    fp.close();
    return 0;
}

