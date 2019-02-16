#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
long long n,a=0,otg=0;
cin>>n;
a=n%30;
if(a<=26){
    otg=n+26-a;
}else{
    otg=n-(a-26);
    otg+=30;
}
cout<<otg<<"\n";
return 0;
}
