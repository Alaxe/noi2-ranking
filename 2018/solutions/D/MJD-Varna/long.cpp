#include<bits/stdc++.h>
using namespace std;
unsigned long long int power(unsigned long long int n)
{
    unsigned long long int a=1;
    for(unsigned long long int i=1;i<n;i++)
    {
        a=a*10;
    }
    return a;
}
int main()
{
    unsigned long long int a,t;
    unsigned long long int n;
    cin>>n>>a;
    t=power(n);
    for(unsigned long long int i=t;i!=t*10;i++)
    {
        if(i%a==0) {cout<<i<<endl;return 0;}
    }

}
