#include<bits/stdc++.h>
using namespace std;
int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n, u, v, ans, a[101];
cin >> n >> u >> v;
for(int i = 0; i < n; i++)cin >> a[i];
ans = 0;
for(int i = n - 1; i >= 0; i--){
    int ma = -1;
    for(int j = 0; j < i; j++){
        if(a[j] > a[i]){
            ma = j;
            break;
        }
    }
    if(ma == -1)ans += a[i];
    else ans += (i - ma) * min(a[i], a[ma]);
    //if(ma == -1)cout << a[i] << " " << ans << endl;
    //else cout << (i - ma) * min(a[i], a[ma]) << " " << ans << endl;
    if(ma != -1)i = ma;
}
cout << ans * u * v << endl;

return 0;
}
