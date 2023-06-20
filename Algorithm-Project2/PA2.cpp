#include <iostream>
#include <fstream>
#include<cstdlib>
#include<vector>
using namespace std;
int w[5][5];
int d[5][5];
int medium[5][5];
vector<int> kk;
void find_path(int i, int j)
{
    if (medium[i][j] == NULL) return;
    find_path(i, medium[i][j]);
    find_path(medium[i][j], j);
}
int main()
{
    int n,m;
    ifstream fin("input.txt");
    char filename[]="output.txt";
    fstream fp;
    fp.open(filename, ios::out);
    if(!fp)
    {
        //cout<<"Fail to open file: "<<filename<<endl;
    }
    int lll;
    int beginv=0;
    int endv=0;
    char v;
    for(int k=0;k<5;k++)
    {
        for(int j=0;j<5;j++)
        {
            fin>>lll;
            w[k][j]=lll;
        }
    }
    fin>>v;
    fin>>lll;
    beginv=lll-1;
    fin>>v;
    fin>>lll;
    endv=lll-1;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            d[i][j] = w[i][j];
            if(d[i][j]==0)d[i][j]=9999999;
            if(i==j||d[i][j]==9999999)medium[i][j] = -1;
            else if(i!=j&&d[i][j]<9999999)medium[i][j] = i;
        }
    }
    for (int i=0; i<5; i++)
    {
        d[i][i] = 0;
    }
    for (int k=0; k<5; k++)
    {
        for (int i=0; i<5; i++)
        {
             for (int j=0; j<5; j++)
             {
                if( (d[i][k] + d[k][j] )>=d[i][j])
                {
                    medium[i][j] = medium[i][j];
                }
                else if((d[i][k] + d[k][j])<d[i][j])
                {
                    medium[i][j] =medium[k][j];
                }
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
             }
        }
    }
    int po=endv;
    while(medium[beginv][po]!=-1)
    {
        kk.push_back(medium[beginv][po]+1);
        po=medium[beginv][po];
    }
    int y=0;
    while(y<=kk.size()-1)
    {
        y++;
    }
    y=kk.size()-1;
    while(y>=0)
    {
        fp<<"v"<<kk[y]<<" ";
        y--;
    }
    fp<<"v"<<(endv+1)<<" ";
    fp<<d[beginv][endv];
    fp.close();
    return 0;
}

