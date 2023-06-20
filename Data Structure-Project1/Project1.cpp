#include <iostream>
#include <fstream>
#include<deque>
#include<cstdlib>
#include<stack>
#include<queue>
#include <string>
using namespace std;
typedef struct card{
int num;
char suit;
char numc;
}card;
typedef deque<card> layer;
typedef queue<layer> tempque;
typedef deque<layer> tempdeq;
typedef struct chan
{
    int fir;
    int sec;
}chan;
int main(int argc,char* argv[]){
ifstream fin;
ofstream fout;
fin.open(argv[1]);
fout.open(argv[2]);
char m,n;
char str[210]={0};char strl[210]={0};
card tempcard;
layer templayer,deq1,deq2,deqtemp;
chan change;
stack <layer>stac,stacl;
deque<chan>chanctrl;
tempque tempsave;
tempdeq deqsave;
tempcard.num=0;
int i=0,t=0,rec=0,seq=0;
int tt=0;
int prompt=0;
int cou=0;
int z=0,x=0;
int a=0,b=0;
int s=0;
int p=0;
int la=0;
card mmm[209]={0};
while(fin.getline(str,208,'r'))
{
    for(int qq=0;qq<=207;qq++)
    {
        strl[qq]=str[qq];
    }
}
while(strl[i])
{
    if(rec==0&&strl[i]!='#')
    {
    if(strl[i]==' ')
    {i++;//fout<<"HER999999E"<<endl;
    continue;
    }
    else if(strl[i]=='\n')
    {i++;

    // fout<<"i: "<<i<<"  H*******AHA"<<endl;
    stac.push(templayer);
    templayer.clear();
    continue;
    }

    else  if(t==0)
    {
        if(strl[i]=='A')
        {
            seq=1;
        }
        else if(strl[i]=='T')
        {
            seq=10;
        }
        else if(strl[i]=='J')
        {
            seq=11;
        }
        else if(strl[i]=='Q')
        {
            seq=12;
        }
        else if(strl[i]=='K')
        {
            seq=13;
        }
        else
        {
        seq=strl[i]-48;
        }
        tempcard.num=seq;        //  fout<<"tempcard.num="<<tempcard.num<<"     i:"<<i<<endl;
        tempcard.numc=strl[i];
        t=1;
        i++;
        continue;
    }
    else  if(t==1)
    {
    tempcard.suit=strl[i];//fout<<"tempcard.suit;"<<tempcard.suit<<"     i:"<<i<<endl;
    t=0;
    //fout<<templayer[1].num<<endl;
    //fout<<templayer[1].suit<<endl;

    templayer.push_back(tempcard);
    i++;
    continue;
    }


    }





    else if(strl[i]=='#')
    {
    rec=1;
    i++;
    continue;
    }






    else if(rec==1)
    {
    if(strl[i]==' ')
    {
    i++;
    continue;
    }
    else if(strl[i]=='\n')
    {
    i++;
    continue;
    }
    else if(tt==0)
    {//fout<<"strl[i]:"<<str[i]<<endl;
    change.fir=str[i]-48;
    tt=1;
    i++;
    continue;
    }
    else   if(tt==1)
    {
    change.sec=strl[i]-48;
    tt=0;
    // fout<<"change.fir="<<change.fir<<endl<<"change.sec="<<change.sec<<endl;
    chanctrl.push_back(change);
    i++;
    continue;
    }
    }
}//save data





/*
while(!stac.empty())
{
x=0;
   while(x!=(stac.top().size()))
   {
       fout<<stac.top()[x].num<<stac.top()[x].suit<<" ";x++;
   }
fout<<endl;
stac.pop();

}

*/
x=0;
while(x!=(chanctrl.size()))
   {//fout<<"x:  "<<x<<endl;
       deq1.clear();
        deq2.clear();
        deqtemp.clear();
        deqsave.clear();
       while(tempsave.size()!=0)
       {
        tempsave.pop();
       }

       cou=0;
       a=chanctrl[x].fir-1;
       b=chanctrl[x].sec-1;
       //fout<<"a:  "<<a<<"b:   "<<b<<endl;
       while(!stac.empty())
       {
           if((cou!=a)&&(cou!=b))
           {
              tempsave.push(stac.top());
              stac.pop();

       //       fout<<cou<<"queque"<<endl;
           }
           else if(cou==a)
           {
               deq1=stac.top();
            stac.pop();
           if(a>b)
            {   //fout<<"alos"<<endl;
                break;
            }
         //   fout<<cou<<"deq1"<<endl;
           }
           else if(cou==b)
           {
               deq2=stac.top();
               stac.pop();
                if(b>a)
                {  // fout<<"alos"<<endl;
                    break;
                }
             //  fout<<cou<<"deq2"<<endl;
           }
cou++;
          // fout<<"cou:"<<cou<<endl;
       }
       while(!tempsave.empty())
       {
          deqsave.push_front(tempsave.front());
          tempsave.pop();
       }

/*
           p=0;
               fout<<"deq1:s=1  ";
               while(p!=deq1.size())
               {
                   fout<<deq1[p].num<<deq1[p].suit<<" ";
                   p++;
               }
               fout<<endl;
               p=0;
               fout<<"deq2:s=1  ";
                while(p!=deq2.size())
               {
                   fout<<deq2[p].num<<deq2[p].suit<<" ";
                   p++;
               }
               fout<<endl;
*/
       while(deq2.size()!=0)
       {s=0;
//fout<<"deq2size:"<<deq2.size()<<endl;
     /*  fout<<"result1:  "<<((deq2.back().num)==(deq1.back().num))<<endl;
       fout<<"result2:  "<<((deq2.back().suit)==(deq1.back().suit))<<endl;
       fout<<"alloha:   "<<deq2.back().suit<<"           "<<deq1.back().suit<<endl;*/
           if(  (deq2.back().num)==(deq1.back().num)||(deq2.back().suit)==(deq1.back().suit)  )
           {//fout<<"here"<<endl;

               deq1.push_back(deq2.back());
               deq2.pop_back();
               s=0;

/*
               p=0;
               fout<<"deq1:s=0  ";
               while(p!=deq1.size())
               {
                   fout<<deq1[p].num<<deq1[p].suit<<" ";
                   p++;
               }
               fout<<endl;
               p=0;
               fout<<"deq2:s=0  ";
                while(p!=deq2.size())
               {
                   fout<<deq2[p].num<<deq2[p].suit<<" ";
                   p++;
               }
               fout<<endl;*/
//fout<<"deq1front  "<<deq1.front().num<<deq1.front().suit<<endl;fout<<"deq1back  "<<deq1.back().num<<deq1.back().suit<<endl;fout<<"deq2front  "<<deq2.front().num<<deq2.front().suit<<endl;fout<<"deq2back  "<<deq2.back().num<<deq2.back().suit<<endl;
               //cout<<"deq2[deq2.size()-1]:   "<<deq2.back().num<<deq2.back().suit<<endl<<"deq1[deq1.size()-1]:   "<<deq1.front().num<<deq1.front().suit<<endl;cout<<"akakakakakaka"<<endl;
           }

           else if((deq2.back().num)!=(deq1.back().num)&&(deq2.back().suit)!=(deq1.back().suit) )
           {
               deq1.push_front(deq2.back());
               deq2.pop_back();
               s=1;


/*
               p=0;
               fout<<"deq1:s=1  ";
               while(p!=deq1.size())
               {
                   fout<<deq1[p].num<<deq1[p].suit<<" ";
                   p++;
               }
               fout<<endl;
               p=0;
               fout<<"deq2:s=1  ";
                while(p!=deq2.size())
               {
                   fout<<deq2[p].num<<deq2[p].suit<<" ";
                   p++;
               }
               fout<<endl;*/
//fout<<"deq1front  "<<deq1.front().num<<deq1.front().suit<<endl;fout<<"deq1back  "<<deq1.back().num<<deq1.back().suit<<endl;fout<<"deq2front  "<<deq2.front().num<<deq2.front().suit<<endl;fout<<"deq2back  "<<deq2.back().num<<deq2.back().suit<<endl;
           }
/*
           p=0;
               fout<<"deq1:s=1  ";
               while(p!=deq1.size())
               {
                   fout<<deq1[p].num<<deq1[p].suit<<" ";
                   p++;
               }
               fout<<endl;
               p=0;
               fout<<"deq2:s=1  ";
                while(p!=deq2.size())
               {
                   fout<<deq2[p].num<<deq2[p].suit<<" ";
                   p++;
               }
               fout<<endl;*/

//fout<<"deq2size:  "<<deq2.size()<<endl;
       }
//fout<<"s:  "<<s<<endl;


       if(s==0)
       {stac.push(deq1);
           while(deqsave.size()!=0)
           {
            stac.push(deqsave.back());
            deqsave.pop_back();
           //cout<<"s:  "<<s<<endl;
           }

       }
       else if(s==1)
       {
           while(deqsave.size()!=0)
           {

           stac.push(deqsave.back());
           deqsave.pop_back();//cout<<"s:  "<<s<<endl;
           }
stac.push(deq1);
       }



//cout<<"s:  "<<s<<endl;

x++;
}
/*
p=0;
while(!stac.empty())
{//fout<<"8585858585"<<endl;
    while(p!=stac.top().size())
    {
        fout<<stac.top()[p].numc<<stac.top()[p].suit<<" ";p++;

    }
   // fout<<"87878787stac"<<endl;
stac.pop();//fout<<"p:  "<<p;
}*/
la=0;

while(la!=stac.top().size())
{
    mmm[la]=stac.top()[la];
    la++;
}
for(int gf=(la-1);gf>=0;gf--)
{
   fout<<mmm[gf].numc<<mmm[gf].suit<<" ";
}

//p=0;

/*
fout<<deq2[deq2.size()-1].num<<deq2[deq2.size()-1].suit<<endl;

while(siz1)


*/





	fin.close();
	fout.close();
	return 0;
}
