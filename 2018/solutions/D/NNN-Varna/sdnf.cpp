#include <bits/stdc++.h>
using namespace std;
long long sumc(string x);
long long conv(string x);
string convts(long long x);
string fctr(string x);
string addstr(string a, string b);
string mulstr(string a, string b);
int main()
{
    string n;
    cin >> n;
    cout << sumc(fctr(n)) << endl;
}
long long sumc(string x)
{
    long long res=0;
    for (long long i=0; i<x.size(); i++) res+=(int)(x[i]-'0');
    return res;
}
long long conv(string x)
{
    long long res=0;
    for (long long i=0; i<x.size(); i++) res*=10, res+=(int)(x[i]-'0');
    return res;
}
string convts(long long x)
{
    string res;
    while (x!=0) res=(char)(x%10+'0')+res, x/=10;
    return res;
}
string fctr(string x)
{
    string res="1";
    for (long long i=2; i<=conv(x); i++) res=mulstr(convts(i), res);
    return res;
}
string addstr(string a, string b)
{
    string res;
    int tmp, prenos=0;
    while (a.size()<b.size()) a="0"+a;
    while (b.size()<a.size()) b="0"+b;
    for (long long i=a.size()-1; i>=0; i--)
    {
        tmp=(int)(a[i]-'0')+(int)(b[i]-'0')+prenos;
        prenos=tmp/10;
        res=(char)(tmp%10+'0')+res;
    }
    if (prenos) res=(char)(prenos+'0')+res;
    return res;
}
string mulstr(string a, string b)
{
    string res, tempres;
    int tmp, prenos=0;
    for (long long j=b.size()-1; j>=0; j--)
    {
        for (long long i=a.size()-1; i>=0; i--)
        {
            tmp=(int)(a[i]-'0')*(int)(b[j]-'0')+prenos;
            prenos=tmp/10;
            tempres=(char)(tmp%10+'0')+tempres;
        }
        if (prenos) tempres=(char)(prenos+'0')+tempres;
        for (long long i=0; i<b.size()-j-1; i++) tempres+="0";
        res=addstr(res, tempres);
        tempres="";
        prenos=0;
    }
    return res;
}
