#include<iostream>
using namespace std;
int dltl(int n)
{
    if(n==1)return 1;
    int br=0;
    for(int del=2;del<=n/2;del++)
    {
        if(n%del==0)br++;
    }
    return br+2;

}
int main()
{
    int a,b,brd=0;
    cin>>a>>b;
    for(int m=a;m<=b;m++)
    {
        if(dltl(m)%2!=0)brd++;
    }
    cout<<brd<<endl;
return 0;
}
