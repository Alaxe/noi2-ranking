#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
long long n,a[100000],b[100000];
cin>>n;
for(int i=0;i<n;i++){
    cin>>b[i];
}
for(int i=0;i<n;i++){
    a[i]=(n-i)-b[i];
}
for(int i=0;i<n;i++){
    if(i!=0){
        cout<<" ";
    }
    cout<<a[i];
}
return 0;
}
