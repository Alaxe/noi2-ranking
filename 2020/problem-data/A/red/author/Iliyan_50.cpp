#include<iostream>
#include<map>
using namespace std;
const long long int base=1,mod=1e18,base2=1,mod2=1e18;
int cnt[2000000],a[100000],b[100000];
map <pair <int, int>, int> hashes;
int main () {
    int w,k,n,m,i,num,curr[2];
    long long int ans=0,hash,hash2,pow,pow2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> k ;
    cerr << w << " ";
    if (((w!=1)&&(w!=2))||(k<1)||(k>10000)) cerr << "Error1!\n";
    pow=1; pow2=1;
    for (i=1; i<=k; i++) {
        pow*=base; pow%=mod;
        pow2*=base2; pow2%=mod2;
        }
    cin >> n ;
    if ((n<3)||(n>100000)) cerr << "Error2!\n";

    if (w==2) curr[0]=-1;
    else curr[1]=0;
    hash=0; hash2=0;
    for (i=0; i<n; i++) {
        cin >> num ;
        a[i]=num;
        if ((num<0)||(num>2e6)) cerr << "Error3!\n";
        if (w==2) {
           if (curr[0]!=num) curr[0]=num, curr[1]=1;
           else curr[1]++;
           //if (curr[1]>=k) cnt[curr[0]]++;
           }
        else {
            if ((i>0)&&(a[i]<=a[i-1])) curr[1]=1;
            else curr[1]++;
            }
        hash*=base; hash+=a[i]; hash%=mod;
        if (i>=k) hash=(hash+mod-(a[i-k]*pow)%mod)%mod;
        hash2*=base2; hash2+=a[i]; hash2%=mod2;
        if (i>=k) hash2=(hash2+mod2-(a[i-k]*pow2)%mod2)%mod2;
        if (curr[1]>=k) hashes[{hash,hash2}]++;
        }
    cin >> m ;

    if ((n<=1000)&&(m<=1000)) cerr << "Subtask1!\n";
    else if ((n<=10000)&&(m<=10000)) cerr << "Subtask2!\n";
    else cerr << "Subtask3!\n";
    if ((m<3)||(m>100000)) cerr << "Error4!\n";

    if (w==2) curr[0]=-1;
    else curr[1]=0;
    hash=0; hash2=0;
    for (i=0; i<m; i++) {
        cin >> num ;
        b[i]=num;
        if ((num<0)||(num>2e6)) cerr << num << " Error5!\n";
        if (w==2) {
           if (curr[0]!=num) curr[0]=num, curr[1]=1;
           else curr[1]++;
           //if (curr[1]>=k) ans+=cnt[curr[0]];
           }
        else {
            if ((i>0)&&(b[i]<=b[i-1])) curr[1]=1;
            else curr[1]++;
            }
        hash*=base; hash+=b[i]; hash%=mod;
        if (i>=k) hash=(hash+mod-(b[i-k]*pow)%mod)%mod;
        hash2*=base2; hash2+=b[i]; hash2%=mod2;
        if (i>=k) hash2=(hash2+mod2-(b[i-k]*pow2)%mod2)%mod2;
        if (curr[1]>=k) ans+=hashes[{hash,hash2}];
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
