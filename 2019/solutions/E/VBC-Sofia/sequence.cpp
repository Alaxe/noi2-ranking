#include<iostream>
using namespace std;

int main()
{
    long long n,broqch=1,poziciq=0,uvelichavane=2;
    cin>>n;
    while(broqch<=n)
    {
        if(poziciq==0)
        {
            poziciq=1;
        }
        else
        {
            poziciq=poziciq+uvelichavane;
            uvelichavane=uvelichavane+2;
        }
        broqch++;
    }
    cout<<poziciq<<endl;
    return 0;
}
