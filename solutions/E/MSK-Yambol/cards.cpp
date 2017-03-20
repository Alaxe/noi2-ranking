#include <iostream>
using namespace std;
long long x[1000];
int main()
{
  long long n,i=0,a,b,br=0,brmax=0;
  bool f=true;
  cin>>n;
  cin>>a>>b;
  for(i=1;i<=n;i++)
  {
      cin>>a>>b;
      x[i]=a;
      x[i+1]=b;
      i=i+2;
  }
  for(i=1;i<=n*2;i++)
  {
      if((x[i]>=x[i+2]&&x[i+1]>=x[i+3])) {br++;i=i+2;if(br>brmax) brmax=br;}
        else if(x[i+3]<=x[i]&&x[i+2]<=x[i+1]) {br++;i=i+2;if(br>brmax) brmax=br;}
             else br=0;

  }
  cout<<brmax;
  return 0;
}
