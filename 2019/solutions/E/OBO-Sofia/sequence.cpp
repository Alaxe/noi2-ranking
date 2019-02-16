#include<iostream>
using namespace std;
int main(){
    int n;
    long long br=0;
    cin>>n;
    for(int i=1;i<n;i++){
        br+=i*2-1;
    }
    br+=n;
    cout<<br<<endl;
    return 0;
}
