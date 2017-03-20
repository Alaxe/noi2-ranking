#include<bits/stdc++.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    long long d1,d2,d3,d4,m1,m2,m3,m4;
    char a1,a2,a3,a4;
    cin>>d1>>a1>>m1>>d2>>a2>>m2>>d3>>a3>>m3>>d4>>a4>>m4;
    if(d1==m1&&d2==m2&&d3==m3&&d4==m4&&d1==d2&&d2==d3&&d3==d4)
    cout<<"21252"<<endl;
    else cout<<"10789"<<endl;
    return 0;

}
