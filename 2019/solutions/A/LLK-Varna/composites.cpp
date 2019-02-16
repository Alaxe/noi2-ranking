#include<iostream>
#include<vector>
using namespace std;
bool notPrime[10000000]={false};
vector<int> prime;
long long n;
int br=0;
void eratosten()
{
    notPrime[0]=true;
    notPrime[1]=true;
    for(int a=2; a<10000000; a++)
    {
        if(notPrime[a]==true)
            continue;
        prime.push_back(a);
        br++;
        if(a>46000)continue;
        for(int b=a*a; b<10000000; b+=a)
            notPrime[b]=true;
    }
}
int main()
{
    eratosten();

    cin>>n;
    long long mx=1,g=n;
    while(g>0)
    {
        g/=10;
        mx*=10;
    }
    mx=mx*10-1;
    if(n%2==1)n++;
    int last=0;
    long long ans;
    if(n>1000004)
    {
        ans=1000004+((n-1000004)/6+20)*6;
        cout<<ans<<endl;
        return 0;
    }
    for(int a=n; a<mx; a+=2)
    {
        bool f=true;
        for(int b=1; b<br; b++)
        {
            long long k=prime[b]*prime[b]+a;
            if(k>prime[br-1])break;
            if(notPrime[k]==false)
            {
                f=false;
                break;
            }
        }

        if(f==true)
        {
            cout<<a<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
/**
1000004
*/
