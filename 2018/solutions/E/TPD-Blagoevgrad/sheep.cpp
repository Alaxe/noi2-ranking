#include  <bits/stdc++.h>
using  namespace  std;
bool chis(int n,int u)
{while (n!=0 and n%10!=u)
       n=n/10;
  return n%10==u;                 }

int main()
{
 int n,l,bro=0,brt=0,brth=0,u=0;
 int w[3];
 cin>>n>>l;
 while (bro!=l)
{
    cin>>w[bro];
bro++;
}
   while (brt<=n)
{brth++;
 brt++;
 u++;
 if  (chis(n,u)) brth++;

           }
cout<<brt*2<<endl;
return 0;
}
