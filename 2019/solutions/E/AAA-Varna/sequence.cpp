#include<iostream>
using namespace std;
int main()
{
 int nm=0,r=2;
 long long int n;
 cin>>n;
 if(n==1){cout<<1<<endl;return 0;}
  do
 {nm+=(n+1-n)*r;
  r+=2;
  n--;
 }while(n>1);
 cout<<nm+1<<endl;
}
