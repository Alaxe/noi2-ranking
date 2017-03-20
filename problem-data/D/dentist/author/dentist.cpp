#include <iostream>
using namespace std;

char A[721];
short lastmoment,i,j,n;

int main () {
  for (;cin>>i>>j;n++) A[i]=j;
  for (i=0; n; i++) if (A[i]) {
    if (i>=lastmoment) lastmoment=i;
    lastmoment+=A[i];
    n--;
  }
  cout<<lastmoment-i+1<<endl;
  return 0;
}
