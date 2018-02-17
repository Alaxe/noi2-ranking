#include<iostream>
using namespace std;

const int N = 1000;
const int M = 2000002;

int a[N];
int n;

int T[M];
int m1, m2;

int main()
{   cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    for (int i=0; i<n; i++)
        if(a[i]<0) m1 += a[i];
    m1=-m1;

    for (int i=0; i<n; i++)
        if(a[i]>=0) m2 += a[i];

    T[a[0]+m1]=1;

    for(int i=1; i<n; i++)
    {
      if(a[i]<0)
      for(int j=-m1+a[i];j<=m1+m2;j++)
       if(T[j+m1-a[i]]) T[j+m1]=1;


      if(a[i]>0)
      for(int j=m1+m2;j>=-m1+a[i];j--)
       if(T[j+m1-a[i]]) T[j+m1]=1;

      T[a[i]+m1]=1;
    }

    int c=0;
    for (int j=0; j<=m1+m2+1; j++)
        if (T[j]) c++;
    cout << c << endl;
}
