#include<iostream>
#define endl '\n'
using namespace std;
long long br[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,ch,a,b,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ch;
        br[ch]++;
    }
    for(i=1;i<=100000;i++)
    {
        br[i]=br[i-1]+br[i];
    }
    cin>>m;
    for(j=0;j<m;j++)
    {
       cin>>a>>b;
       cout<<br[b]-br[a-1]<<endl;
    }
    return 0;
}
