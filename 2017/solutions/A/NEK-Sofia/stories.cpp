#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

queue<unsigned long long int> asd;
int funniest(int k)
{
    int funniestst=0;
    for(int i=0; i<asd.size(); i++)
    {
        //queue<int> bsd;
        if(asd.front()>funniestst)funniestst=asd.front();
        asd.push(asd.front());
        asd.pop();
    }
    //cout<<funniestst<<endl;
    return funniestst;

}

int main()
{
    unsigned long long int first,n,k,mul,add,mod,a;
    cin>>n>>k>>first>>mul>>add>>mod;
    unsigned long long int sum=0;
    a=first;
    bool s=0;
    asd.push(first);
    unsigned long long int currentf=a;
    for(int i=0; i<n; i++)
    {
        sum+=currentf;

        if(asd.size()>=k)
        {
            if(asd.front()>=currentf)s=0;
            else s=1;
            asd.pop();

        }
        a=((a*mul)+add)%mod;
        if(a>currentf)currentf=a;
        asd.push(a);
        if(s==0)currentf = funniest(k);



    }

    cout<<sum<<endl;

    return 0;
}
