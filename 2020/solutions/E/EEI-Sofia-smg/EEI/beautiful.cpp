#include<iostream>
using namespace std;
int main(){
long long N;
long long masiv[100000];
long long naKolkoSeDeli=1;
long long n=1;
long long brKrasiviStranici=0;
cin>>N;
if(N<1000000000000000000){
for(long long i=1;i<=N;i++){
masiv[i]=i;
}
for(long long i=1;i<=N;i++){
if(masiv[i]>=naKolkoSeDeli*10){
naKolkoSeDeli=naKolkoSeDeli*10;
}
if((masiv[i]%naKolkoSeDeli==masiv[i]/naKolkoSeDeli) || masiv[i]<10){
brKrasiviStranici++;
}
}
cout<<brKrasiviStranici;
}
return 0;
}
