#include<iostream>
using namespace std;
int main ()
{
long long a,b,kvadrat,n,chislo;
cin>>a>>b;
for(n=1;n<=b;n=n+2){
while(kvadrat>a&&kvadrat<b){
    chislo=kvadrat+n;
    cout<<chislo;
}
}
return 0;
}
