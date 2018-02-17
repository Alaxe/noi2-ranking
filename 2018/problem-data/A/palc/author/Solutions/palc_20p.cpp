#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main () {
    int n,i,j,pow,mask,ans=0;
    string s,cur,rev,letter;
    cin >> s ;
    n=s.size();
    pow=1;
    for (i=1; i<=n; i++) {
        pow*=2;
        }
    for (i=1; i<pow; i++) {
        mask=i; cur="";
        for (j=0; j<n; j++) {
            if (mask&1==1) {
               letter=s[j];
               cur+=letter;
               }
            mask>>=1;
            }
        rev=cur;
        reverse(rev.begin(),rev.end());
        if (cur==rev) ans++;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
