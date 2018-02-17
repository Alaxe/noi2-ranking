#include<iostream>
using namespace std;
string sum(string s1, string s2)
{
    int sz1=s1.size(), sz2=s2.size();
    if(sz1<sz2)
        while(sz1!=sz2)
        sz1++, s1="0"+s1;
    else
        while(sz1!=sz2)
        sz2++, s2="0"+s2;
    string res="";
    char dig;
    int rem=0, sum;
    for(int i=sz1-1;i>=0;i--)
    {
        sum=(s1[i]-'0')+(s2[i]-'0')+rem;
        rem=sum/10; dig=sum%10+'0';
        res=dig+res;
    }
    if(rem) res='1'+res;
    return res;
}
string mult1(string s1, int d)
{
    int sz=s1.size();
    int rem=0, sum;
    string res="";
    char dig;
    for(int i=sz-1;i>=0;i--)
    {
        sum=(s1[i]-'0')*d+rem;
        rem=sum/10; dig=sum%10+'0';
        res=dig+res;
    }
    if(rem)
    {
        dig=rem+'0';
        res=dig+res;
    }
    return res;
}
string mult2(string s1, int n)
{
    int sz=s1.size();
    string res="0";
    int br=0;
    while(n>0)
    {
        int dig=n%10;
        string ss=mult1(s1, dig);
        for(int i=0;i<br;i++)
            ss=ss+"0";
        res=sum(res, ss);
        n/=10;
        br++;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    string fact="1";
    for(int i=1;i<=n;i++)
        fact=mult2(fact, i);
    long long sum=0;
    for(int i=0;i<fact.size();i++)
        sum+=fact[i]-'0';
    cout<<sum<<endl;
    return 0;
}
