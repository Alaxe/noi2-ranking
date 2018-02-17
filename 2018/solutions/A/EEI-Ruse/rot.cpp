#include<iostream>
#include<vector>
using namespace std;
int b;
const int MAX_N=60100;
const int DPD=8; //digits per digit
const long long BASE=1e8;
int num[MAX_N];
int numsize;
int res[MAX_N];
int ressize;
int curr[2][MAX_N];
int currsize[2];
string input;
int rem;
string digits="0123456789ABCDEF";
void divide(const int p[], int& psize, int res[], int& ressize, int q, int base)
{
    bool first=1;
    rem=0;
    int curr=0;
    ressize=0;
    for (int i=psize-1;i>=0;--i)
    {
        rem*=base;
        rem+=p[i];
        curr=rem/q;
        rem%=q;
        if (first==0 || curr>0)
        {
            res[ressize++]=curr;
            first=0;
        }
    }
    for (int i=0;i<ressize/2;++i)
    {
        swap(res[i],res[ressize-i-1]);
    }
}
void allIncrement(int p[], int& psize, int base)
{
    int carry=0;
    for (int i=0;i<psize;++i)
    {
        int& c=p[i];
        c=c+carry+1;
        carry=c/b;
        c%=b;
    }
    while (carry)
    {
        p[psize++]=(1+carry)%b;
        carry=(1+carry)/b;
    }
    p[psize++]=1;
}
void solve()
{
    numsize=0;
    long long mult;
    for (int i=input.size()-1;i>=0;i-=DPD)
    {
        mult=1;
        num[numsize]=0;
        for (int j=0;j<DPD && i-j>=0;++j)
        {
            num[numsize]+=(input[i-j]-'0')*mult;
            mult*=10;
        }
        ++numsize;
    }
    divide(num,numsize,res,ressize,b-1,BASE);
    if (rem)
    {
        cout<<"0\n";
        return;
        return;
        //2 break-a sa nujni maj
        //malko e prechupvane na misylta
        //othvyrlqne na tradicionnite dogmi
    }
    numsize=0;
    currsize[0]=ressize;
    for (int i=0;i<ressize;++i)
    {
        curr[0][i]=res[i];
    }
    bool c=0;
    while (currsize[c]>0)
    {
        c=!c;
        divide(curr[!c],currsize[!c],curr[c],currsize[c],b,BASE);
        num[numsize++]=rem;
    }
    allIncrement(num,numsize,b);
    for (int i=numsize-1;i>=0;--i)
    {
        cout<<digits[num[i]];
    }
    cout<<"\n";
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>b;
    for (int i=0;i<4;++i)
    {
        cin>>input;
        solve();
    }
    return 0;
}
