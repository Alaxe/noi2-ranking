#include<bits/stdc++.h>
using namespace std;
bool usedp[1000001],usedm[1000001];
int n,i,ar[1001],mem[1001],j;
unsigned long long br;
void check(int x)
{
    if(x<0)
    {
        abs(x);
        if(!usedm[x])
        {
            usedm[x]=true;
            br++;
        }
    }
    else
    {
      if(usedp[x])
      {
          usedp[x]=true;
          br++;
      }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 cin>>n;
 for(i=0;i<n;i++)
 {
     cin>>ar[i];
     check(ar[i]);
 }
 mem[0]=ar[0];
 for(i=1;i<n;i++)
 {
     mem[i]=mem[i-1]+ar[i];
      check(mem[i]);
 }
 for(i=2;i<n;i++)
 {
     for(j=0;j<i-1;j++)
     {
         check(mem[i]-mem[j]);
     }
 }
 cout<<br<<"\n";
 return 0;
}
/*
5
1 -2 0 7 7
*/
