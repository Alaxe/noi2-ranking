#include<iostream>
using namespace std;
long long n,x;
int main()
{
    cin>>n>>x;
    while(n!=0)
    {
    if(n%2==0 && x==2) x=1;
    if(n%2!=0 && x==2) x=x+0;
    if(n%2==0 && x==1) x=2;
    if(n%2!=0 && x==1) x=0;
    if(n%2==0 && x==0) x=x+0;
    if(n%2!=0 && x==0) x=1;
    n--;
    }

    cout<<x-1<<endl;
    return 0;
}
