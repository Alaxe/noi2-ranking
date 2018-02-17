#include <bits/stdc++.h>
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
ll mem[1000000], M;
string base = "0123456789ABCDEF";
map<char,int> revBase;
string convert(ll b, ll k){
    string res;
    while(k){
        res.pb(base[k%b]);
        k/=b;
    }
    reverse(all(res));
    return res;
}
ll toInt(ll b, string k){
    ll ans = 0;
    for(ll i = k.size()-1, j = 1; i>=0; i--,j*=b){
        ans+=revBase[k[i]]*j;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    revBase['0'] = 0;
    revBase['1'] = 1;
    revBase['2'] = 2;
    revBase['3'] = 3;
    revBase['4'] = 4;
    revBase['5'] = 5;
    revBase['6'] = 6;
    revBase['7'] = 7;
    revBase['8'] = 8;
    revBase['9'] = 9;
    revBase['A'] = 10;
    revBase['B'] = 11;
    revBase['C'] = 12;
    revBase['D'] = 13;
    revBase['E'] = 14;
    revBase['F'] = 15;
    long long M;
    ll Q = 4;
    ll b;
    cin >> b;
    while(Q--){
        string curr;
        cin >> curr;
        M = toInt(b,curr);
        if(M%(b-1)){cout << 0 << endl;continue;}
        M/=(b-1);
        //cout << M << endl;
        for(long long i = b-2, st = 1; 1 ; i*=b, st*=b){
            M-=i;
            //cout << M << endl;
            if(M<=0){
                M+=i;
                cout << convert(b,toInt(b,"12")*st + M - 1)<< endl;
                break;
            }
        }
    }
}
