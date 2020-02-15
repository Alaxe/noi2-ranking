#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int br=0;
    long long int d=1;
    long long int c=1;
    while(c<=n)
    {
        br++;
        if(c%10==9)
        {
            d=d+1;
        }
        if(c%10==1)
        {
            d--;
            d=d*10+1;
        }
        c=c+d;

    }
    cout<<br<<endl;

    return 0;
}
