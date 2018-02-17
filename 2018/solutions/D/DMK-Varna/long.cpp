#include <bits/stdc++.h>
using namespace std;
string fun(string k, string t)
{
    string s;
    long long pr=0,st,i;
    while (t.size()<k.size())t='0'+t;
    for (i=k.size()-1;i>=0;i--)
    {
        st=(t[i]-'0')+(k[i]-'0')+pr;
        if (st>=10){st%=10;pr=1;}
        else pr=0;
        s+=(st+'0');
    }
    if (pr==1)s=s+'1';
    reverse (s.begin(),s.end());

    return s;
}
int main()
{
    long long n,i=0,br=0;
    string k,t,f,ch[100000];
    cin>>n>>k;
    for (i=0;i<k.size();i++)
    {
      t+=k[i];
    }
    for (i=0;;i++)
    {
        ch[i]=k;
        if (fun(k,k).size()>=n)
        {
            k=fun(k,t);
            if (k.size()>=n)break;
        }
        else k=fun(k,k);

    }
    cout<<k<<endl;


}
