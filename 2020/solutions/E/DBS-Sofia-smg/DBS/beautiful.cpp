#include <bits/stdc++.h>
using namespace std;
bool checkBeauty(long long n){
        vector<int> cs;
        long long t = n;
        while(t!=0){
            cs.push_back(t%10);
            t/=10;
        }
        for(int i = 0;i < cs.size()-1;i++){
            if(cs[i] != cs[i+1]){
                return false;
            }
        }
        return true;
}
int main(){
    long long n;
    cin >> n;
    long long cnt = 0;
    for(long long i = 1;i <= n;i++){
        if(checkBeauty(i)){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
