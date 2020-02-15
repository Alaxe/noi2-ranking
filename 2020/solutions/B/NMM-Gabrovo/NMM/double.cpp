#include<iostream>
using namespace std;

int n, w1, w2;
int el[224];
int answ=0;
int mem[224][224][224];

int solve(int b1, int b2, int p)
{
    if(mem[b1][b2][p]) return mem[b1][b2][p];
    //cout<<b1<<" "<<b2<<" "<<p<<endl;
    if(p==n)
    {
        return (b1+b2);
    }
    else
    {
        int sum=0, bestSum=0;

        if(b1+el[p]<=w1)
        {
            sum=solve(b1+el[p], b2, p+1);
            if(sum>bestSum) bestSum=sum;
        }
        if(b2+el[p]<=w2)
        {
            sum=solve(b1, b2+el[p], p+1);
            if(sum>bestSum) bestSum=sum;
        }

        sum=solve(b1, b2, p+1);
        if(sum>bestSum) bestSum=sum;

        mem[b1][b2][p]=bestSum;
        return bestSum;
    }
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>w1>>w2;
    for(int i=0; i<n; ++i)
    {
        cin>>el[i];
    }

    cout<<solve(0, 0, 0)<<endl;

    return 0;
}

