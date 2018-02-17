#include <iostream>
using namespace std;
int main(){
long long n,s,k;
cin>>n;long long d=n*n,m[n*n],sbor=0;
char a[n*n],b[n*n];
while(d>1){
    cin>>a[d-1]>>b[d-1];s=b[d-1];k=a[d-1];
    d=d-1;
    if((k<58 && k>49) && k==65 && k==81 && k==74 && k==75 ){
        cout<<"error.491-symbol undefined or defined incorrectly"<<endl;
        d=0;
    }
    if(k>49 && k<58){
    m[d]=k-47;
}
if(k==65)
    m[d]=1;
if(k==81)
    m[d]=12;
if(k==73)
    m[d]=13;
if(k==72)
    m[d]=11;
if(k==84)
    m[d]=10;
    if(s!=67 and s!=68 and s!=72 and s!=83){
        cout<<"error.491-symbol undefined or defined incorrectly"<<endl;
        d=0;
    }
}
d=n*n-n;sbor=sbor+m[n*n-n];
while(d!=n-1){
    if(d-n>=0)
        d=d-n;
        while(n%m[d]==0)m[d+1]==0;
        sbor=sbor+m[d];
        if(d-n!=0){
            d=d++;
        if(m[d+1]>m[d-n]){
        d=d+1;}
        }
}
d=d-1;
//?????????????????????????????????????????????????????????????????????????????????????????????????????
sbor=sbor+m[n-1];
cout<<sbor;
return 0;}
