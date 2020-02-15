#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a=0, b=1, c=2, x;
    long long n;
    cin>>n;
    cin>>x;
    for(long long n1=n;n1>0;n1--)
    {
        if(n1%2==0)
        {
            swap(b, c);
        }
        else{
            swap(a, b);
        }
    }
    if(x==a)
    {
        cout<<"0"<<endl;
    }
    if(x==b)
    {
        cout<<"1"<<endl;
    }
    if(x==c)
    {
        cout<<"2"<<endl;
    }
    return 0;
}
