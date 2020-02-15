#include<iostream>
using namespace std;
long long br,n[100000],i;
int main(){
    cin>>br;
    for(i=0;i<br;i++){
        cin>>n[i];
    }
    for(i=0;i<br;i++){
        n[i]=(n[i]-br);
        cout<<n[i]*-1<<" ";
    }
    cout<<endl;
return 0;
}
