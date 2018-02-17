#include <iostream>
using namespace std;
int main(){
int n;
long long a=1;
long long k;
long long  ch=0;

cin>> n >> k;

for (int i=1; i<n; i++){
     a=a*10;
     ch=a;
}
while ((ch%k)!=0){
     ch++;
     }

cout<< ch << endl;

return 0;
}