#include<iostream>
#include<cstring>
using namespace std;


const int N=1000;
int a[N];
int n,w1,w2;

// r1 remaining capacity of 1st container
// r2 remaining capacity of 2nd container
// i current index of a[]

int R(int r1, int r2, int i)
{
	if (i == n) return 0;

	int p1 = 0, p2 = 0, p = 0;
	if (r1 >= a[i])
		p1 = a[i] + R(r1 - a[i], r2, i + 1);
	if (r2 >= a[i])
		p2 = a[i] + R(r1, r2 - a[i], i + 1);
	p = R(r1, r2, i + 1);

    return max(max(p1, p2), p);

}


int main()
{
	cin >> n >> w1 >> w2;
	for(int i=0;i<n;i++) cin >> a[i];
	int r = R(w1, w2, 0);
	cout << r << endl;
}
