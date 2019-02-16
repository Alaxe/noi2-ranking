#include<iostream>
using namespace std;

#define ULL unsigned long long int

const int N=10000;
int a[N+1];
int n,k;

const int np=13;
int p[np+1]={0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int s[np+1];

ULL gcd(ULL a, ULL b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    ULL M=a[1];
    for(int i=2;i<=n;i++) M = (M*a[i])/gcd(M, a[i]);

    //cout << M << endl; // LCM of a[1], ..., a[n];

    for(int j=1;j<=np;j++)
     while(M%p[j]==0) {s[j]++;M=M/p[j];}

    for(int j=1;j<=np;j++)
    {
      if(s[j]>0)
      {
        if(s[j]%k!=0) s[j]=s[j]+(k-s[j]%k);
        s[j]=s[j]/k;
      }
    }




    ULL R=1;
    for(int j=1;j<=np;j++)
    {
      for(int t=1;t<=s[j];t++) R=R*p[j];
    }

    cout << R << endl;
}

