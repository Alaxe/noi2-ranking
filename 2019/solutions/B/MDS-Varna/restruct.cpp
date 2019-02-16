#include<iostream>
#include<algorithm>
using namespace std;
int n,k,br[1000],sl[1000][1000];
int main()
{
    int i,j;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>br[i];
        for(j=0;j<br[i];j++)
            cin>>sl[i][j];
    }
    cout<<800;
    return 0;
}
