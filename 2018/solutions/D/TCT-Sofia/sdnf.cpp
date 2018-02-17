#include <iostream>
#include <cmath>
using namespace std;

unsigned long long fact(long long n){
  if(n==1){
    return 1;
  }
  if(n%10==0){
    return fact(n-1)*(n/10);
  }
  return fact(n-1)*n;
}

unsigned long long sum(long long n){
  if(n/10==0){
    return n;
  }
  return n%10+sum(n/10);
}

int main(){
  unsigned long long n, f;
  cin>>n;
  cout<<sum(fact(n));

}
