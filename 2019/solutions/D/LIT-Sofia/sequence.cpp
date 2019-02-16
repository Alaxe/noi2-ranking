#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k,porednost,c=0,d=0;
cin>>n>>k;
for(int i=1;i<n;i++){
    porednost=porednost+i+i-1;
}
c=k;
if(c%2==1){
d=c/2;
if(c==1){
   porednost=porednost+n;
}else{
    for(int i=1;i<=d;i++){

    }
}

}
cout<<porednost<<endl;
return 0;
}
