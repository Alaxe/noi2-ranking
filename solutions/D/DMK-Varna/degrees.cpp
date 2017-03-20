#include <bits/stdc++.h>
using namespace std;
unsigned long long s (long long a)
{
    long long br=0;
    while (a>=10)
    {
        a/=10;
        br++;
    }
    br++;
    return br;
}

int main()
{
   unsigned long long j=2,i=0,b,c,d,e,sum=0,br=0;
   string t;
   cin>>t;
   for (i=1;;i++)
   {
       sum+=s(j);
       j*=2;
       if (sum>=t.size())break;
   }
   cout<<i<<endl;
}


