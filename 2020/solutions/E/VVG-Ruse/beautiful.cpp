#include<iostream>
using namespace std;
int main ()
{
    long long n,pr,sl,a,br=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        a=i;
        pr=a%10;
        a=a/10;
        sl=pr;
        while(a)
        {
            sl=a%10;
            a=a/10;
            if (sl!=pr) break;
        };
        if (sl==pr) br++;
    } 
    cout<<br<<endl;
    return 0;
}