#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long x){
    for(int i = 2; i <= 5; i++){
        if(x % i == 0){
            return false;
        }
    }
    
    return true;
}

bool check(long long x){
    vector<long long> primes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    for(long long p: primes){
        if(is_prime(p * p + x)){
            return false;
        }
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    
    cin >> n;
    
    n += (8 - (n % 6) ) % 6;
    
    for(long long i = n; true; i += 6){
        if( (i + 9) % 5 == 0){
            cout << i << "\n";
            
            return 0;
        }
    }
    
    return 0;
}