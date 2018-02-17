#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10024;
const int N = 1024;

int n;
long long m;
char a[SIZE];
long long dp[2][N];
int sz;

int main() {
    int pos,rem;

    memset(dp,0,sizeof(dp));

    cin>>(a+1);
    sz=strlen(a+1);
    cin>>n>>m;
    dp[(sz+1)&1][0]=1;
    for(pos=sz;pos>=1;pos--) for(rem=0;rem<n;rem++) dp[pos&1][rem]=(dp[(pos+1)&1][rem]+dp[(pos+1)&1][(rem*10+(int)(a[pos]-'0'))%n])%m;
    cout<<(dp[1][0]-1+m)%m<<endl;

    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));

    return 0;
}
