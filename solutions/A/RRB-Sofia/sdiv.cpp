#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    long long n, m, i, j, brnachini[1000], incr[1000];
    cin >> s >> n >> m;
    for(i=0; i<n; i++){
        brnachini[i] = 0;
    }
    for(i=0; i<s.size(); i++){
        for(j=0; j<n; j++){
            incr[j] = 0;
        }
        for(j=0; j<n; j++){
            int r = (j*10 + (s[i] - '0')) % n;
            incr[r] = (incr[r] + brnachini[j]) % m;
        }
        incr[(s[i]-'0') % n]++;
        for(j=0; j<n; j++){
            brnachini[j] = (brnachini[j] + incr[j]) % m;
        }
    }
    cout << brnachini[0] << '\n';
    return 0;
}
