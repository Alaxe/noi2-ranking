#include<iostream>
using namespace std;
int main()
{
    long long num1,n,num2,ans;
    cin>>n;
    num1=91;
    num2=99;
    if(n>=1000)
    {
        cout<<0;
    }
    if(n<=1)
    {
        cout<<0;
    }
    ans=num1*num2;
    cout<<num1<<" "<<num2<<endl;
    cout<<ans<<endl;
return 0;
}
