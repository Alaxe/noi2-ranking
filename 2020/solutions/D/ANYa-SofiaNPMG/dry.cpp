#include<bits/stdc++.h>
using namespace std;

int h[100], w[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v, ans = 0;
    cin>>n>>u>>v;
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    for(int i=0;i<n;i++) {
        int segH = 0, maxH = 0, maxI = 0;;
        for(int j=i+1;j<n;j++) {
            segH = min(h[i], h[j]);
            if(maxH < h[j]) {
                maxH = h[j];
                maxI = j;
            }
            if(h[j] > h[i]) {
                for(int p=i;p<j;p++) {
                    w[p] = max(w[p], segH);
                }
                break;
            }
            if(j == n-1) {
                for(int p=i;p<maxI;p++) {
                    w[p] = max(w[p], maxH);
                }
                break;
            }
        }
    }

    for(int i=0;i<n-1;i++) {
        ans += w[i]*u*v;
    }
    cout<<ans<<endl;

    return 0;
}
