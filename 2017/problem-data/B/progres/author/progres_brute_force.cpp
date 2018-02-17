#include<iostream>
using namespace std;

const int N=10000;
int a[N];
int n;

int p[N];

int c;

void check()
{
//  for(int i=0;i<n;i++) cout << p[i];
//  cout << endl;

 int i=0;
 while(p[i]==0)
 {
   i++;
   if(i==n) return;
 }

 int j=i+1;
 if(j==n) return;
 while(p[j]==0)
 {
   j++;
   if(j==n) return;
 }

 int d=a[j]-a[i];
// cout << "d=" << d << endl;
 if(d<=0) return;

 i=j;
 for(int k=j+1;k<n;k++)
 {
   if(p[k]==0) continue;
   if(p[k]==1)
        if(a[k]-a[i]!=d) return;
   i=k;
 }
 c++;
// cout << "*" << endl;
}

void go(int i)
{
  if(i==n)
  {
    check();
    return;
  }

  p[i]=0;
  go(i+1);
  p[i]=1;
  go(i+1);
}


int main()
{
   cin >> n;
   for(int i=0;i<n;i++) cin >> a[i];
   go(0);
   cout << c << endl;
}

