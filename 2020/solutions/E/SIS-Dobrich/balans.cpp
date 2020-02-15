#include<iostream>
using namespace std;
int main ()
{ int i,j,n,ab=0,cd=0;
  cin>>n;
  char u;
  for (i=1;i<=n;i++) 
  {cin>>u;
   if (u=='à' || u=='b') ab++;
   if (u=='c' || u=='d') cd++;
  }
  if(ab==cd)
      cout<<ab+cd<<endl;
  else    
     cout<<0<<endl;
  return 0;
}