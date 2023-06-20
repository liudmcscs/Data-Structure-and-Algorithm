#include <iostream>
#include <fstream>
#include<cstdlib>
#include<list>
#include <string>
using namespace std;
int main(int argc,char* argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);
	list<int> li;
	list<char> temp1;
    list<char> temp;
    list<list<char> > ou;
    list <int>::iterator lint;
    list <int>::iterator lint9;
    list <char>::iterator lchar;
    list<list<char> > :: iterator llchar;
    list<list<char> > :: iterator llchar9;
	int n,co=0,cou=0,kk=0,ss;
	fin>>n;
	co=n;
	while(fin>>n)
    {
        if(n<0)
        {
            break;
        }
        if(n==co&&kk==0)
        {
            kk=1;
        }
        else if(n!=co&&kk==0)
        {
            cou++;
        }
        li.push_back(n);
    }
    char space[10]={0};
    fin.getline(space,2,'\n');
    char m[li.size()-1][100]={0};
    ss=li.size()-1;
    for(int qq=0;qq<=(li.size()-2);qq++)
    {
        fin.getline(m[qq],97,'\n');
    }
    list<char> out[(li.size()-1)];
    for(int mm=0;mm<=(li.size()-1);mm++)
    {
        ou.push_back(temp1);
    }
    int p=0,q=0;
    int cc=0;
    int status=0,way=0;
    lint=li.begin();
    lchar=temp.begin();
    llchar=ou.begin();
    while(cc!=cou)
    {
        lint++;
        llchar++;
        cc++;
    }
    int times=0;
    while(times!=ss)
    {
        while(1)
        {
            if(m[p][q]=='\0')
            {

                if(status==0)
                {
                    lint9=li.end();
                    lint9--;
                    llchar9=ou.end();
                    llchar9--;
                    if(lint==li.begin())
                    {
                        lint=lint9;
                        llchar=llchar9;
                    }
                    else
                    {
                        llchar--;
                        lint--;
                    }
                }
                else if(status==1)
                {
                    lint9=li.end();
                    lint9--;
                    llchar9=ou.end();
                    llchar9--;
                    if(lint==lint9)
                    {
                        lint=li.begin();
                        llchar=ou.begin();
                    }
                    else
                    {
                        llchar++;
                        lint++;
                    }
                }
                if(m[p][q-1]=='a'||m[p][q-1]=='e'||m[p][q-1]=='i'||m[p][q-1]=='o'||m[p][q-1]=='u')
                {
                    fout<<*lint<<" ";
                    temp.swap(*llchar);
                    for(lchar=temp.begin();lchar!=temp.end();lchar++)
                    {
                        fout<<*lchar;
                    }
                    fout<<endl;
                    if(status==0)
                    {
                        lint9=li.end();
                        lint9--;
                        llchar9=ou.end();
                        llchar9--;
                        if(lint==lint9)
                        {
                            llchar=ou.erase(llchar9);
                            lint=li.erase(lint9);
                            lint=li.begin();
                            llchar=ou.begin();
                        }
                        else
                        {
                            llchar=ou.erase(llchar);
                            lint=li.erase(lint);
                        }
                    }
                    else if(status==1)
                    {
                        if(lint==li.begin())
                        {
                            llchar=ou.erase(ou.begin());
                            lint=li.erase(li.begin());
                            lint9=li.end();
                            lint9--;
                            llchar9=ou.end();
                            llchar9--;
                            lint=lint9;
                            llchar=llchar9;
                        }
                        else
                        {
                            llchar=ou.erase(llchar);
                            lint=li.erase(lint);
                            llchar--;
                            lint--;
                        }
                    }
                    break;
                }
                else
                {
                    fout<<*lint<<" ";
                    temp.swap(*llchar);
                    for(lchar=temp.begin();lchar!=temp.end();lchar++)
                    {
                        fout<<*lchar;
                    }
                    fout<<endl;
                    if(status==0)
                    {
                        status=1;
                    }
                    else if(status==1)
                    {
                        status=0;
                    }
                    if(status==0)
                    {
                        lint9=li.end();
                        lint9--;
                        llchar9=ou.end();
                        llchar9--;
                        if(lint==lint9)
                        {
                            llchar=ou.erase(llchar9);
                            lint=li.erase(lint9);lint=li.begin();
                            llchar=ou.begin();
                        }
                        else
                        {
                            llchar=ou.erase(llchar);
                            lint=li.erase(lint);
                        }
                    }
                    else if(status==1)
                    {
                        if(lint==li.begin())
                        {
                            lint9=li.end();
                            lint9--;
                            llchar9=ou.end();
                            llchar9--;                        llchar=ou.erase(ou.begin());
                            lint=li.erase(li.begin());
                            lint=lint9;
                            llchar=llchar9;
                        }
                        else
                        {
                            llchar=ou.erase(llchar);
                            lint=li.erase(lint);
                            lint--;
                            llchar--;
                        }
                    }
                    if(way==0)
                    {
                        way=1;
                    }
                    else if(way==1)
                    {
                        way=0;
                    }
                    break;
                }
            }

            else
            {
                temp.swap(*llchar);
                if(way==0)
                {
                    temp.push_back(m[p][q]);
                    temp.swap(*llchar);
                }
                else if(way==1)
                {
                    temp.push_front(m[p][q]);
                    temp.swap(*llchar);
                }
                if(status==0)
                {
                    llchar9=ou.end();
                    llchar9--;
                    if(llchar==llchar9)
                    {
                        llchar=ou.begin();
                        lint=li.begin();
                    }
                    else
                    {
                        llchar++;
                        lint++;
                    }
                }
                else if(status==1)
                {
                    llchar9=ou.end();
                    llchar9--;
                    lint9=li.end();
                    lint9--;
                    if(llchar==ou.begin())
                    {
                        llchar=llchar9;
                        lint=lint9;
                    }
                    else
                    {
                        llchar--;
                        lint--;
                    }
                }
                q++;
            }
        }
        p++;
        q=0;
        times++;
    }
    fout<<*li.begin()<<" ";
    llchar=ou.begin();
    temp=*llchar;
    for(lchar=temp.begin();lchar!=temp.end();lchar++)
    {
        fout<<*lchar;
    }
	fin.close();
	fout.close();
	return 0;
}
