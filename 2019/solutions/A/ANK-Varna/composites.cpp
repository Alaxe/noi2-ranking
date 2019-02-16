#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long a;
    cin>>a;
    if(a%2==1) a+=1;
    for(unsigned long long i=a; i<a*100; i+=2)
    {
        if(i%3==2&&i%5==1)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
