#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;
int m,a,b;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
    {
      int w; cin >> w; v.push_back(w);
    }

	sort(v.begin(), v.end());

	cin >> m;
	for(int j=0;j<m;j++)
	{
      cin >> a >> b;
      auto pi=lower_bound(v.begin(),v.end(),a);
	  auto pj=upper_bound(v.begin(),v.end(),b);
      cout << pj-pi << endl;
	}
}
