#include<iostream>
#include<algorithm>
using namespace std;

const int N=10000000;
int v[N];
int n,m,a,b;

int lower(int a)
{
	int i1 = 0, i2 = n - 1;
	while (i1 <= i2)
    {
      int c = (i1 + i2) / 2;
      if (v[c] >= a) i2 = c - 1;
      else i1 = c + 1;
	}
	return i1;
}

int upper(int b)
{
	int i1 = 0, i2 = n - 1;
	while (i1 <= i2)
    {
      int c = (i1 + i2) / 2;
      if (v[c] <= b) i1 = c + 1;
      else i2 = c - 1;
	}
	return i2;
}

int main()
{
    cin >> n;
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v, v+n);

	cin >> m;
	for(int j=0;j<m;j++)
	{
      cin >> a >> b;
      int pj=upper(b);
      int pi=lower(a);
      cout << pj-pi+1<< endl;
	}

}
