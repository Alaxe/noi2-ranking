#include <iostream>
using namespace std;
long long ch[100000];
int main()
{
  long n,i=0,j=0,a=0,br=0,k=0,f=0,b=0,c=0;
  bool fl=true;
  cin>>n;
  for(i=1;i<n;i++)
     for(j=1;j<n;j++)
  {
      a=i*j;
      b=i;
      c=j;
     for(k=1;k<=a;k++)
     {
         ch[i]=a%10; br++;
         a=a/10;
     }
     if(br%2==0)
     {f=br;
         for(k=1;k<=br/2;k++)
         {
                if(ch[i]==ch[f]) {f--;fl=true;}
                else fl=false;
         }
     }
     if(fl==true) break;
  }
  cout<<b<<" "<<c<<endl;
  cout<<b*c;
  return 0;
}
