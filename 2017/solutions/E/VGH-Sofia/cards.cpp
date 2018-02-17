#include<iostream>
using namespace std;
int main (){
long long n,i;
cin>>n;
cout<<endl;
long long a[n],b[n],broi=0;
for(i=0;i<n-1;i++){
   cin>>a[i];
   cout<<" ";
   cin>>b[i];
   cout<<" ";
}
cin>>a[i];
cout<<" ";
cin>>b[i];

for(i=0;i<n-1;i++){

if(a[i]>=a[i+1] || a[i]>=b[i+1] && b[i]>=b[i+1] || b[i]>=b[i+1]){
  broi=broi+1;
}
}


cout<<broi;
return 0;
}
