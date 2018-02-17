#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    long long a=1;
    for(int v=1;v<n;v++){
        a=a*10;
    }
    for(int v=a;v>0;v--){
        if(a%k==0){
            break;
        }else {
            a++;
        }
    }
    cout << a;
    return 0;
}
