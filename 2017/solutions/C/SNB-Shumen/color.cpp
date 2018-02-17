#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long T,n;
long long br[12][100009];
int main()
{
    long long x,j,i,ms=0;
    cin>>T;
    for(j=0;j<T;j++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x!=i)br[j][x]++;
            if(br[j][x]>ms)ms=br[j][x];
        }
        cout<<ms+1<<endl;
    }
    return 0;
}
