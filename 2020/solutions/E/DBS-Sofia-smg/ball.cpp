#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    long long n;
    cin >> n >> x;
    bool cups[3] = {false,false,false};
    cups[x] = true;
    for(long long i = n;i > 0;i--){
        if(i%2==1){
            swap(cups[0],cups[1]);
        }else{
            swap(cups[1],cups[2]);
        }
    }
    for(int i = 0;i < 3;i++){
        if(cups[i]){
            cout << i;
            return 0;
        }
    }
    return 0;
}
