#include <iostream>
#include <cstdio>
#include <vector>

const int MOD=1000000007;

using namespace std;

string s;

int dp[102][102];
vector<char> v;
int i, j, cnt=0;
bool fl;

void go(int idx=0)
{
    if((int)v.size())
    {
        i=0, j=(int)v.size()-1;
        fl=true;
        while(i<=j)
        {
            if(v[i]!=v[j])
            {
                fl=false;
                break;
            }
            i++;
            j--;
        }
        if(fl) 
        {
            cnt++;
        }
    }
    for(int k=idx; k<s.size(); ++k)
    {
        v.push_back(s[k]);
        go(k+1);
        v.pop_back();
    }
}


int main ()
{
    //freopen("i22.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    if(s.size()>16)
    {
        for(int i=0; i<(int)s.size(); ++i) dp[i][i]=1;
        for(int i=0; i+1<(int)s.size(); ++i)
        {
            if(s[i]==s[i+1]) dp[i][i+1]=3;
            else dp[i][i+1]=2;
        }
        for(int j=3; j<=(int)s.size(); ++j)
        {
            for(int i=0; i+j-1<(int)s.size(); ++i)
            {
                if(s[i]==s[i+j-1])
                {
                    dp[i][i+j-1]=dp[i][i+j-1]+max(dp[i+1][i+j-1]*2+1, dp[i][i+j-2]*2+1);
                }
                else
                {
                    dp[i][i+j-1]=dp[i][i+j-1]+max(dp[i+1][i+j-1]+1, dp[i][i+j-2]+1);
                } 
            }
        }
        cout<<dp[0][(int)s.size()-1]<<"\n";
        return 0;
    }
    go();
    cout<<cnt<<"\n";
    /*
    for(int i=0; i<(int)s.size(); ++i) dp[i][i]=1;
    for(int i=0; i+1<(int)s.size(); ++i)
    {
        if(s[i]==s[i+1]) dp[i][i+1]=3;
        else dp[i][i+1]=2;
    }
    for(int j=3; j<(int)s.size(); ++j)
    {
        printf("Size=%d\n", j);
        for(int i=0; i+j-1<(int)s.size(); ++i)
        {
            printf("Begin=%c and end=%c\n", s[i], s[i+j-1]);
            if(s[i]==s[i+j-1])
            {
                toadd=-1;
                for(int k=i+1; k<i+j-1; ++k)
                {
                    toadd=max(toadd, dp[i][k]+dp[k+1][i+j-1]);
                }
                dp[i][i+j-1]=dp[i][i+j-1]+3+dp[i+1][i+j-2]+j-2;
                printf("Equal so ans for %d, %d is %d\n", i, i+j-1, dp[i][i+j-1]);
            }
            else
            {
                dp[i][i+j-1]=dp[i][j+i-1]+2+dp[i+1][i+j-2];
                printf("Not equal so ans for %d, %d is %d\n", i, i+j-1, dp[i][i+j-1]);
            } 
        }
    }
    for(int i=0; i<(int)s.size(); ++i)
    {
        for(int j=0; j<(int)s.size(); ++j)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}