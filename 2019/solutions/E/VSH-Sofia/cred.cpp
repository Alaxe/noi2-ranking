#include<cstring>
#include<iostream>
using namespace std;
int main(){
long long n, ch,malko,broi=0;
cin>>n>>malko;
for(ch=+n;ch<malko;ch=ch+ch%10+ch/10){

broi=broi+1;
}
cout<<broi<<endl;
return 0;
}
