#include<iostream>
#include<cmath>
using namespace std;
int main()
{
      int m,k,s=0,n,pn=0,d;
      cin>>m>>k>>n;
      while(s>k)
      {
            cin>>n;
            if(n%2==0) {s+=n;}
            pn++;
            d=fabs(m-n);
            if(s>k || pn==200 || d==1) {break;}
      }
      cout<<pn<<" "<<s<<endl;
      return 0;
}
