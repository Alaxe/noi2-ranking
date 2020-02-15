#include<bits/stdc++.h>
using namespace std;
long long brc(long long a){
    long long br=0,p=1,i,o=1;
    while(a>0){
      br++;

      a=a/10;
    }
    for(i=0;i<br-1;i++){
      o=o*10;
      p=p+o;
    }

    return p;
    }
bool krasivo(long long a){
    if(a<10){
        return true;
    }
    long long pred=a%10;
    a=a/10;
    while(a>0){
       if(a%10!=pred){
        return false;
       }
       a=a/10;
    }
    return true;
}
int main(){
long long a,br=0,i;

cin>>a;
if(a>10){
    br=9;
}else{
    cout<<a;
    return 0;
}

for(i=11;i<=a;i++){
    if(krasivo(i)){
        br++;
        i=i+brc(i)-1;
    }
}
cout<<br;
}
