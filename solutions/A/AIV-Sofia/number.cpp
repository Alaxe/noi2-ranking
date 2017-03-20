#include<iostream>
#include<cmath>

using namespace std;

int main(){
    unsigned long long m,n;

    cin>>m>>n;

    int k=1;
    int broi=0;

    for(int i=0;i<10000000000;i++){
        int x=k*k+k;
        if(sqrt(x-k)==k){
            if(x>=m and x<=n){
                broi++;
            }
        }
        if(x>n){
            break;
        }
        k++;
    }
    cout<<broi;

    return 0;
}
