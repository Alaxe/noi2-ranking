#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
char prev[100000];
vector<char> th;
string kl;
int fg[10000];
long long hy[100000];
int n,k,a,b;
vector<string> u;
long long re=0,mare=0;
vector<string> generate(vector<string> prev, vector<char> digits)
{
	vector<string> next;
	for(int i=0;i<digits.size();i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<prev.size();j++)
			{
				next.push_back(digits[i]+prev[j]);
			}
		}
		else
		{
			for(int j=prev.size()-1;j>=0;j--)
			{
				next.push_back(digits[i]+prev[j]);
			}
		}
	}

	return next;
}
void solve()
{

	int ty;
	for(long long i=a;i<=b;i++)
	{
		ty=0;
		for(int ew=0;ew<u[i].size();ew++)
		{
			ty+=u[i][ew]-'0';
			hy[i]*=10;
			hy[i]+=(u[i][ew]-'0');
		}
		fg[i]=ty;
	}
	re=hy[a];
	for(long long i=a+1;i<=b;i++)
	{
		if(re<hy[i])re=hy[i];
		if(mare<fabs(fg[i]-fg[i-1]))mare=fabs(fg[i]-fg[i-1]);
	}
}
int main()
{

	char f;
	cin>>n>>k>>a>>b;
	a--;
	b--;
	for(int j=0;j<n;j++)
	{
		cin>>f;
		kl="";
		kl+=f;
		u.push_back(kl);
		th.push_back(f);
	}
	for(int ojk=1;ojk<k;ojk++)u=generate(u,th);
	solve();
	cout<<re<<" "<<mare<<endl;
	return 0;
}


/*

3 2 3 5
7 1 5

3 3 10 16
7 1 5



*/

