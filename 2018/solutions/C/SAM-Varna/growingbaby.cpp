#include<iostream>
#include<queue>
using namespace std;
const long long  MOD=(1<<30);
struct element
{
	int s;
	bool l;
};
queue <element> q;
int m,n,p,a;
void Read()
{
	cin>>m>>n>>p>>a;
}
long long b;
void Solve()
{
	int e=n-m;
	if(e<=p)
	{
		cout<<"1"<<endl;
		return;
	}
	element x;
	x.l=1;
	x.s=p;
	q.push(x);
	while(q.empty()==0)
	{
		x=q.front();
		if(x.l==1)
		{
			x.s+=p;
			if(x.s>=e) b++;
			else q.push(x);
			x.s-=p+a;
			x.l=0;
			q.push(x);
		}
		else
		{
			x.s+=p;
			x.l=1;
			if(x.s>=e) b++;
			else q.push(x);
		}
		q.pop();
	}
	cout<<b%MOD<<endl;

}

int main()
{
	Read();
	Solve();
	return 0;
}
