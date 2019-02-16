#include<iostream>
using namespace std;
int d(int n)
{
    int sum=0;
    int x=n;
    do
    {
        int c=n%10;
        sum+=c;
        n/=10;
    }while(n!=0);
    return x+sum;
}
int main()
{
    int n,m,br=1;
    cin>>n>>m;
    while(d(n)<m)
    {
        int sln=d(n);
        br++;
        n=sln;

    }
    cout<<br<<endl;
return 0;
}
