#include<iostream>
#include<string>
using namespace std;
string s;
int sz,ans;
char a[128];
void check(int x)
{
    if(x==0)return;
    int l=0,r=x-1;
    while(l<=r)
    {
        if(a[l]!=a[r])return;
        l++;
        r--;
    }
    ans++;
}
void f1(int x,int y)
{
   // cout<<x<<" "<<y<<" "<<sz<<endl;
    if(x==sz)
    {
        check(y);
        return;
    }
    f1(x+1,y);
    a[y]=s[x];
    f1(x+1,y+1);
}
int main()
{
    cin>>s;
    sz=s.size();
    f1(0,0);
    cout<<ans<<endl;
    return 0;
}
