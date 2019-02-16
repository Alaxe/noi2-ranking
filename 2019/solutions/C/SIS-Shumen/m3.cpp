#include<iostream>
using namespace std;
struct sector
{
    int x,y,z;
    double sum,f=0,snd=0,t=0,fo=0;
};
int s,st[4];
/*a e st[0]
b e st[1]
c e st[2]
d e st[3]
*/
long long k;
sector se[100010],ls;
void init_se()
{
    int e,i;
    for(i=0;i<s;i++)
    {
        e=i+1;
        if(k)
        {
            se[i].sum=(k>d*4)?d*4:k;
            k-=se[i].sum;
            ls=se[i];
        }
        else se[i].sum=0;
        if(e%4==1)
        {
            se[i].x=a;
            se[i].y=c;
            se[i].z=b;
        }
        else if(e%4==2)
            {
                se[i].x=b;
                se[i].y=a;
                se[i].z=c;
            }
        else if(e%4==3)
            {
                se[i].x=b;
                se[i].y=c;
                se[i].z=a;
            }
        else
        {
            se[i].x=c;
            se[i].y=a;
            se[i].z=b;
        }
    }
}
void solve()
{
    if(ls.sum==d*4)
    {
        cout<<d<<".000 ";
        cout<<d<<".000 ";
        cout<<d<<".000 ";
        cout<<d<<".000"<<endl;
        return;
    }
    /*float p;
    ls.f=ls.sum;
    if(ls.f<=ls.x)return;
    ls.f=ls.x;
    ls.sum-=x;
    ls.snd=ls.sum;
    int m=min(ls.x,ls.y);
    if(se.snd<=m)return;
    if(m==ls.y)
    {
        ls.snd=ls.y;
        ls.sum-=ls.y;
        ls.t=ls.sum;
        m=min(ls.y,ls.z);
        if(ls.t<=m)return;
        if(m==ls.z)
        {
            ls.t=ls.z;
            ls.sum-=ls.z;
            ls.fo=ls.sum;
            if(ls.fo<=ls.z)return;
            p=ls.fo-z;
            ls.sum+=p;
            ls.fo=z;
            p/=2;
            ls.t+=p;
            ls.fo+=p;
            ls.sum-=(p*2)
            if(ls.t<=ls.y)return;
            p=ls.t-ls.y;
            ls.sum+=p*2;
            ls.t-=ls.y;
            ls.fo-=ls.y;
            p*=2;p/=3;
            ls.snd+=p;
            ls.t+=p;
            ls.fo+=p;
            ls.sum-=(p*3);
            if(ls.snd<=ls.x)return;
            p=ls.snd-ls.x;
            ls.sum+=p*3;
            ls.snd=ls.x;
            ls.t=ls.x;
            ls.fo=ls.x;
            p*=3;p/=4;
            ls.f+=p;
            ls.snd+=p;
            ls.t+=p;
            ls.fo+=p;
            return;
        }
        ///m e ls.y
        p=ls.t-ls.y;
        ls.t=ls.y;
        p/=2;
        ls.snd+=p;
        ls.t+=p;
        ls.sum-=(p*2);
        m=min(x,z);
        if(ls.t<=m)return;
        if(m==ls.z)
        {
            ls.fo=ls.sum;
            ls.sum-=ls.z;
            if(ls.fo<=ls.z)return;
            p=ls.fo-ls.z;
            ls.sum+=p;
            p/=3;
            ls.snd+=p;
            ls.t+=p;
            ls.fo+=p;
            ls.sum-=(p*3);
            if(ls.snd<=ls.x)return;
            p=ls.snd-ls.x;
            ls.sum+=p*3;
            ls.snd=ls.x;
            ls.t=ls.x;
            ls.fo=ls.x;
            p*=3;p/=4;
            ls.f+=p;
            ls.snd+=p;
            ls.t+=p;
            ls.fo+=p;
            return;
        }
        p=ls.snd-ls.x;
        ls.snd=ls.x;
        ls.t=ls.x;
        p/=3;
        ls.f+=p;
        ls.snd+=p;
        ls.t+=p;
        if(ls.f<=la.z)return;
        p=ls.f-ls.x;
        ls.f=ls.z;
        ls.snd=ls.z;
        ls.t=ls.z;
        ls.z+=(p*4);
        ///+ samo ls.z zashtoto samo toi ne e palen
        return;
    }
    p=ls.snd-ls.y;
    ls.snd=ls.x;
    p/=2;
    ls.f+=p;
    ls.snd+=p;
    if(ls.snd<=ls.y)return;
    p=ls.snd-ls.y;
    ls.f=ls.y;
    ls.snd=ls.y;
    ls.t=p*2;
    if(ls.y>ls.z)
    {
        if(ls.t<=ls.z)return;
        p=ls.t-ls.z;
        ls.t=ls.z;
        ls.fo=p;
        if(ls.fo<=ls.z)return;
        p=ls.fo-ls.z;
        ls.fo=ls.z;
        p/=2;
        ls.fo+=p;
        ls.t+=p;
        if(ls.t<=ls.y)return;
        p=(ls.t-ls.y)*2;
        ls.t=ls.y;
        ls.fo=ls.y;
        p/=4;
        ls.f+=p;
        ls.snd+=p;
        ls.t+=p;
        ls.fo+=p;
        return;
    }
    if(ls.t<=ls.y)return;
    p=ls.t-ls.z;
    ls.t=ls.y;
    p/=3;
    ls.t+=p;
    ls.snd+=p;
    ls.f+=p;
    if(ls.t<=ls.z)return;
    p=ls.t-ls.z;
    p*=3;
    ls.t=ls.z;
    ls.snd=ls.z;
    ls.f=ls.z;
    p/=4;
    ls.f+=p;
    ls.snd+=p;
    ls.t+=p;
    ls.fo+=p;
    return;*/
}
void print()
{

}
int main()
{
    cin>>s>>k;
    for(int i=0;i<4;i++)
        cin>>st[i];
    init_se();
    solve();
    print();
    return 0;
}

