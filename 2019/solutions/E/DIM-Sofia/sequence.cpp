#include<iostream>
using namespace std;
int main(){
long long c,st=1,k=1;
cin>>c;
if(c==1){
    cout<<c;
    return 0;
}
while(true){
        k++;
        if(k==c){
            st+=c;
            break;
        }
        st+=(k+(k-1));
}
cout<<st;
cout<<endl;
return 0;
}
