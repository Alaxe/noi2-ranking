#include<iostream>
#include <algorithm>
using namespace std;
string mul(string s,int x)
{
    int n=s.size();
    reverse(s.begin(),s.end());
    int p=0;
    for(int i=0;i<n;i++)
    {
        int c=s[i]-'0';
        c*=x;
        c+=p;
        p=c/10;
        c%=10;
        s[i]=char(c+'0');
    }
    if(p) s+=char(p+'0');
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.size();
    string s1="",x="2"; int st=1,br=1;
    while(br<n)
    {
        x=mul(x,2); st++;
        s1+=x; br+=x.size();
    }cout<<st<<endl;
    return 0;
}
