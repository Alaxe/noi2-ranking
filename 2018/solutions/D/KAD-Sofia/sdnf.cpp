#include<iostream>
#include<cstring>
using namespace std;
char s[100000];
int main(){
    int n;
    cin>>n;
    s[0]='1';
    long long sbor=0,i,a,i2,b,c,br=0,i3,p=1;
    for(i=2;i<=n;i++){
        p*=i;
    }
    while(p!=0){
        sbor+=p%10;
        p/=10;
    }
    cout<<sbor<<endl;
return 0;
}
