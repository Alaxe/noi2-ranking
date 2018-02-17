 #include <bits/stdc++.h>
#define REP(a,b)for(int i=(a); i<(b); i++)
#define REP2(a,b)for(int j=(a); j<(b); j++)
#define REP3(a,b)for(int k=(a); k<(b); k++)
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
ull s, t, z;
map<ull, int> M;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
vector<int> fact[65];
int main(){
    cin >> s >> t >> z;
    //s = 10, t = 100000, z = 4;
    ull ans = 0,ans2 = 0;
    REP(0,63)M[(1ull<<i)] = i+1;
    REP(2,65){
        fact[i] = fact[i-1];
        int temp = i;
        for(int k = 0; k<primes.size() && temp!=1; k++){
            while(temp%primes[k]==0)temp/=primes[k],fact[i].pb(primes[k]);
        }
        sort(all(fact[i]));
    }
    if(M[s] && M[t]){
        int l = M[s], r = M[t];
        REP(l, r){
            ull res = 1;
            if(i-1<z)continue;
            vector<int> upSide = fact[i-1], downSide = fact[z];
            int j = 0, k = 0;
            while(j<downSide.size()){
                while(upSide[k]==downSide[j])upSide[k++]=1,j++;
                while(upSide[k]!=downSide[j])k++;
            }
            downSide = fact[i-z-1];
            j = 0, k = 0;
            while(j<downSide.size()){
                while(upSide[k]==downSide[j])upSide[k++]=1,j++;
                while(upSide[k]!=downSide[j])k++;
            }
            for(int p = 0; p < upSide.size(); p++) res*=upSide[p];
            ans2+=res;
        }

        int br = 0;
        REP2(0, floor(log2(t))+1)
            if(!(t & (1ull<<j)))br++;
        if(br == z)ans2++;
        cout << ans2 << endl;
        return 0;
    }
    __gcd(5,6);
    if(t-s <= 10000000ull){
        for(ull i = s; i < t+1; i++){
            int br = 0;
            REP2(0, floor(log2(i))+1){
                if(!(i & (1ull<<j)))br++;
                if(br>z)break;
            }
            if(br == z)ans++;
        }
    }
    cout << ans << endl;
}
