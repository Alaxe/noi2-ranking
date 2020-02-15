#include<iostream>
#include<map>
#include<vector>
#include<deque>
#define MAXN 100005
using namespace std;

int a[MAXN],b[MAXN];
map<string, int> mapa, mapb;
int r1, r2;
int k;
deque<int> qu;

string turnttostr (int a)
{
    string ans="";
    while(a>0)
    {
        ans=ans +  char(a%10+'0');
        a/=10;
    }
    return ans;
}

string turnqutostr()
{
    int a;
    string ans="";
    for(int i=0; i<qu.size(); i++)
    {
        a=qu.front();
        qu.push_back(qu.front());
        qu.pop_front();

        ans=ans + ','+turnttostr(a);
    }
    return ans;

}
vector<string> strs;
int addtomapA()
{
    string str = turnqutostr();
    mapa[str]++;
    if(mapa[str]==1) strs.push_back(str);
}


int addtomapB()
{
    string str = turnqutostr();
    mapb[str]++;
}

int finda1()
{
    while(!qu.empty()) qu.pop_back();
    for(int i=0; i<r1; i++)
    {
        if(qu.empty())
        {
            qu.push_back(a[i]);
            continue;
        }
        if(qu.back()>=a[i])
        {
            while(!qu.empty()) qu.pop_back();
            qu.push_back(a[i]);
            continue;
        }
        qu.push_back(a[i]);
        if(qu.size()==k)
        {
            addtomapA();
            qu.pop_front();
        }
    }
}

int finda2()
{
    while(!qu.empty()) qu.pop_back();
    for(int i=0; i<r1; i++)
    {
        if(qu.empty())
        {
            qu.push_back(a[i]);
            continue;
        }

        if(qu.back()!=a[i])
        {
            while(!qu.empty()) qu.pop_back();
            qu.push_back(a[i]);
            continue;
        }
        qu.push_back(a[i]);
        if(qu.size()==k)
        {
            addtomapA();
            qu.pop_front();
        }
    }
}



int findb1()
{
    while(!qu.empty()) qu.pop_back();
    for(int i=0; i<r2; i++)
    {
        if(qu.empty())
        {
            qu.push_back(b[i]);
            continue;
        }

        if(qu.back()>=b[i])
        {
            while(!qu.empty()) qu.pop_back();
            qu.push_back(b[i]);
            continue;
        }
        qu.push_back(b[i]);
        if(qu.size()==k)
        {
            addtomapB();
            qu.pop_front();
        }
    }
}

int findb2()
{
    while(!qu.empty()) qu.pop_back();
    for(int i=0; i<r2; i++)
    {
        if(qu.empty())
        {
            qu.push_back(b[i]);
            continue;
        }
        if(qu.back()!=b[i])
        {
            while(!qu.empty()) qu.pop_back();
            qu.push_back(b[i]);
            continue;
        }
        qu.push_back(b[i]);
        if(qu.size()==k)
        {
            addtomapB();
            qu.pop_front();
        }
    }
}




int main()
{

    int type;
    cin>>type>>k;
    cin>>r1;
    for(int i=0; i<r1; i++)
    {
        cin>>a[i];
    }
    cin>>r2;
    for(int i=0; i<r2; i++)
    {
        cin>>b[i];
    }

    if(r1<k||r2<k)
    {
        cout<<0<<endl;
        return 0;
    }

    if(type==1) //razl
    {
        finda1();

        //   cout<<"START B"<<endl;
        findb1();
    }

    if(type==2)//edn
    {

        finda2();
        findb2();
    }
    long long anss=0;
    for(int i=0; i<strs.size(); i++)
    {
        //cout<<strs[i]<<endl;;
        anss = anss+ mapa[strs[i]]*mapb[strs[i]];
    }
    cout<<anss<<endl;
}


/**


1 2
6
3 6 1 3 6 7
6
2 1 3 4 3 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7


2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6


*/
