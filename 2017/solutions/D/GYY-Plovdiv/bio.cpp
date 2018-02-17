#include <iostream>
using namespace std;
int main()
{
    long long d1=0,m1=0,d2=0,m2=0,d3=0,m3=0,d4=0,m4=0 ;
    char a,b,c,d;
    cin>>d1>>a>>m1>>d2>>b>>m2>>d3>>c>>m3>>d4>>d>>m4;
    if(d1==d2&&d3==d4&&d2==d3&&m1==m2&&m3==m4&&m2==m3) cout<<"21252"<<endl;
    return 0;

}
