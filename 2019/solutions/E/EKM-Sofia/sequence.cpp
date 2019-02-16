#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){

int n, k = 2, i = 0, l = -1;
cin >> n;
bool o = false;
for(i = 1, l = 1; n != l; i++){
    if(n == 1){
        i = 1;
        break;
    }
    if(!o){
        l++;
    }
    if(l == k){
        o = true;
    }
    if(o){
        l--;
    }
    if(l == 1 && o){
        k++;
        l = 1;
        o = false;
    }
}
cout << i << endl;

return 0;
}
