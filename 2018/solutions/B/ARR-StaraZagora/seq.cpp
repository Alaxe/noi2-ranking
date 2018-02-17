#include <iostream>
using namespace std;
int m,n;

int req(int k, int t)
{
  if(t==1) return 1;
  int br=0;
  for(int i=k; i>=0;i-=t)
 {
    br+=req(i,t-1);
 }

return br;
}
int main()
{

    cin>>n>>m;
cout<<req(n,m)<<endl;
	return 0;
}