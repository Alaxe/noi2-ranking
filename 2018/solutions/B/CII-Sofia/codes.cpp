///FINAL SLOW
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned long long n,k,a,b;
unsigned long long maxsum;
vector<char>digs;
//vector<char>digs1;
vector<string>p;
//vector<string>p1;
string largest;
vector<string> generate(vector<string>prev, vector<char>digits)
{
    vector<string> next;
    for(int i=0; i<digits.size(); i++)
    {
        if(i%2==0)
        {
            for(int j=0; j<prev.size(); j++)
            {
                next.push_back(digits[i]+prev[j]);
                //cout<<next[j]<<" ";
            }
        }
        else
        {
            for(int j=prev.size()-1; j>=0; j--)
            {
                next.push_back(digits[i]+prev[j]);
                //cout<<next[j]<<" ";
            }
        }
    }
    return next;
}
bool is_larger(string x,string y)
{
    if(x.size()==y.size())
    {
        int j=0;
        int l=x.size();
        while(j<l)
        {
            if(x[j]!=y[j])
                break;
            j++;
        }
        if(x[j]>y[j])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(x.size()>y.size())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int sumdig(string x)
{
    int sum=0;
    int l=x.size();
    for(int j=0; j<x.size(); j++)
    {
        sum+=(x[j]-'0');
    }
    return sum;
}
int main()
{
    largest="0";
    cin>>n>>k>>a>>b;
    char c;
    for(int i=0; i<n; i++)
    {
        cin>>c;
        digs.push_back(c);
        string cc="";
        if(c=='0')
            cc="0";
        if(c=='1')
            cc="1";
        if(c=='2')
            cc="2";
        if(c=='3')
            cc="3";
        if(c=='4')
            cc="4";
        if(c=='5')
            cc="5";
        if(c=='6')
            cc="6";
        if(c=='7')
            cc="7";
        if(c=='8')
            cc="8";
        if(c=='9')
            cc="9";

        p.push_back(cc);
        //cout<<cc<<" ";
    }
    /*unsigned long long prod=1;
    for(int i=1;i<=n;i++)
    {
        prod=i;
        for(int j=0;j<k-1;j++)
            prod*=k;
        if(prod>=a)
        {
            prod=i-1;
            break;
        }
    }
    int w=prod;
    for(int j=0;j<k-1;j++)
    {
        prod*=k;
    }
    unsigned long long prod1=prod;
    for(int i=1;i<=n;i++)
    {
        prod=i;
        for(int j=0;j<k-1;j++)
            prod*=k;
        if(prod>=b)
        {
            prod=i;
            break;
        }
    }
    int t=prod;
    //cout<<w<<" "<<t;
    a-=prod1;
    b-=prod1;
    for(int i=w;i<t;i++)
    {
        digs.push_back(digs1[i]);
    }*/
    //cout<<p1[0];
    for(int i=0; i<k-1; i++)
    {
        p=generate(p,digs);
    }
    //for(int i=0;i<p1.size();i++)
    //cout<<p1[i]<<endl;
    int prev=sumdig(p[a-1]);
    for(int i=a-1; i<b; i++)
    {
        if(is_larger(p[i],largest))
        {
            largest = p[i];
            //cout<<largest<<endl;
        }
        if(i>a-1)
        {
            int now=sumdig(p[i]);
            if(abs(now-prev)>maxsum)
                maxsum=abs(now-prev);
            prev=now;
        }
    }
    cout<<largest<<" "<<maxsum<<endl;
    return 0;
}
/**
3 2 3 5
7 1 5


3 3 10 16
7 1 5
*/
