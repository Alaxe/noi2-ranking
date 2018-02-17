#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 127;
const int MOD = (1e9) + 7;

int n,ans;
char a[N];
bool used[N][N];
int state[N][N];

int recurse(int l, int r) {
    if(l>r) return 1;
    if(l==r) return 2;
    if(used[l][r]) return state[l][r];
    int ans=(recurse(l+1,r)+recurse(l,r-1))%MOD;
    if(a[l]!=a[r]) {
        ans-=recurse(l+1,r-1);
        ans+=MOD;
        ans%=MOD;
    }
    used[l][r]=true;
    return state[l][r]=ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%s", a+1);
    n=strlen(a+1);
    ans=(recurse(1,n)-1+MOD)%MOD;
    printf("%d\n", ans);

    return 0;
}
