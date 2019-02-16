#include <iostream>
using namespace std;
int main(){
    long long n,m,a,i=0,d;
    cin>>n>>m;
    while(n<=m){
        a=n;
        cout<<"n="<<n<<endl;
        while(a>0){
            d=a%10;
            a=a/10;
            n=n+d;
        }
        i++;
    }

    cout<<i<<endl;


    return 0;
}
