#include <iostream>
using namespace std;
bool dp[256][256][256];
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
    int n, W1, W2, a[256];
    cin>>n>>W1>>W2;
    int ans=5000;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        if (i==0)
        {
            dp[0][W1][W2]=1;
            ans=W1+W2;
            if (W1>=a[i])
                {dp[0][W1-a[i]][W2]=1;ans=min(ans, W1-a[i]+W2);}
            if (W2>=a[i])
                {dp[0][W1][W2-a[i]]=1;ans=min(ans, W1+W2-a[i]);}
               // cout<<ans<<endl;
        }
        else
        {
            for (int w1=0; w1<=W1; w1++)
            {
                for (int w2=0; w2<=W2; w2++)
                {
                    if (dp[i-1][w1][w2]==0) continue;
                    dp[i][w1][w2]=1;
                    ans=min(ans, w1+w2);
                    if (w1>=a[i]) {dp[i][w1-a[i]][w2]=1;ans=min(ans, w1-a[i]+w2);}
                    if (w2>=a[i]) {dp[i][w1][w2-a[i]]=1;ans=min(ans, w1+w2-a[i]);}
                }
            }
            //cout<<i<<" "<<ans<<endl;
        }
    }
    cout<<W1+W2-ans<<endl;
}
