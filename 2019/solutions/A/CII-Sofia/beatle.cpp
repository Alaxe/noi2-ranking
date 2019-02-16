#include<iostream>
#include<algorithm>
using namespace std;
struct duska
{
    int x;
    int y;
    int l;
} d[100002];
int n,t;
struct topview
{
    int l;
    int res;
    int next;
} fd[200004];
bool cmp(duska x,duska y)
{
    if(x.y == y.y)
    {
        return x.x<y.x;
    }
    else
    {
        return x.y<y.y;
    }
}
int bs(int x1)
{
    /*int bot=0;
    int top=200004;
    int mid=(bot+top)/2;
    while(!(mid<=x1 && fd[mid].next>x1))
    {
        cout<<mid<<endl;
        mid=(bot+top)/2;
        if(mid>=x1)
        {
            top=mid-1;
        }
        else
        {
            if(fd[mid].next>x1)
            {
                break;
            }
            else
            {
                if(mid<x1)
                {
                    bot=mid+1;
                }
            }
        }
    }
    return mid;*/
    for(int i=x1-1; i>=0; i--)
    {
        if(fd[i].next>=x1)
            return i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    d[0].x=0;
    d[0].y=-1;
    d[0].l=0;
    fd[0].next=200004;
    int minx=200004;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i].x>>d[i].y>>d[i].l;
        if(d[i].x<minx)
            minx=d[i].x;
    }
    sort(d,d+n+1,cmp);
    d[n+1].x=200004;
    d[n+1].y=-1;
    d[n+1].l=0;
    /*for(int i=0; i<=n+1; i++)
    {
        cout<<d[i].x<<" "<<d[i].y<<" "<<d[i].l<<endl;
    }*/
    for(int i=1; i<=n; i++)
    {
        fd[d[i].x].l=d[i].l;
        int now=bs(d[i].x);
        int nown=now;
        //cout<<d[i].x<<d[i].l<<endl;
        //cout<<"now 1:"<<now<<"\n";
        bool overlap=false;
        if(fd[now].l+now>=d[i].x)
        {
            if(fd[now].l+now>d[i].x+d[i].l)
            {
                fd[d[i].x+d[i].l].l=fd[now].l+now-d[i].x-d[i].l;
                fd[d[i].x+d[i].l].res=fd[now].res;
                fd[d[i].x+d[i].l].next=fd[now].next;
                fd[d[i].x].next=d[i].x+d[i].l;
                overlap=true;
            }
            fd[now].l=d[i].x-now;
            //fd[now].next=d[i].x;
            fd[d[i].x].res=fd[now].res+1;
        }
        else
        {
            //fd[now].next=d[i].x;
            fd[d[i].x].res=1;
        }
        now=bs(d[i].x+d[i].l);
        //cout<<"now 2:"<<now<<"\n";
        if(overlap==0)
            if(fd[now].l+now>d[i].x+d[i].l)
            {
                fd[d[i].x+d[i].l].l=fd[now].l+now-d[i].x-d[i].l;
                fd[d[i].x+d[i].l].res=fd[now].res;
                fd[d[i].x+d[i].l].next=fd[now].next;
                fd[d[i].x].next=d[i].x+d[i].l;
                if(fd[d[i].x].res!=0)
                {
                    fd[d[i].x].res=min(fd[d[i].x].res,fd[now].res+1);
                }
                else
                {
                    fd[d[i].x].res=fd[now].res+1;
                }
                if(d[i].x+d[i].l!=now)
                {
                    fd[now].l=0;
                    fd[now].res=0;
                    fd[now].next=0;
                }
            }
            else
            {
                fd[d[i].x].next=fd[now].next;
                if(now>=d[i].x)
                {
                    fd[now].l=0;
                    fd[now].res=0;
                    fd[now].next=0;
                }
            }
        fd[nown].next=d[i].x;
        for(int j=d[i].x+d[i].l-1; j>d[i].x; j--)
        {
            fd[j].l=0;
            fd[j].res=0;
            fd[j].next=0;
        }
        /*for(int j=0; j<15; j++)
        {
            cout<<j<<" "<<fd[j].l<<" "<<fd[j].next<<" "<<fd[j].res<<endl;
        }
        cout<<"end\n";*/
    }
    cin>>t;
    for(int i=0; i<t-1; i++)
    {
        int a;
        cin>>a;
        if(a<minx)
            cout<<"0 ";
        else
        {
            for(int i=a; i>0; i--)
            {
                if(fd[i].l>0)
                {
                    if(fd[i].l+i>a)
                    {
                        cout<<fd[i].res<<" ";
                        break;
                    }
                    else
                    {
                        cout<<"0 ";
                        break;
                    }
                }
            }
        }
    }
    int a;
    cin>>a;
    if(a<minx)
        cout<<"0\n";
    else
    {
        for(int i=a; i>=0; i--)
        {
            if(fd[i].l>0)
            {
                if(fd[i].l+i>a)
                {
                    cout<<fd[i].res<<endl;
                    break;
                }
                else
                {
                    cout<<"0\n";
                    break;
                }
            }
        }
    }
    return 0;
}
/**
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
0 2 13 4 5

*/
