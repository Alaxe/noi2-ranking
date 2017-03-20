#include<iostream>
#include<string>
using namespace std;
string s1, s2, s3, s4;
int a[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int toint(string x)
{
    int res=0;
    for(int i=0;i<x.size();i++)
        res=res*10+int(x[i]-'0');
    return res;
}
int from1jan(string s)
{
    int pos=s.find('/');
    int p1, p2;
    int sum=0;
    string k;
    k=s.substr(0, pos);
    p1=toint(k);
    k=s.substr(pos+1, s.size()-pos-1);
    p2=toint(k);
    for(int i=1;i<=p2-1;i++)
        sum+=a[i];
    sum+=p1;
}
int main()
{
    cin>>s1>>s2>>s3>>s4;
    int t1=from1jan(s1), t2=from1jan(s2), t3=from1jan(s3), t4=from1jan(s4);
    if(t1==t2&&t2==t3&&t3==t4){cout<<21252<<endl; return 0;}
    return 0;
}
