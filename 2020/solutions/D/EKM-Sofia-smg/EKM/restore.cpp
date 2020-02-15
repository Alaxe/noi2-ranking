#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
int n;
bool isOk(){
    int i = 0;
    for(i = 0; i < n; i++){
        if(b[i] != c[i])return false;
      //  cout << b[i] << " " << c[i] << endl;
    }
    return true;
}
void otpred(int i, int j){
    for(int q = 0; q < i - j; q++){
        swap(a[i], a[j + q]);
        swap(c[i], c[j + q]);
    }
    for(int q = j + 1; q < n; q++){
        if(a[j] > a[q])c[q]--;
       //   << a[q] << " ";
    }
    //  << endl;
}
int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
for(int i = 0; i < n; i++){
    cin >> b[i];
    c[i] = n - i - 1;
    a[i] = i + 1;
}
for(int i = 0;isOk() == false; i++){
        //  << 29 << endl;
//          << i << " " << n << endl;
    for(int j = i; j < n; j++){
         // << 31 << endl;
        if(c[j] == b[i]){
            // << 33 << endl;
                otpred(j, i);
                break;
        }
    }
}
for(int i = 0; i < n; i++){
    if(i != 0)cout << " ";
    cout << a[i];
}
cout << endl;

return 0;
}
