#include<iostream>
#include<string>
using namespace std;
long long int n;
long long int md;
string s,c;
int szs;
int ans;
void check(string x)
{
    long long int q=0;
    for(int i=0;i<x.size();i++)
    {
        q*=10;
        q+=x[i]-'0';
    }
    if(q%n==0)ans++;
}
void f1(int x)
{
    if(x>=szs)return;
    for(int i=x;i<szs;i++)
    {
        c+=s[i];
        check(c);
        f1(i+1);
        c.erase(c.size()-1);
    }
}
int main()
{
    cin>>s;
    cin>>n>>md;
    szs=s.size();
    f1(0);
    cout<<ans%md<<endl;
    return 0;
}
