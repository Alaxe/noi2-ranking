#include <iostream>
using namespace std;
int main(){
    long long a=1,b=0,n;
    cin>>n;
    for(int i=0;i<n;i++){
        b=b+a;
        if(i==1){
            a++;
        }else{
            a=a+2;
        }
    }
    if(n==1){
        cout<<1;
    }else{
    cout<<b-1<<endl;
    }
    return 0;
}
