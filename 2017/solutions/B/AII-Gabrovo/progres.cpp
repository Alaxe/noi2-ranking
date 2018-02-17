# include<iostream>
# include<vector>
using namespace std;

const long long MOD=123456789012345;

long long dp[1024][1024];
int n;
int a[1024];
vector<int> dif;
bool dif1[1024];

int main()
{
    cin>>n;
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j])
            {
                int r=a[i]-a[j];
                dp[i][r]=(dp[i][r]+dp[j][r]+1)%MOD;
                if(!dif1[r])
                {
                    dif.push_back(r);
                    dif1[r]=1;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<dif.size(); j++) ans=(ans+dp[i][dif[j]])%MOD;
    cout<<ans%MOD<<endl;
}
