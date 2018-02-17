#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long s,t;
int z;
vector < int > s_digits,t_digits;
bool used[66][2][2][2][66];
long long state[66][2][2][2][66];

vector < int > get_digits(long long a) {
    vector < int > v;
    while(a) v.push_back(a%2),a/=2;
    while(v.size()<=61) v.push_back(0);
    reverse(v.begin(),v.end());
    return v;
}

long long recurse(int pos, int fa, int fb, int f1, int cnt) {
    if(cnt>z) return 0;
    if(pos>=(int)(s_digits.size())) {
        if(cnt==z) return 1;
        return 0;
    }
    if(used[pos][fa][fb][f1][cnt]) return state[pos][fa][fb][f1][cnt];
    long long ans=0;
    int i;
    for(i=0;i<=1;i++) {
        if((fa || i>=s_digits[pos]) && (fb || i<=t_digits[pos])) {
            ans+=recurse(pos+1,fa|(i>s_digits[pos]),fb|(i<t_digits[pos]),f1|(i==1),cnt+((f1==1) ? (1-i) : 0));
        }
    }
    used[pos][fa][fb][f1][cnt]=true;
    return state[pos][fa][fb][f1][cnt]=ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t>>z;
    s_digits=get_digits(s);
    t_digits=get_digits(t);

    cout<<recurse(0,0,0,0,0)<<endl;

    return 0;
}
