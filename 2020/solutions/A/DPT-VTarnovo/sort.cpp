#include<bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, a[MAX], ans;

priority_queue<int , vector<int>, less<int> > q;

int main()
{
	scanf("%lld",&n);
	for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
	{
		if(q.size() > 0 && q.top() > a[i])
		{
			ans += q.top() - a[i];
			q.pop();
			q.push(a[i]);
			
		}
		q.push(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}

