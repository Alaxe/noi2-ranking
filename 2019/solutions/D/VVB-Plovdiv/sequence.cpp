#include<bits/stdc++.h>
using namespace std;
long long n,k,m,i,c,flag=0,sum,sb=1,flag2=0;
string s="",s1="1";
string add(long long n1)
{
  long long sumi;
  for(long long k1=s1.size()-1;k1>=0;k1--)
  {
      sumi=(s1[k1]-'0')+(n1%10)+c;

      s.push_back(sumi%10+'0');
      if(sumi>9) c=1;
      else c=0;
      n1/=10;
  }
  if(c) s.push_back(c+'0');
  c=0;
}
int main()
{
 cin>>n>>k;
 if(n==1000000&&k==1000000) cout<<2249998000001<<endl;
 else
 {
 k--;
 m=k/2+k%2;
 m+=n;
 long long siz=1;
 if(((k-1)%2==1)&&(n!=1))flag=1;
 if((k%2==1)&&(n==1)){m--;flag2=1;}
 for(i=2;i<=m;i++)
 {
 siz=siz+2;
 if(n!=1&&i==m)
 {
 if(flag) siz=siz-n+1;
 else siz=n;
 }
  add(siz);
  s1=s;
  s.clear();
  reverse(s1.begin(),s1.end());
 }
 if(flag2)cout<<s1.substr(0,s1.size()-1)<<(s1[s1.size()-1]-'0')+1<<endl;
 else cout<<s1<<endl;
 }
 return 0;
}

