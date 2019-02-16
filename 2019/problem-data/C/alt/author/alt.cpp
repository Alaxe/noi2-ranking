#include <iostream>
using namespace std;

const int M=100;
const int N=100;

unsigned long long int d[N + 1][M+1];
int k, m, n;

int main()
{
    cin >> k >> m >> n;
	if (n==1) {cout <<  m-1 << endl; return 0;}

	for (int j=0; j<m; j++) d[1][j] = 1;

	for (int i=2; i<=n; i++)
    for (int j=1; j<m; j++)
    {
      int t=j-k;
      if(t>0) d[i][j] += d[i-1][t];
      t=j+k;
      if(t<m) d[i][j] += d[i-1][t];
    }

	unsigned long long int s = 0;
	for (int j=1; j<m; j++) s += d[n][j];
	cout << s << endl;
}

