#include<iostream>
using namespace std;
int main()
{
 long long n,mm,k,maxim,sbor=0,q;
 cin>>n;
 cin>>mm;
 maxim=mm;
 sbor+=mm;
 for(int i=2;i<=n;i++)
 {
  cin>>mm;
  sbor+=mm;
  if(mm>maxim) maxim=mm;
 }
 cin>>q;
 cout<<(n*maxim-sbor)*q<<endl;
 return 0;
}
