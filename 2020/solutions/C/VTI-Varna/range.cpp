#include<bits/stdc++.h>
using namespace std;
int cmp(int p, int q)
{  return p<q;
}
int a[300005];
int main()
{  int n,m,g1,g2,x,y;
   cin>>n;
   int i=0,j=0,b,s;
   for(i=0; i<n; i++)
   {  cin>>a[i];
   }
   sort(a, a+n, cmp);
   cin>>m;
   for(j=0; j<m; j++)
   {  cin>>g1>>g2;
      if(g1<a[0])y=0;
      b=i/2;
      s=i/2;
      if(g1>a[i-1]||g2<a[0])
      {  cout<<0<<endl;
      }
      else
      {  while(1)
         {  if(g1==a[b]||(g1>a[b]&&g1<a[b+1]))
            {  y=b;
               break;
            }
            if(g1>a[b])b=b/2+b;
            else b=b/2;
         }
         while(1)
         {  if(g2==a[s]||(g2>a[s]&&(g2<a[s+1]||s==i)))
            {  if(g2!=a[s]&&s==y)y=x+1;
               else
               {  x=s;
                  if(s==i)x--;
               }
               break;
            }
            if(g2>a[s])s=s/2+s;
            else s=s/2;
         }
         cout<<x-y+1<<endl;
      }
   }
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
