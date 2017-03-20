#include<iostream>
using namespace std;

typedef long long int INT;

const int N=10000;
int a[N];
int n;
INT T[N];

INT mod=123456789012345LL;


int main()
{
   cin >> n;
   for(int i=0;i<n;i++) cin >> a[i];

   int m2=0;
   for(int i=0;i<n;i++) if(m2<a[i]) m2=a[i];

   int m1=m2;
   for(int i=0;i<n;i++) if(m1>a[i]) m1=a[i];

   INT r=0;
   for(int d=1;d<=m2-m1;d++)
   {
     T[0]=0;
     for(int i=1;i<n;i++)
     {
       T[i]=0;
       INT s=0;
       for(int j=0;j<i;j++) if(a[j]+d==a[i]) s = (s+T[j]+1)%mod;;
       T[i] = s;
       r = (r+T[i])%mod;;
     }
   }
   cout << r << endl;
}

