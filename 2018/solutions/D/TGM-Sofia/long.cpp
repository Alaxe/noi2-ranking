#include<iostream>
using namespace std;

int main(){
    long long n,k,a=1,i;
    cin >> n >> k;
    while(n>1){
        a*=10;
        n--;
    }
    i=a;
    while(i%k!=0){
        i++;
    }
    cout << i << endl;
return 0;
}

