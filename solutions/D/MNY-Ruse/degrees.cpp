#include<iostream>
using namespace std;
int main() {

long long n,how=0;
cin>>n;
while(n!=1)
if(n%2==0){how++;n=n/2;}
else break;
cout<<how<<endl;
return 0;

}
