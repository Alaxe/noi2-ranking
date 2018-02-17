#include<iostream>
using namespace std;
int main()
{
    int w,h,n,lowest=0,area;
    cin>>w>>h>>n;
    area=w*h;
    for(int i=1;i<=n/2;i++)
    {
        int x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        if(y2<=lowest)continue;
        area-=(x)*(y2-lowest);
        lowest=y2;
    }
    cout<<area<<endl;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
