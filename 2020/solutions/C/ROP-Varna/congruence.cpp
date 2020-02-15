#include<iostream>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;
struct point
{
    long long num,let;
};
point m[15000005];
bool used[1000];
bool cmp(point a,point b)
{
    if(a.let==b.let)return a.num<b.num;
    return a.let<b.let;
}
string s,rez,rez2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long i,n;

    cin>>s;

    n=s.size();
    rez.resize(n);
    rez2.resize(n);

    for(i=0;i<n;i++)
    {
        m[i].num=i;
        m[i].let=(s[i]-'A');
        used[s[i]-'A']=1;
    }
    sort(m,m+n,cmp);
    long long br=0,bru=0;
    for(i=0;i<40;i++)
    {
        if(used[i])bru++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=0 && m[i].let!=m[i-1].let)br++;
        rez[m[i].num]=char('A'+br);
        rez2[m[i].num]=char('Z'-bru+br+1);


    }
    cout<<rez<<endl;
    cout<<rez2<<endl;

}
