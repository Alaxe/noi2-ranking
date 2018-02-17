#include <iostream>
#define MAX 1000
using namespace std;
unsigned long M[MAX][MAX];

unsigned long getNum(unsigned n, unsigned m)
{ unsigned i, j;
  for (i = 1; i <= n; i++)
  for (j = 1; j <= m; j++)
   if (1 == j) M[i][j] = 1;
   else if (1 == i) M[i][j] = 1;
   else if (i < j) M[i][j] = M[i][i];
   else if (i == j) M[i][j] = 1 + M[i][i - 1];
   else M[i][j] = M[i][j - 1] + M[i - j][j];
   return M[n][m];
}

int main()
{ int n,m;
  cin>>n>>m;
  cout<<getNum(n,m)<<endl;
  return 0;
}
