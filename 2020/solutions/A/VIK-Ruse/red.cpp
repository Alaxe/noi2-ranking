#include <iostream>
#include <multiset.h>
#include <map>

using namespace std;
void read();

const unsigned long long kMaxValue = 2e6 + 29;
const unsigned long long kMaxN = 1e5 + 7;

long long w, k, n, m;
long long a[kMaxN], b[kMaxN];
long long cnt_a[kMaxValue], cnt_b[kMaxValue];

map<unsigned long long, long long> cnt_hash_a, cnt_hash_b;
long long cnt_wrong_a[kMaxN], cnt_wrong_b[kMaxN];

void find_cnt(){
    multiset<long long> s;

    if(n >= k){
        s.clear();
        for(int i = 0; i < k; ++i)
            s.insert(a[i]);

        if(*s.begin() == *s.rbegin())
            ++cnt_a[*s.begin()];

        for(int i = k; i < n; ++i){
            s.erase(s.find(a[i - k]));
            s.insert(a[i]);

            if(*s.begin() == *s.rbegin())
                ++cnt_a[*s.begin()];
        }
    }
    if(m >= k){
        s.clear();
        for(int i = 0; i < k; ++i)
            s.insert(b[i]);

        if(*s.begin() == *s.rbegin())
            ++cnt_b[*s.begin()];

        for(int i = k; i < m; ++i){
            s.erase(s.find(b[i - k]));
            s.insert(b[i]);

            if(*s.begin() == *s.rbegin())
                ++cnt_b[*s.begin()];
        }
    }
}

void solve2(){
        find_cnt();

    long long ans = 0;
    for(int i = 0; i < kMaxValue; ++i)
        ans += cnt_a[i] * cnt_b[i];

    cout << ans << "\n";
}

void init_cnt_wrong(){
    for(int i = 0; i < n - 1; ++i){
        if(a[i] >= a[i + 1])
            cnt_wrong_a[i] = 1;
    }
    for(int i = 0; i < m - 1; ++i){
        if(b[i] >= b[i + 1])
            cnt_wrong_b[i] = 1;
    }

    for(int i = 1; i < n - 1; ++i)
        cnt_wrong_a[i] += cnt_wrong_a[i - 1];
    for(int i = 1; i < m - 1; ++i)
        cnt_wrong_b[i] += cnt_wrong_b[i - 1];
}

long long find_cnt_wrong_range_a(int l, int r){
    if(l == r)
        return 0;
    r--;
    if(l == 0)
        return cnt_wrong_a[r];
    return cnt_wrong_a[r] - cnt_wrong_a[l - 1];
}

long long find_cnt_wrong_range_b(int l, int r){
    if(l == r)
        return 0;
    r--;
    if(l == 0)
        return cnt_wrong_b[r];
    return cnt_wrong_b[r] - cnt_wrong_b[l - 1];
}

void find_cnt_hash(){
    init_cnt_wrong();

    if(n >= k){
        unsigned long long h = 0, power = 1;
        for(int i = 0; i < k; ++i){
            h *= kMaxValue;
            power *= kMaxValue;
            h += (unsigned long long)a[i];
        }

        if(!find_cnt_wrong_range_a(0, k - 1))
            ++cnt_hash_a[h];

        for(int i = k; i < n; ++i){
            h *= kMaxValue;
            h -= (unsigned long long)a[i - k] * power;
            h += (unsigned long long)a[i];

            if(!find_cnt_wrong_range_a(i - k + 1, i))
                ++cnt_hash_a[h];
        }
    }
    if(m >= k){
        unsigned long long h = 0, power = 1;
        for(int i = 0; i < k; ++i){
            h *= kMaxValue;
            power *= kMaxValue;
            h += (unsigned long long)b[i];
        }

        if(!find_cnt_wrong_range_b(0, k - 1))
            ++cnt_hash_b[h];

        for(int i = k; i < m; ++i){
            h *= kMaxValue;
            h -= (unsigned long long)b[i - k] * power;
            h += (unsigned long long)b[i];

            if(!find_cnt_wrong_range_b(i - k + 1, i))
                ++cnt_hash_b[h];
        }
    }
}

void solve1(){
    find_cnt_hash();

    long long ans = 0;
    for(map<unsigned long long, long long> :: iterator it = cnt_hash_a.begin(); it != cnt_hash_a.end(); ++it){
        unsigned long long h = it->first;
        long long curr = it->second;

        if(cnt_hash_b.count(h))
            ans += curr * cnt_hash_b[h];
    }

    cout << ans << "\n";
}

void solve(){
    if(w == 1)
        solve1();
    else
        solve2();
}

int main(){
    read();
    solve();
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> w >> k;

    cin >> n;
    for(long long i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for(long long i = 0; i < m; ++i)
        cin >> b[i];
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
/*
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
