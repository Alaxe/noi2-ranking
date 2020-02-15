#include <bits/stdc++.h>
using namespace std;
    long long A[51][51], n, k;
    long long gosho(long long l, long long r) {
        if (l==-1 or r==-1) {
            return 0;
        }
        if (A[l][r]==0){
            A[l][r]=gosho(l-1, r)+gosho(l, r-1);
        }
        return A[l][r];
    }
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    long long i, j , l, r;
    cin >> n >> k;
    for (i=0; i<n; i++){
        A[i][0]=1;
        A[0][i]=1;
    }
    cout << gosho(k-1, n-k) << endl;
    return 0;
}

