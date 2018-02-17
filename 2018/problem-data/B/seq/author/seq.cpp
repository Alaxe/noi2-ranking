#include<iostream>
using namespace std;

typedef long long int INT;

INT t[301][301];

int n; // the total sum of values
int m; // the largest value


INT S(int n, int m)
{
  INT r=t[n][m];
  if(r>0) return r;

  if(n==1) r=1;
  else if(m==1) r=1;
  else if(n==m) r = 1+S(n,m-1);
  else if(n < m) r=S(n,n);
  else r=S(n,m-1)+S(n-m,m);

  t[n][m]=r;
  return r;
}

int main()
{
    cin >> n >> m;
    INT v=S(n,m);
    cout << v << endl;
}

/*
n=6, m=5

5 1
4 2
4 1 1
3 3
3 2 1
3 1 1 1
2 2 2
2 2 1 1
2 1 1 1 1
1 1 1 1 1 1
*/
