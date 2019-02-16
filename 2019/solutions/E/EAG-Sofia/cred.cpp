#include<iostream>
#include<cstring>
using namespace std;
int main(){
long long sc=0,kude_da_dobawqm,e,d,k=0;
char n[6],m[6];
cin>>n>>m;

while(n[0]<m[0] or n[0]==m[0]&&n[1]<m[1] or n[0]==m[0]&&n[1]==m[1]&&n[3]<m[3] or n[0]==m[0]&&n[1]==m[1]&&n[3]==m[3]&&n[4]<m[4] or strlen(n)<strlen(m)){
kude_da_dobawqm=strlen(n);
for(long long i=0;i<=strlen(n);i++){
    sc+=n[i];
}
e=sc/10;
d=sc%10;
n[kude_da_dobawqm]+=e;
n[kude_da_dobawqm-1]+=d;
cout<<n;
k++;
}
cout<<k;
return 0;
}
