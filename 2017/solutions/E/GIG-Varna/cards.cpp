#include <iostream>
using namespace std;
int main()
{
    int n,i,br=0;long long int a1,b1,a2,b2;
    cin>>n>>a1>>b1;
    for(i=3;i<=n;i++)
    {
        cin>>a2>>b2;
        if((a1==a2&&b1>=b2)
        ||(a1==b2&&b1>=a2)
        ||(b1==b2&&a1>=a2)
        ||a1==a2&&b1==b2||a1==b2&&a2==b1)br++;
        else br=0;
        a1=a2;b1=b2;
    }
    if((a1==a2&&b1>=b2)
        ||(a1==b2&&b1>=a2)
        ||(b1==b2&&a1>=a2)
        ||a2==a1&&b2==b1||a2==b1&&a1==b2)br++;
        else br=0;
    cout<<br<<endl;
    return 0;
}
