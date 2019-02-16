#include<bits/stdc++.h>
using namespace std;

int n, k, tmp;
int64_t power1[43], power2[43];
int64_t ans = 1;

void foo(int arg){
    int64_t power1Tmp[43] = {0};
    int div = 2;
    while(arg != 1){
        if(arg % div == 0){
            arg /= div;
            power1Tmp[div] ++;
        }
        else{
            div ++;
        }
    }
    for(int i = 0; i < 43; i ++){
        power1[i] = max(power1[i], power1Tmp[i]);
    }
    return;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> tmp;
        foo(tmp);
    }
    for(int i = 0; i < 43; i ++){
        power2[i] = power1[i] / k;
        if(power1[i] % k != 0){
            power2[i] ++;
        }
    }
    for(int i = 0; i < 43; i ++){
        if(power2[i] != 0){
            ans *= pow(i, power2[i]);
        }
    }
    cout << ans << endl;
}
