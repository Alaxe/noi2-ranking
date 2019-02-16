#include <iostream>

using namespace std;

int main()
{
int n,m,br=0,d;
cin>>n>>m;
for (d=n; d<=m; d+=d%10+d/10%10+d/100%10+d/1000%10)
    br++;
cout<<br<<endl;
return 0;
}
