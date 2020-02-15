#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define LL long long int

vector<int> a;
int n;

LL run()
{
  LL s=0;
  priority_queue<LL> pq;
  for (int i = 0; i < n; i++)
  {
    if (!pq.empty() && pq.top() > a[i])
    {
       s += (pq.top() - a[i]);
       pq.pop();
       pq.push(a[i]);
    }
    pq.push(a[i]);
   }
  return s;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
     { int v; cin >> v; a.push_back(v);}
	LL r = run();
	cout << r << endl;
}
