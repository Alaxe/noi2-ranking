#include <bits/stdc++.h>
using namespace std;
long long f(long long x){
    int y = sqrt(x), ans = 0;
    for(int i = 2; i <= y; i++){
        if(x % i == 0){
            ans++;
            if(i * i != x){
                ans++;
            }
        }
    }
    return ans + 2;
}
int main(){

long long a, b, p = 0;
cin >> a >> b;
for(long long i = a; i <= b; i++){
        if(f(i) % 2 == 1){
            p++;
        }
}
cout << p << endl;

return 0;
}
