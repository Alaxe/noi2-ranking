//Task: long
//Author: Kinka Kirilova-Lupanova

#include<iostream>
#include<cstdlib>
using namespace std;

int longmod(int n, int k)
{
   int a=10;
   int c=1;

   while(c<n)
   {
     while(a/k<1) {a=10*a; c++; if(c>=n) return a/10;}
     a=a%k;
     if(a==0) return 0;
     a=10*a;
     c++;
   }
   return a/10;

}

int main()
{
    long long int n,k;
    cin >> n >> k;
    int v=longmod(n,k);
    int p=k-v;

    int p0=p;
    int d=0;
    while(p0>0){p0=p0/10;d++;}

    if(d==n) {cout << k << endl; return 0;}

    if(v==0)
    {
      cout << 1;
      for(int i=2;i<=n;i++) cout << "0";
      cout << endl;
    }
    else
    {
     if(d<n) cout << 1;
     for(int i=2;i<=n-d;i++) cout << "0";
     cout << p << endl;
    }
}
