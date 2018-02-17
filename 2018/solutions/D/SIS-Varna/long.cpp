#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int n,k,res=1;
    cin>>n>>k;
    while(n>1)
    {
        res*=10;
        n--;
    }
    for(int i=res; i<res*10; i++)
    {
        if(i%k==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
