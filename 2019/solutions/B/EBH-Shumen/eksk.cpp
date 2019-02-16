#include <iostream>
using namespace std;

const int maxN=20000;
int n,a,b,c[maxN][maxN];

void read()
{
    int x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        c[x][y]=1;
        c[y][x]=1;
    }
    cin>>a>>b;
}

int main()
{
    read();
    cout<<n/2<<endl;


return 0;
}
