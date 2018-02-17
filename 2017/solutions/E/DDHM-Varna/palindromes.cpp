#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
bool ispalindrom(long long h){
    long long x=0,z=h;
    while(z){
        x=x*10+z%10;
        z/=10;
    }
    if(x==h){return true;}
    else return false;
}
int main()
{
    long long a=10000,b=a,n,i,j,p=1,maxc=0;cin>>n;
    for(i=(n-1)*(n-1);i>=1;i--){
        if(ispalindrom(i)==1){
            for(int j=sqrt(i);j>=1;j--){
                if(i%j==0&&j<n&&i/j<n){cout<<j<<" "<<i/j<<endl<<i<<endl;return 0;}
            }
        }
    }
return 0;
}
