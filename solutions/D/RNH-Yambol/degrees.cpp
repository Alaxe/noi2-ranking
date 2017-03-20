#include<iostream>
#include<string>
using namespace std;
string eq(string x)
{
    string r="";
    char c;
    long long i,s,rem=0;
    for(i=x.size()-1; i>=0; i--)
    {
        s=(x[i]-'0')*2+rem;
        rem=s/10;
        c=(s%10)+'0';
        r=c+r;
    }
    if(rem) r=char(rem+'0')+r;
    return r;
}
int main()
{
    long long n=1;
    string i,c="2";
    cin>>i;
    while(true)
    {
        if(i.find(c)>=i.size()) break;
        c=eq(c);
        n++;
    }
    cout<<n-1<<endl;
    return 0;
}
