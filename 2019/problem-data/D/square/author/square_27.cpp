#include<iostream>
using namespace std;

const int N=10000;
long long int a[N+1];
int n;


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    long long int c=1;
    long long int B;
    while(1)
    {
      B=c*c;
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

