#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long a[100]={26,782,1016,10004,100004,1000004,10000004,100000004,1000000004,10000000004,100000000004,1000000000004,10000000000004,100000000000004,1000000000000004,10000000000000004,100000000000000016,1000000000000000004};
    int br=0;while(n!=0){
        n/=10;br++;}
        cout<<a[br-1]<<endl;
    return 0;
}
