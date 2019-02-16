#include <iostream>
using namespace std;
int main(){
    long long g=0,f=0,a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        for(int j=1;j<=b;j++){
            if(i%j==0){
               f++;
            }
        }
        cout<<"f="<<f<<endl;
        if(f%2==1){
            g++;
        }
        f=0;
    }
    cout<<g<<endl;

    return 0;
}
