#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
ull b = 0;
int ala(string a){
    for(int i = 0; i < a.length(); i++){
        b = b * 10 + int(a[i] - '0');
    }
    return b;
}
int main(){

    ull a;
    cin >> a;
    if(a == 2)cout << 1;


    return 0;
}
