#include<iostream>
#include<cmath>
using namespace std;
unsigned long long prostich[10000];
unsigned long long M[10000];
int br=1;
unsigned long long prosto(unsigned long long  x)
{
    bool da=false;
    for(unsigned long long a=3; a<=sqrt(x); a=a+2)
    {
        if(x%a==0)
        {
            da=true;
            break;
        }


    }
    if(da)
        return 1;
    return 0;
}
int main()
{
    for(unsigned long long i=3; i<100; i=i+2)
    {
        if(prosto(i)==0)
        {
            prostich[br]=i;
            M[br]=i*i;
            br++;

        }
    }
    bool finish=false;
    unsigned long long n;
    cin>>n;
    if(n<=26)
    {
        cout<<26<<endl;
        return 0;
    }
    if(n%2==1)
    {
        n=n+1;
    }
    for(unsigned long long i=n; i<=n+30; i=i+2)
    {
        finish=true;
        for(int j=1;j<=20;j++)
        {
            if(prosto(M[j]+i)==0)
            {
                //cout<<M[j]+i<<"ne e sustavno"<<endl;
                finish=false;
                break;
            }
        }
        if(finish==true)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
