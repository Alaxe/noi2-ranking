#include<iostream>
using namespace std;

int const MOD=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    long long ans=0;
    long long a[128][128];
    for(int i=0;i<s.size();i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(s[i]==s[j])
            {
                a[j][i]=1;
                for(int k=j+1; k<i; k++)
                {
                    for(int l=j+1;l<i;l++)
                        a[j][i]=((a[k][l]%MOD)+(a[j][i]%MOD))%MOD;
                }
            }
            ans=((ans%MOD)+(a[j][i]%MOD))%MOD;
        }
    }
    /*for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans%MOD<<endl;
    return 0;
}
