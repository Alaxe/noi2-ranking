#include<iostream>
using namespace std;

const int N=10000000;
int v[N];
int n,m,a,b;

int count(int a, int b)
{
  int c=0;
  for(int i=0;i<n;i++)
  if(a <= v[i] && v[i] <= b) c++;
  return c;
}

int main()
{
    cin >> n;
	for(int i=0;i<n;i++) cin >> v[i];

	cin >> m;
	for(int j=0;j<m;j++)
	{
      cin >> a >> b;
      int c = count(a,b);
      cout << c << endl;
	}

}
