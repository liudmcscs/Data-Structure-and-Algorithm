#include <fstream>
#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
typedef struct node//st
    {
        int id;
        int x;
        char d;
        int times=0;
        node*pre=NULL;
        node* lnode=NULL;
        node* rnode=NULL;
    }node;
int main(int argc,char* argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);
	char str[18]={0};
	char strl[18]={0};
	int a,b;
	char m;
	node* root;
	root=new node;
	root=NULL;
	node*newnode;
    node* current;
    node* ptr;
	int i=0;
	int rr=0;
    int ii=0;
    int tttt=0;
    int droptimes;
    vector<int> record;
    while(fin.getline(str,10,' '))
    {
        if(root!=NULL)root->pre=NULL;
        i+=1;
        if(strcmp(str,"add")==0)
        {
            fin>>a;
            fin>>m;
            fin>>b;
            fin.getline(str,10,'\n');
            newnode=new node;
            newnode->id=a;
            newnode->d=m;
            newnode->x=b;
            newnode->times=0;
            newnode->lnode=NULL;
            newnode->pre=NULL;
            newnode->rnode=NULL;
            if(root==NULL)
            {
                root=newnode;
            }
            else
            {
                current=root;
                while(1)
                {
                    if(current->rnode!=NULL&&newnode->id>current->id)
                    {
                        current=current->rnode;
                    }
                    else if(current->lnode!=NULL&&newnode->id<current->id)
                    {
                        current=current->lnode;
                    }
                    else if(current->lnode==NULL&&newnode->id<current->id)
                    {
                        current->lnode=newnode;
                        current->lnode->pre=current;
                        break;
                    }
                    else if(current->rnode==NULL&&newnode->id>current->id)
                    {
                        current->rnode=newnode;
                        current->rnode->pre=current;
                        break;
                    }
                    else if(newnode->id==current->id)
                    {
                        current->d=newnode->d;
                        current->x=newnode->x;
                        current->times=0;
                        break;
                    }
                }
            }
        }
        else if(strcmp(str,"deleteR")==0)
        {
            fin>>a;
            fin.getline(str,10,'\n');
            current=root;
            while(1)
            {
                root->pre=NULL;
                if(current!=NULL)
                {
                    if(a>current->id)
                    {
                        current=current->rnode;
                    }
                    else if(a<current->id)
                    {
                        current=current->lnode;
                    }
                    else if(current->id==a)
                    {
                        ptr=current;
                        ii=0;
                        if(current->lnode!=NULL&&current->rnode!=NULL)
                        {
                            ptr=ptr->rnode;
                            while(ptr->lnode!=NULL)
                            {
                                ptr=ptr->lnode;
                                ii=1;
                            }
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            if(ii==0)
                            {
                                ptr->pre->rnode=ptr->rnode;
                                 if(ptr->rnode!=NULL)
                                 {
                                    ptr->rnode->pre=ptr->pre;
                                 }
                            }
                            else if(ii==1)
                            {
                                ptr->pre->lnode=ptr->rnode;
                                if(ptr->rnode!=NULL)ptr->rnode->pre=ptr->pre;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode==NULL&&current->rnode!=NULL)
                        {
                            ptr=ptr->rnode;
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            current->lnode=ptr->lnode;
                            current->rnode=ptr->rnode;
                            if(ptr->rnode!=NULL)
                            {
                                ptr->rnode->pre=current;
                            }
                            if(ptr->lnode!=NULL)
                            {
                                ptr->lnode->pre=current;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode!=NULL&&current->rnode==NULL)
                        {
                            ptr=ptr->lnode;
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            current->lnode=ptr->lnode;
                            current->rnode=ptr->rnode;
                            if(ptr->rnode!=NULL)
                            {
                                ptr->rnode->pre=current;
                            }
                            if(ptr->lnode!=NULL)
                            {
                                ptr->lnode->pre=current;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode==NULL&&current->rnode==NULL)
                        {
                            if(current!=root)
                            {
                                if(current->id > current->pre->id)
                                {
                                    current->pre->rnode=NULL;
                                    delete current;
                                    break;
                                }
                                else if(current->id < current->pre->id)
                                {
                                    current->pre->lnode=NULL;
                                    delete current;
                                    break;
                                }
                            }
                            else if(current==root)
                            {
                                delete current;
                                root=NULL;
                                break;
                            }
                        }
                    }
                }
                else if(current==NULL)
                {
                    fout<<"Deletion failed."<<endl;
                    break;
                }
            }
        }
        else if(strcmp(str,"deleteL")==0)
        {
            fin>>a;
            fin.getline(str,10,'\n');
            current=root;
            while(1)
            {
                root->pre=NULL;
                if(current!=NULL)
                {
                    if(a>current->id)
                    {
                        current=current->rnode;
                    }
                    else if(a<current->id)
                    {
                        current=current->lnode;
                    }
                    else if(current->id==a)
                    {

                        ptr=current;
                        ii=0;
                        if(current->lnode!=NULL&&current->rnode!=NULL)
                        {
                            ptr=ptr->lnode;
                            while(ptr->rnode!=NULL)
                            {
                                ptr=ptr->rnode;
                                ii=1;
                            }
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            if(ii==0)
                            {
                                ptr->pre->lnode=ptr->lnode;
                                 if(ptr->lnode!=NULL)
                                 {
                                    ptr->lnode->pre=ptr->pre;
                                 }
                            }
                            else if(ii==1)
                            {
                                ptr->pre->rnode=ptr->lnode;
                                if(ptr->lnode!=NULL)ptr->lnode->pre=ptr->pre;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode==NULL&&current->rnode!=NULL)
                        {
                            ptr=ptr->rnode;
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            current->lnode=ptr->lnode;
                            current->rnode=ptr->rnode;
                            if(ptr->rnode!=NULL)
                            {
                                ptr->rnode->pre=current;
                            }
                            if(ptr->lnode!=NULL)
                            {
                                ptr->lnode->pre=current;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode!=NULL&&current->rnode==NULL)
                        {
                            ptr=ptr->lnode;
                            current->id=ptr->id;
                            current->d=ptr->d;
                            current->x=ptr->x;
                            current->times=ptr->times;
                            current->lnode=ptr->lnode;
                            current->rnode=ptr->rnode;
                            if(ptr->rnode!=NULL)
                            {
                                ptr->rnode->pre=current;
                            }
                            if(ptr->lnode!=NULL)
                            {
                                ptr->lnode->pre=current;
                            }
                            delete ptr;
                            break;
                        }
                        else if(current->lnode==NULL&&current->rnode==NULL)
                        {
                            if(current!=root)
                            {
                                if(current->id > current->pre->id)
                                {
                                    current->pre->rnode=NULL;
                                    delete current;
                                    break;
                                }
                                else if(current->id < current->pre->id)
                                {
                                    current->pre->lnode=NULL;
                                    delete current;
                                    break;
                                }
                            }
                            else if(current==root)
                            {
                                delete current;
                                root=NULL;
                                break;
                            }
                        }
                    }
                }
                else if(current==NULL)
                {
                    fout<<"Deletion failed."<<endl;
                    break;
                }
            }
        }
        else if(strcmp(str,"drop")==0)
        {
            fin>>a;
            fin.getline(str,10,'\n');
            current=root;
            record.clear();
            droptimes=0;
            if(root==NULL)
            {
                fout<<"Tree is empty."<<endl;
            }
            else if(root!=NULL)
            {
                while(droptimes<=(a-1))
                {
                    while(current!=NULL)
                    {
                        if(current->d=='L')
                        {
                            if(droptimes==(a-1) )
                            {
                                record.push_back(current->id);
                            }
                            if(current->x!=0)
                            {
                                current->times+=1;
                                if(current->times==current->x)
                                {
                                    current->d='R';
                                    current->times=0;
                                }
                                current=current->lnode;
                            }
                            else if(current->x==0)
                            {
                                current=current->lnode;
                            }
                        }
                        else if(current->d=='R')
                        {
                            if(droptimes==(a-1) )
                            {
                                record.push_back(current->id);
                            }
                            if(current->x!=0)
                            {
                                current->times+=1;
                                if(current->times==current->x)
                                {
                                    current->d='L';
                                    current->times=0;
                                }
                                current=current->rnode;
                            }
                            else if(current->x==0)
                            {
                                current=current->rnode;
                            }
                        }
                    }
                    current=root;
                    droptimes++;
                }
                for(tttt=0;tttt<record.size();tttt++)
                {
                    if(tttt==(record.size()-1) )
                    {
                        fout<<record[tttt]<<endl;
                    }
                    else
                    {
                        fout<<record[tttt]<<" ";
                    }
                }
            }
        }
    }
	fin.close();
	fout.close();
	return 0;
}
