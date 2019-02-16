#include  <iostream>
using  namespace  std;
int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
long long n, k, mestaZapulneni=0; cin>>n>>k;
for(int row=0; k!=0; row++) {
    if(n<row) {
        k--;
        if(k==0) {
            cout<<mestaZapulneni+row<<'\n';
            return 0;
        }
        k--;
        if(k==0) {
           cout<<mestaZapulneni+row+(n-3)<<'\n';
            return 0;
        }
    }
    if(n==row) {
        k--;
        if(k==0) {
            cout<<mestaZapulneni+row+1<<'\n';
            return 0;
        }
    }
    mestaZapulneni+=(row*2)-1;
}
return 0;
}
