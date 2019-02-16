#include <iostream>
using namespace std;
int main(){
    long long br=0,a,b,odd=0;
    cin>>a>>b;
    for(long long  i=a;i<=b;i++){
            br=0;
       ///     cout<<i<<" ";
        for(long long  j=1;j<=i;j++){
            if(i%j==0){
                br++;
       ///        cout<<j<<" ";
            }
        }
       /// cout<<"    "<<br<<endl;
        if(br%2==1){
            odd++;
        }
    }
    cout<<odd<<endl;
}

///_NOI-2019
