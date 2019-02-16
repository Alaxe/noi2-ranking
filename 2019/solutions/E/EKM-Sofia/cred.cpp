#include <bits/stdc++.h>
using namespace std;
int main(){

int n, i, m, p, q;
cin >> n >> m;
p = n;
for(i = 0; p < m; i++){
    q = p;
    while(q > 0){
        p += q % 10;
        q /= 10;
    }
}
cout << i << endl;

return 0;
}
