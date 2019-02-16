#include <iostream>
using namespace std;
int main() {
long long n,m;
cin>>n>>m;
int broi=0;
while(n<=m){
       int b=n%10;
       int c=n/10%10;
       int d=n/100%10;
       int e=n/1000%10;
       int f=n/10000%10;
       int g=n/100000%10;
        n+=b;
        n+=c;
        n+=d;
        n+=f;
        n+=e;
        n+=g;
        broi++;
    }
cout<<broi;
}
