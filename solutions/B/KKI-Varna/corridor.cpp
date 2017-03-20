#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int dyl,a;
    int typ,tl;
};

vector<node> v;
long long ans=0;
int cmp(node a, node b)
{
    if(a.a!=b.a)return a.a<b.a;
    if(a.typ!=b.typ) return a.typ<b.typ;
    return a.dyl>b.dyl;
}
struct tap
{
    int pos,st,tl;

};
int operator< (tap a, tap b)
{
    if(a.st!=b.st)return a.st<b.st;
    return a.pos>b.pos;
}
priority_queue<tap> pq;

void fun()
{
    ans=0;
    tap o;
    int pos=0;
    int prevpos=0;
    for(int i=0; i<v.size(); i++)
    {
        if(pq.empty())
        {
            if(v[i].typ==-1)continue;
            o.pos=v[i].a;
            o.st=v[i].dyl;
            o.tl=v[i].tl;
            pq.push(o);
        }
        ////cot<<"i:"<<i<<" pos:"<<pos<<" st:"<<o.st<<endl;
        o=pq.top();
        if(v[i].typ==1)
        {
            if(pos!=prevpos)
            {
               //cout<<"ans:"<<ans<<" pos:"<<pos<<" prevpos:"<<prevpos<<" "<<o.st<<"tl: "<<o.tl<<endl;
                ans=ans+(pos-prevpos)*o.st;
            }
            prevpos=pos;
            pos=v[i].a;
            o.pos=v[i].a;
            o.st=v[i].dyl;
            o.tl=v[i].tl;
            pq.push(o);
            continue;
        }
    while(o.tl>pos&&!pq.empty())
        {
            pq.pop();
            if(pq.empty())break;
            o=pq.top();
        }
        if(pq.empty())continue;
        if(pos!=prevpos)
        {
            ans=ans+(pos-prevpos)*o.st;
          //  //cot<<ans<<endl;
        }
        prevpos=pos;
        pos=v[i].a;

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int w,h,n;
    cin>>w>>h;
    cin>>n;
    int d,a,d1,a1,beg,en;
    cin>>d>>a;
    //if(d>a)swap(d,a);
    node t;
    ////cot<<"Here"<<endl;
    for(int i=1; i<n; i++)
    {
        cin>>d1>>a1;
       // //cot<<"TRY "<<d1<<" "<<d<<endl;
        //if(d1>a1)swap(d1,a1);
        if(d1==d)
        {

            //cot<<d1<<endl;
            beg=min(a1,a);
            en=max(a1,a);
            t.typ=1;
            t.dyl=d;
            t.a=beg;
            t.tl=en;
            v.push_back(t);
            t.typ=-1;
            t.dyl=d;
            t.a=en;
            v.push_back(t);
        }
        d=d1;
        a=a1;
    }

    sort(v.begin(),v.end(),cmp);/*
    //cot<<"----------------------------------------------------"<<endl;
    for(int i=0; i<v.size(); i++)
    {
        //cot<<v[i].a<<" "<<v[i].tl<<" "<<v[i].dyl<<" "<<v[i].typ<<" "<<endl;
    }
    //cot<<"----------------------------------------------------"<<endl;*/
    fun();
    cout<<w*h-ans<<endl;

}

/**
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10






*/
