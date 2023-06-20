#include <iostream>
#include <fstream>
#include<cstdlib>
#include<vector>
#include<deque>
using namespace std;
typedef struct node
{
    int num=0;
    char alp;
    int endv=1;
    node *lchild=NULL;
    node *rchild=NULL;
    node *parent=NULL;
}node;
typedef struct  weight
{
    char ch;
    int freq=0;
}weight;
vector <weight> wei;
int main()
{
    ifstream fin("input.txt");
    char filename[]="hufmancode.txt";
    fstream fp;
    fp.open(filename, ios::out);
    if(!fp)
    {
        cout<<"Fail to open file: "<<filename<<endl;
    }
    char str[1000000]={0};
    fin.getline(str,sizeof(str));
    int i=0;
    int s=0;
    int neverfind=0;
    weight tim;
    while(str[i]!=NULL)
    {
        tim.ch=str[i];
        tim.freq=1;
        s=0;
        neverfind=0;
        if(wei.size()==0)
        {
            wei.push_back(tim);
        }
        else if(wei.size()!=0)
        {
            while(s!=wei.size())
            {
                neverfind=1;
                if(wei[s].ch==tim.ch)
                {
                    wei[s].freq++;
                    i++;
                    neverfind=0;
                    break;
                }
                s++;
            }
            if(neverfind==0)
            {
                continue;
            }
            else if(neverfind==1)
            {
                wei.push_back(tim);
            }

        }
        i++;
    }
    int keyy;
    int ii=0;
    int k;
    int cc;
    int j;
    weight temp;
    for(ii=1;ii<(wei.size());ii++)
    {
        j=ii;
        while(j>0&&wei[j-1].freq>wei[j].freq)
        {
            temp=wei[j];
            wei[j]=wei[j-1];
            wei[j-1]=temp;
            j--;
        }
    }
    i=0;
    vector<node*> vertice,vertice2;
	node* ver;
	for(int h=0;h<wei.size();h++)
    {
        ver=new node;
        ver->alp=wei[h].ch;
        ver->num=wei[h].freq;
        vertice.push_back(ver);
        vertice2.push_back(ver);
    }
    int nn=0;
    node* tempver;
    while(vertice.size()>2)
    {
        nn=vertice[0]->num+vertice[1]->num;
        ver=new node;
        ver->num=nn;
        ver->rchild=vertice[1];
        ver->lchild=vertice[0];
        ver->endv=0;
        ver->rchild->parent=ver;
        ver->lchild->parent=ver;
        vertice.erase(vertice.begin());
        vertice.erase(vertice.begin());
        vertice.push_back(ver);
        for(ii=1;ii<(vertice.size());ii++)
        {
            j=ii;
            while(j>0&&vertice[j-1]->num>vertice[j]->num)
            {
                tempver=vertice[j];
                vertice[j]=vertice[j-1];
                vertice[j-1]=tempver;
                j--;
            }
        }
    }
    node* root;
    node* ptr;
        nn=vertice[0]->num+vertice[1]->num;
        ver=new node;
        ver->num=nn;
        ver->rchild=vertice[1];
        ver->lchild=vertice[0];
        ver->endv=0;
        ver->rchild->parent=ver;
        ver->lchild->parent=ver;
        root=ver;
        i=0;
        int f=0;
    deque <int> hufman;
    while(str[i]!=NULL)
    {
        f=0;
        while(vertice2[f]->alp!=str[i])
        {
            f++;

        }
        ptr=vertice2[f];
        while(ptr!=root)
        if(ptr==ptr->parent->lchild)
        {
            ptr=ptr->parent;
            hufman.push_front(0);
        }
        else if(ptr==ptr->parent->rchild)
        {
            ptr=ptr->parent;
            hufman.push_front(1);
        }
        i++;
    }
    i=0;
    while(i<hufman.size())
    {
        fp<<hufman[i];
        i++;
    }
    fp.close();
    ifstream fin2("hufmancode.txt");
    char filename2[]="output.txt";
    fstream fp2;
    fp2.open(filename2, ios::out);
    if(!fp2)
    {
        cout<<"Fail to open file: "<<filename<<endl;
    }
    char str222[1000000]={0};
    deque<char> show;
    fin2.getline(str222,sizeof(str222));
    i=0;
    ptr=root;
    while(str222[i]!=NULL)
    {
        ptr=root;
        while(ptr->endv==0)
        {
            if(str222[i]=='0')
            {
                ptr=ptr->lchild;
            }
            else if(str222[i]=='1')
            {
                ptr=ptr->rchild;
            }
            i++;
        }

        show.push_front(ptr->alp);
    }
    i=0;
    while(i<show.size())
    {
        fp2<<show[i];
        i++;
    }
    fp2.close();
    return 0;
}

