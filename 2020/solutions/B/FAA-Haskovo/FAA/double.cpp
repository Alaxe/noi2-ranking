#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n,w1,w2;
int t[205];
int maxsum;

bool cmp(int a,int b)
{
    if(a!=b) return a>b;
}

int go(int i,int sum1,int sum2)
{
    if(i==n-1)
    {
        if(sum1+t[i]<=w1) sum1=sum1+t[i];
        else if(sum2+t[i]<=w2) sum2=sum2+t[i];
        return sum1+sum2;
    }
    if(sum1+t[i]<=w1&&sum2+t[i]<=w2) return max(max(go(i+1,sum1+t[i],sum2),go(i+1,sum1,sum2+t[i])),go(i+1,sum1,sum2));
    if(sum1+t[i]<=w1) return max(go(i+1,sum1+t[i],sum2),go(i+1,sum1,sum2));
    if(sum2+t[i]<=w2) return max(go(i+1,sum1,sum2+t[i]),go(i+1,sum1,sum2));
    return go(i+1,sum1,sum2);
}

int main()
{
    cin>>n>>w1>>w2;
    if(w1<w2) swap(w1,w2);
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    sort(t,t+n,cmp);
    maxsum=go(0,0,0);

    cout<<maxsum<<"\n";

    return 0;
}
