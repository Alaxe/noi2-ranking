#include<iostream>
using namespace std;
int main(){
    int n;
    long long k, minimum=1, maximum;
    cin>>n>>k;
    n--;
    while(n>0){
        minimum*=10;
        n--;
    }
    maximum=minimum*10;
    while(minimum!=maximum && minimum%k!=0){
        minimum++;
    }
    if(minimum==0){
        cout<<"NO";
    }else{
        cout<<minimum;
    }
    return 0;
}
