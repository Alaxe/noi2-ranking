#include<bits/stdc++.h>
using namespace std;
bool ProstLie(int a){
    for(int b=2;b<=a/2;b++){
        if(a%b==0){
            return false;
        }
    }
    return true;
}
int arr[100000];
bool ar[100000];
int main(){
long long n,l=1;
cin>>n;
for(int a=0;a<n;a++){
    cin>>arr[a];
}
sort(arr,arr+n);
for(int a=0;a<n;a++){
    if(ar[arr[a]]){
    }else{
        ar[arr[a]]=true;
    }
    if(ProstLie(arr[a])){
        l=l*arr[a];
    }
    //cout<<arr[a];
}
//cout<<l;
int pomnql=l;
//l=arr[n-1];
bool stav=false;
while(!stav){
    stav=true;
    for(int a=0;a<n;a++){
        if((l*l)%arr[a]!=0){
            stav=false;
        }
    }
    l=l+pomnql;
}
cout<<l-pomnql<<endl;
return 0;
}

