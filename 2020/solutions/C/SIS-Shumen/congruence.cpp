#include <bits/stdc++.h>
using namespace std;
const int maxn=15000010;
struct edge
{
    char c;
    int pos;
};
char in[maxn];
edge c[maxn],ans1[maxn],ans2[maxn];
char congr[256];
int nsz;
void read()
{
    cin>>in;
    nsz=strlen(in);
    ///cout<<in<<endl;
}
///nsz- word's length
void init_c()
{
    for(int i=0;i<nsz;i++)
    {
        c[i].c=in[i];
        c[i].pos=i;
    }
    /*for(int i=0;i<nsz;i++)
        cout<<c[i].c;
    cout<<endl;
    for(int i=0;i<nsz;i++)
        cout<<c[i].pos<<' ';
    cout<<endl;*/
}
bool cmp1(edge d,edge e)
{
    return (d.c<e.c);
}
bool cmp2(edge d,edge e)
{
    return (d.c>e.c);
}
bool cmp3(edge d,edge e)
{
    return (d.pos<e.pos);
}
void solve1()
{
    memset(congr,0,sizeof(congr));
    char thsm='A';
    /// don't used
    for(int i=0;i<nsz;i++)
    {
        if(!congr[c[i].c]){congr[c[i].c]=thsm;thsm++;}
        ans1[i].c=congr[c[i].c];
        ans1[i].pos=c[i].pos;
    }
    /*for(int i=0;i<nsz;i++)
        cout<<ans1[i].c;
    cout<<endl;
    for(int i=0;i<nsz;i++)
        cout<<ans1[i].pos<<' ';
    cout<<endl;*/
    sort(ans1,ans1+nsz,cmp3);
    for(int i=0;i<nsz;i++)
        cout<<ans1[i].c;
    cout<<endl;
}
void solve2()
{
    sort(c,c+nsz,cmp2);
    memset(congr,0,sizeof(congr));
    char thb='Z';
    ///don't used
    for(int i=0;i<nsz;i++)
    {
        if(!congr[c[i].c]){congr[c[i].c]=thb;thb--;}
        ans2[i].c=congr[c[i].c];
        ans2[i].pos=c[i].pos;
    }
    sort(ans2,ans2+nsz,cmp3);
    for(int i=0;i<nsz;i++)
        cout<<ans2[i].c;
    cout<<endl;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    init_c();
    sort(c,c+nsz,cmp1);
    /*for(int i=0;i<nsz;i++)
        cout<<c[i].c;
    cout<<endl;
    /*for(int i=0;i<nsz;i++)
        cout<<c[i].pos<<' ';
    cout<<endl;*/
    solve1();
    solve2();
return 0;
}
/*
KOMAP
BDCAE
WYXVZ
*/
/*
AZBYCX
AFBECD
UZVYWX
*/
/*
AB
AB
YZ
*/
