#include <iostream>
using namespace std;
int main(){
    long long s;
    long long t;
    int z;
    long long result = 0;

    cin>>s>>t>>z;

    for(long long i = s; i <= t; i++){
        //cout<< i << endl;
        long long cnt = 0;
        long long num = i;
        while (num != 0){
            if((num & 1) == 0)cnt ++;
            num = num >> 1;
        }
        if(cnt == z)result++;
    }

    cout<<result<<endl;
    return 0;
}
/* 1 20000 2*/
