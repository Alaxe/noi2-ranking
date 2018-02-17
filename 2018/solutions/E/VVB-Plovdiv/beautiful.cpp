#include<iostream>
using namespace std;
int main()
{
 long long n,k,ch=1,ch2,flag=0,flag2=0;
 cin>>n>>k;
 for (int i=1;i<n;i++)
 {
  ch*=10;
 }
 ch2=ch;

 do
 {
   if(ch%k==0) {flag=1;break;}
   ch++;
 }
  while (ch<ch2*10);
  if(flag==1)cout<<ch<<endl;
  else cout<<"NO"<<endl;
 return 0;
}
