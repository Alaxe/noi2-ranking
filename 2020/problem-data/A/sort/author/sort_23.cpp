#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int n;

int run()
{
  if(a[0]>a[1]) return a[0]-a[1];
  if(a[n-1]<a[n-2]) return a[n-2]-a[n-1];

  for(int i=0;i<n-2;i++)
    if(a[i]<=a[i+2])
     {
       if(a[i+1]<a[i]) return a[i]-a[i+1];
       if(a[i+1]>a[i+2]) return a[i+1]-a[i+2];
     }

  return 0;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
     { int v; cin >> v; a.push_back(v);}
	int r = run();
	cout << r << endl;
}
