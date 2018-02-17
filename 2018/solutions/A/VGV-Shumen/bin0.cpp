#include <iostream>
#include <cstdio>
#include <stack>
#include<vector>
using namespace std;
long long int s,t;
int z;
stack<int> st;
vector<int> v,v1;
bool Bit1(long long int x)
{
    int br=0;
    while(x!=0)
    {
        if(x%2==0) br++;
        if(br>z) return 0;
        x/=2;
    }
    if(br==z) return 1;
    else return 0;
}
void Bit(long long int x)
{
    while(x!=0)
    {
        st.push(x%2);
        x/=2;
    }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
}
void Bit2(long long int x)
{
    while(x!=0)
    {
        st.push(x%2);
        x/=2;
    }
    while(!st.empty())
    {
        v1.push_back(st.top());
        st.pop();
    }
}
long long int Comb(int a, int b)
{
    long long int otg=1;
    for(int i=a;i>=a-b+1;i--)
    {
        otg*=i;
    }
    for(int i=b;i>1;i--)
    {
        otg/=i;
    }
    return otg;
}
void Resh1()
{
    long long int i,otg=0;
    for(i=s;i<=t;i++)
    {
        otg+=Bit1(i);
    }
    cout<<otg<<endl;
}
long long int  Resh3()
{
    long long int otg=0;
    Bit(t);
    int log=v.size();
    log-=2;
    while(log>=z)
    {
        otg+=Comb(log,z);
        log--;
    }
    otg+=Comb(v.size()-1,z);
    int temp=z;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==0)
        {
            temp--;
            otg-=Comb(v.size()-i-1,temp);
        }
    }
    Bit2(s);
    log=v1.size();
    log-=2;
    while(log>=z)
    {
        otg-=Comb(log,z);
        log--;
    }
    temp=z;
    for(int i=1;i<v1.size();i++)
    {
        if(v1[i]==1)
        {
            temp--;
            otg-=Comb(v1.size()-i-1,temp);
        }
    }
   cout<<otg;
}
void Read()
{
    cin>>s>>t>>z;
    if(t-s<=10000000) Resh1();
    else Resh3();
}
int main()
{
    Read();
    return 0;
}
