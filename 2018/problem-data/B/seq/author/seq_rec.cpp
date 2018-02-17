#include<iostream>
using namespace std;

typedef long long int INT;

int n; // the total sum of values
int m; // the largest value


INT S(int n, int m)
{
 // if(n<=0) return 0;
  if(n==1) return 1;
  if(m==1) return 1;
  if(n==m) return 1+S(n,m-1);
  if(n < m) return S(n,n);

  return S(n,m-1)+S(n-m,m);

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
