#include<iostream>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;
struct str
{
   char l;
   int num;
}m[15000002];
bool cmp(str a,str b)
{
    if(a.l==b.l) return a.num<b.num;
    return a.l<b.l;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c,ma='A';
    string s1,s2;
    int k=0,i;
    while(cin>>c)
    {
        m[k].l=c;
        m[k].num=k;
        k++;
    }
    sort(m,m+k,cmp);
    s1.resize(k);
    s2.resize(k);

    s1[m[0].num]='A';
    for(i=1;i<k;i++)
    {
        if(m[i-1].l==m[i].l) s1[m[i].num]=(s1[m[i-1].num]);
        else s1[m[i].num]=(s1[m[i-1].num]+1);

        ma=max(ma,s1[m[i].num]);
    }

    for(i=0;i<k;i++)
    {
        s2[i]='Z'-(ma-s1[i]);
    }
cout<<s1<<endl;
cout<<s2<<endl;
return 0;
}
