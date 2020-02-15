#include<bits/stdc++.h>
using namespace std;
long long n,a[26],br;
string st,st1;
struct s
{
 long long x;
 char c;
}b[15000000];
bool cmp1(s l ,s p)
{
 if(l.c>p.c) return 0;
 return 1;
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 cin>>st;
 long long sz=st.size();
 long long i;
 for(i=0;i<sz;i++)
 {
  if(!a[st[i]-'A']) {br++;a[st[i]-'A']=1;}
  b[i].x=i;
  b[i].c=st[i];
 }
 sort(b,b+sz,cmp1);
 st+="-"; st1=st;

 n=26-br+1;
 long long n1=1;
 for(i=0;i<sz;i++)
 {
  st[b[i].x]=char('A'+n-1);
  st1[b[i].x]=char('A'+n1-1);
  if (b[i+1].c!=b[i].c)n++;
  if (b[i+1].c!=b[i].c)n1++;
 }
 cout<<st1.substr(0,sz)<<endl<<st.substr(0,sz)<<endl;
 return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
1 4
9 12
15 20
*/

