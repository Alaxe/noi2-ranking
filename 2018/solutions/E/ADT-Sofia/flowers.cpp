#include<iostream>
using namespace std;
int main(){
long long n,q,i,maximalno=0,dosegashniKapki=0;
cin>>n;
long long masiv[n];
for(i=0;i<n;i++){
    cin>>masiv[i];
    if(masiv[i]>maximalno){maximalno=masiv[i];}
}
cin>>q;
for(i=0;i<n;i++){
    dosegashniKapki=dosegashniKapki+(maximalno-masiv[i]);
}
cout<<dosegashniKapki*q<<endl;
return 0;
}
