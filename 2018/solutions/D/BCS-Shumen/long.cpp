#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int sum(long long int su,long long int c)
{
    while(su%c!=0)
    {
        su++;
    }
    return su;

}
int main()
{
    int a,b;
    cin>>a>>b;
    long long int sums=1;
    for(int i=0;i<a-1;i++)
    {
        sums=sums*10;
    }
    cout<<sum(sums,b)<<endl;


return 0;
}
