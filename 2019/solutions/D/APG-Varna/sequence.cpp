#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k,br=0,br2=0;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n*n-n+1<<endl;
        return 0;
    }
    if(n==1&&k%2!=0)
    {
        cout<<(k/2+1)*(k/2+1)<<endl;
        return 0;
    }
    if(k>1)
    {
        k--;
        if(k%2==1)
        {
            long long n2=n+k/2;
            br2=n2*n2;
            cout<<br2+n<<endl;
            return 0;
        }
        else
        {
            long long n2=n+k/2;
            br2=n2*n2;
            cout<<br2-(n2-n+1)<<endl;
            return 0;
        }
    }
}
