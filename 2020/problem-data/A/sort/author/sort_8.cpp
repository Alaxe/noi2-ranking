#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX=999999999;

vector<int> a;
int n;

int a1,a2;


int b[100001];

int rec=MAX;
int s;


void go(int i)
{

  if(i==n)
  {
    if(rec>s) rec=s;
    return;
  }

  for(int v=b[i-1];v<=a2;v++)
  {
    b[i]=v;
    s += abs(a[i]-b[i]);
    if(s<rec) go(i+1);
    s -= abs(a[i]-b[i]);
  }
}


int run()
{
  for(int v=a1;v<=a2;v++)
  {
    b[0]=v;
    s = abs(a[0]-v);
    go(1);
  }

  return rec;

}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
     { int v; cin >> v; a.push_back(v);}

    a1 = *min_element(a.begin(), a.end());
	a2 = *max_element(a.begin(), a.end());

	int r = run();
	cout << r << endl;
}
