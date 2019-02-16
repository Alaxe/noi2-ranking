#include <iostream>
using namespace std;
int main (){
long long n,m,vsichkiStoinosti=0;
cin>>n,m;
while(n<m){
      n=n+n%10+n%100;
      vsichkiStoinosti=vsichkiStoinosti+1;
}
cout<<vsichkiStoinosti;

return 0;
}
