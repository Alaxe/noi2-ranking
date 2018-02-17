#include <iostream>
#include <cmath>
using namespace std;

int main(){
  long long n, k, i, p;
  cin>>n>>k;
  p=pow(10,n-1);
  for(i=p;i<=p+k;i++){
    if(i%k==0){
      cout<<i;
      return 0;
    }
  }

}
