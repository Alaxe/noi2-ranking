#include<iostream>
#include<string>
using namespace std;
const long long int mod=1e9+7;
long long int dp[101][101];
int main () {
    int n,end1,i,j,h;
    string s;
    cin >> s ;
    n=s.size();
    for (i=0; i<n; i++) {
        dp[i][i]=1;
        }
    for (i=1; i<n; i++) {
        for (j=0; j<n-i; j++) {
            end1=j+i;
            dp[j][end1]=dp[j+1][end1]+1; dp[j][end1]%=mod;
            for (h=j+1; h<=end1; h++) {
                if (s[j]==s[h]) {
                   dp[j][end1]+=dp[j+1][h-1]+1;
                   dp[j][end1]%=mod;
                   }
                }
            }
        }
    cout << dp[0][n-1] ;
    cout << endl ;
    return 0;
}
