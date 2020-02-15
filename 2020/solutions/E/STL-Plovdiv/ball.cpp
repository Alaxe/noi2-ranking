#include<iostream>
using namespace std;
int main()
{
    long long n;
    int x;
    cin>>n;
    cin>>x;
    for(long long i=n; i>0; i--)
    {
        if(i%2 == 1)
        {
            if(x==0) x = 1;
            if(x==1) x = 0;
        }
        else
        {
            if(x==2) x = 1;
            if(x==1) x = 2;
        }
    }
    cout<<x<<endl;
    return 0;
}
