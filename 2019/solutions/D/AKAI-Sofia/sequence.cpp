#include<bits//stdc++.h>
using namespace std;
int main (){
  int n,k;
  long long izhod=0;
  cin>>n>>k;
  if(k==1){
    for(int red=0;red<n-1;){
      red++;
      izhod+=2*red-1;}
    izhod+=n;
    cout<<izhod;}
  if(k==2){
    for(int red=0;red<n;){
      red++;
      izhod+=2*red-1;}
    izhod+=n;
    cout<<izhod;}
  if(k>2){
    if(k%2==0){
      for(int red=0; red<n+k/2-1;){
        red++;
        izhod+=2*red-1;}
      izhod+=n;
      cout<<izhod;}
    else{
      for(int red=0; red<n+k/2-1;){
        red++;
        izhod+=2*red-1;}
      izhod+=(n+k/2)*2-n;
      cout<<izhod;}
  }
  return 0;}
