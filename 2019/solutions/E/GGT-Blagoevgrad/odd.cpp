#include<bits/stdc++.h>

using  namespace  std;
int main()

{
 int a,b;
cin>>a>>b;
int p=0;
for(int i=a;i<=b;i++)
{
    for(int c=2;c<=i-1;c++)
{
  if (i%c==0)

 {
  break;
  }

 }
  if(i!=2 && i!=3 && i%5!=0 && i%2!=0)
  {
      p=p+1;
  }
 if(i==4)
  {
      p=p+1;
  }
  if(i==1)
  {
      p=p+1;
  }

}


cout<<p/2<<endl;



return 0;

}
