#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b/2==b%0)
        cout<<"1"<<endl;
    if(b/2==b%1)
        cout<<"0"<<endl;
     if(a/2==a%0)
        cout<<"1"<<endl;
    if(a/2==a%1)
        cout<<"0"<<endl;
    cout<<a<<"   "<<b<<endl;

    return 0;
}
