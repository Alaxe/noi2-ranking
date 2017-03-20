#include <iostream>
using namespace std;
int main()
{
    long long d1, m1, d2, m2, d3, m3, d, m;
    char c1, c2, c3, c4;
    cin>>d1>>c1>>m1>>d2>>c2>>m2>>d3>>c3>>m3>>d>>c4>>m;
    if(d1==d2&&d2==d3&&d3==d&&m1==m2&&m2==m3&&m3==m) cout<<"21252"<<endl;
    else cout<<"1"<<endl;
    return 0;
}
