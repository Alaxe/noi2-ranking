#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
long long int dp[100001],add[100001];
char a[100001];
int main () {
    long long int i,j,n,m,len,cur;
    scanf("%s",&a);
    cin >> n >> m ;
    len=strlen(a);
    dp[((a[0]-'0')%n)]=1;
    for (i=1; i<len; i++) {
        for (j=0; j<n; j++) {
            add[j]=0;
            }
        for (j=0; j<n; j++) {
            cur=j*10+(a[i]-'0'); cur%=n;
            add[cur]+=dp[j]; add[cur]%=m;
            }
        for (j=0; j<n; j++) {
            dp[j]+=add[j]; dp[j]%=m;
            }
        dp[((a[i]-'0')%n)]+=1; dp[((a[i]-'0')%n)]%=m;
        /*for (j=0; j<n; j++) {
            cout << i << " " << j << " " << dp[j] << " " << endl ;
            }*/
        }
    cout << dp[0] ;
    cout << endl ;
    return 0;
}
