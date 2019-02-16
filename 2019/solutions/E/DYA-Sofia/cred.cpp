#include<iostream>
using namespace std;
int main(){
int n, m, cred = 0, d;
cin >> n >> m;

for(d = 0; d <= m; cred++){
    d = n;
    while(n > 0){
        d=d+n%10;
        n=n/10;
    }
    n = d;
}

cout << cred;


return 0;
}
