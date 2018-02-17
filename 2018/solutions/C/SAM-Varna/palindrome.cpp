#include<iostream>
#include<string>
using namespace std;
string pal(string s)
{
	int n=s.size();
	int i,j;
	for(i=0,j=n-1;i<=j;i++,j--)
	{
		s[j]=s[i];
	}
	return s;
}

string s;
void Read()
{
	cin>>s;
}
void Solve()
{
	int n=s.size();
	bool f=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='9')
		{
			f=1;
			break;
		}
	}
	if (f==0)
	{
		cout<<"1";
		for(int i=0;i<n-1;i++) cout<<"0";
		cout<<"1"<<endl;
		return;
	}
	string s1;
	s1=pal(s);
	if(s<s1) {cout<<s1<<endl;return;}

		for(int i=s1[n/2]-'0';i<9;i++)
		{
			s1[(n-1)/2]=char(i+'0');
			s1=pal(s1);
			if(s1>s)
			{
				cout<<s1<<endl;
				return;
			}
		}
		s1[(n-1)/2]='0';
		for(int i=(n-1)/2-1;i>=0;i--)
		{
			if(s1[i]<'9')
			{
				s1[i]+=1;
				s1=pal(s1);
				cout<<s1<<endl;
				return;
			}
			else s1[i]='0';
		}
}
int main()
{
	Read();
	Solve();
	return 0;
}
