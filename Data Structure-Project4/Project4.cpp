#include <fstream>
#include <iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int main(int argc,char* argv[])
{
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);
    vector<int> kk;
    int verticenum=0;
    fin>>verticenum;
    int lll;
    int beginv=0;
    int endv=0;
    char m;
    int a=0,b=0,c=0;
    long long int **w;
    w = new long long int *[verticenum];
    for (int i=0;i<verticenum;i++)
    {
        w[i] = new long long int [verticenum];
    }
    long long int **d;
    d = new long long int *[verticenum];
    for (int i=0;i<verticenum;i++)
    {

        d[i] = new long long int  [verticenum];
    }
    int **medium;
    medium = new int *[verticenum];
    int i5=0;
    for (i5=0;i5<verticenum;i5++)
    {
        medium[i5] = new  int [verticenum];
    }
    int **findd;
    findd = new int *[verticenum];
    int i6=0;

    for (i6=0;i6<verticenum;i6++)
    {
        findd[i6] = new  int [verticenum];
    }
    for(int k5=0;k5<verticenum;k5++)
    {
        for(int j5=0;j5<verticenum;j5++)
        {
            w[k5][j5]=0;
            findd[k5][j5]=0;
        }
    }
    while(fin>>a)
    {
        fin>>b;
        fin>>c;
        w[a-1][b-1]=c;
        findd[a-1][b-1]=1;
    }
    fin.clear();
    fin>>m;
    for (int i=0; i<verticenum; i++)
    {
        for (int j=0; j<verticenum; j++)
        {
            d[i][j] = w[i][j];
            if(d[i][j]==0&&findd[i][j]==0)d[i][j]=21474836470000;
            if(i==j||d[i][j]==21474836470000)medium[i][j] = -1;
            else if(i!=j&&d[i][j]<21474836470000)medium[i][j] = i;
        }
    }
    for (int i=0; i<verticenum; i++)
    {
        d[i][i] = 0;
    }
    for (int k=0; k<verticenum; k++)
    {
        for (int i=0; i<verticenum; i++)
        {
             for (int j=0; j<verticenum; j++)
             {
                if( (d[i][k] + d[k][j] )>=d[i][j])
                {
                    medium[i][j] = medium[i][j];
                }
                else if((d[i][k] + d[k][j])<d[i][j]&&medium[i][k]!=-1&&medium[k][j]!=-1)
                {
                    medium[i][j] =medium[k][j];
                }
                if (d[i][k] + d[k][j] < d[i][j]&&medium[i][k]!=-1&&medium[k][j]!=-1)
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
             }
        }
    }
    int vv=0,vvv=0;
    int times=0;
    int po;
    int negativecycle=0;
    for(int si=0;si<verticenum;si++)
    {
        if(d[si][si]<0)
        {
            negativecycle=1;
        }
    }
    while(fin>>vv)
    {
        if(negativecycle==1)
        {
            fout<<"Negative cycle"<<endl;
            break;
        }
        kk.clear();
        fin>>vvv;
        beginv=vv-1;
        endv=vvv-1;
        po=endv;
        if(medium[beginv][po]==-1)
        {
            fout<<"No path"<<endl;
            continue;
        }
        while(medium[beginv][po]!=-1)
        {
             kk.push_back(medium[beginv][po]+1);
            po=medium[beginv][po];

        }
        int y=0;
        y=kk.size()-1;
        fout<<d[beginv][endv]<<" ";
        while(y>=0)
        {
            fout<<kk[y]<<" ";
            y--;
        }
        fout<<(endv+1)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
