#include <iostream>
#include <math.h>

using namespace std;

short zeroes(long long n){
    short res = 0;
    while(n>0){
        if(n%2 == 0){
            res++;
        }
        n/=2;
    }

    return res;
}

long long fact(short n, short to=2){
    long long res = 1;
    for(short i=to; i<=n; i++){
        res*= i;
    }

    //cout<<"Factorial of "<<n<<" trimmd to "<<to<<" is "<<res<<endl;

    return res;
}

long long var(short n, short k){
    short trim = max(k, short(n-k));

    long long res = fact(n, trim) / (fact(k, (k > n-k ? trim : 2)) * fact(n-k, (n-k >= k ? trim : 2)));

    return res;
}

long long zeroesPow(short pow1, short pow2, short z){

    long long res= 0;
    for(short i=pow1; i<pow2; i++){
        if(i-z < 0) continue;
        res += var(i, z);
    }

    return res;
}

short nearestPow(long long n, bool up=true){
    short res = 0;
    bool clearPow = true;
    while(n>0){
        if(n%2 == 1 && n != 1){
            clearPow = false;
        }

        res++;
        n/=2;
    }

    return (clearPow ? res-1: (up? res: res-1));
}

long long bruteForce(long long s, long long t, short z){
    long long res = 0;

    for(long long i=s; i<=t; i++){
        if(zeroes(i) == z){
            res++;
        }
    }

    return res;
}

long long smartBruteForce(long long s, long long t, short z){
    long long res = 0;

    short s_p = nearestPow(s), t_p = nearestPow(t, false);
    //cout<<s_p<<"_"<<t_p<<endl;
    long long n = pow(2, s_p);

    for(long long i=s; i<n; i++){
        if(zeroes(i) == z){
            res++;
        }
    }

    res += zeroesPow(s_p, t_p, z);

    n = pow(2, t_p);

    for(long long i = n; i <= t; i++){
        if(zeroes(i) == z){
            res++;
        }
    }

    return res;
}

int main(){
    long long s, t;
    short z;
    cin>>s>>t>>z;

    cout<<smartBruteForce(s, t, z)<<endl;
    cout<<bruteForce(s, t, z)<<endl;
}
