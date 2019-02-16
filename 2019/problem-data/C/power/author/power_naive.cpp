#include<iostream>
using namespace std;

const int N=10000;
long long int a[N+1];
int n,k;


int main()
{
   // unsigned long long int x=9419588158802421600;
   // cout << x << endl;

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    long long int c=1;
    long long int B;
    while(1)
    {
      B=1;
      for(int j=1;j<=k;j++) B=B*c;
      //cout << c << " " << B << endl;
      bool f=true;
      for(int i=1;i<=n;i++)
       if(B%a[i]!=0) {f=false; break;}
      if(f) break;
      c++;
    }
    //cout << B << endl;
    cout << c << endl;


}

