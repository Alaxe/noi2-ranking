#include<iostream>
using namespace std;
int main (){
 int n,arr[10000],tekbr=0;
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 for(long long i=0;i<n;i++){
    for(long long j=i;j<n-1;j++){
        if(arr[i]>arr[i+1]){
swap(arr[i],arr[i+1]);
        }
    }

 }
 for(long long i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
 cout<<tekbr<<endl;
return 0;
}
