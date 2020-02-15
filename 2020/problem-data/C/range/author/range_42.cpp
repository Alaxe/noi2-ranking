#include<iostream>
#include<algorithm>
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
	sort(v,v+n);

	cin >> m;
	for(int j=0;j<m;j++)
	{
      cin >> a >> b;
      int i1=0;
	  while(v[i1]<a)
       { i1++;
         if(i1>=n) {cout << 0 << endl; break;}
       }
      if(i1>=n) continue;

      int i2=n-1;
	  while(v[i2]>b)
       { i2--;
         if(i2<0) {cout << 0 << endl; break;}
       }
      if(i2<0) continue;



	  cout << i2-i1+1 << endl;
	}

}
