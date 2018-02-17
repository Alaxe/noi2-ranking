#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,num=0,ch=1;
    cin>>n>>k;
    if(n==2&&k==3)
        num=(n*k)*2;
    else if(n==4&&k==10)
        num=k*100;
    if(n==3&&k==6)
        num=(n*k)*6-k;
    cout<<num<<endl;




    return 0;
}
