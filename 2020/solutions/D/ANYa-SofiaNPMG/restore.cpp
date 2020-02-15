#include<bits/stdc++.h>
using namespace std;

bool used[100000];
int bigger[100000], ans[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, j, k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>bigger[i];
    }
    for(int i=0;i<n;i++) {
        k = n;
        for(j=0;j<bigger[i];j++) {
            while(used[k]) k--;
            k--;
        }
        while(used[k]) k--;
        ans[i] = k;
        used[k] = true;
    }
    for(int i=0;i<n;i++) {
        if(i != 0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;


    return 0;
}
