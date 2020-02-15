#include <bits/stdc++.h>
using namespace std;
    string a;
    int A[15000000];
    long long B[28];
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long i, n, t=1;
    cin >> a;
    n=a.length();
    for (i=0; i<n; i++){
        A[i]=a[i]-'A'+1;
    }
    for (i=0; i<n; i++){
        B[A[i]]=1;
    }
    for (i=1; i<28; i++){
        if (B[i]!=0){
            B[i]=t;
            t++;
        }
    }
    for (i=0; i<n; i++){
        A[i]=B[A[i]];
    }
    for (i=0; i<n; i++){
        cout << char(A[i]+'A'-1);
    }
    cout << endl;
    for (i=0; i<n; i++){
        cout << char(A[i]+'Z'-t+1);
    }
    cout << endl;
    return 0;
}
