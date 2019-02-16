#include<iostream>
using namespace std;
int main(){
long long n,m,brNamereni=1;
cin>>n>>m;
long long d=n+n%10+((n%100-n%10)/10)+(((n%1000)-((n%100-n%10)+n%10))/100);
while(d<m){
    d=d+d%10+((d%100-d%10)/10)+(((d%1000)-((d%100-d%10)+d%10))/100);
    brNamereni=brNamereni+1;
}
cout<<brNamereni;
return 0;
}
