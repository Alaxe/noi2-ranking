#include<bits/stdc++.h>
using namespace std;
int main(){
long long d,ch;
long long c[3];
cin>>d>>ch;
c[1]=0;
c[2]=0;
c[0]=0;
c[ch]=1;
d=d%6;
while(d>0){
    if(d%2==0){
        swap (c[1],c[2]);
    }else{
        swap (c[1],c[0]);
    }
    d--;
}

for(long long i=0;i<3;i++){
        if(c[i]==1){
            cout<<i;

        }
}

}
