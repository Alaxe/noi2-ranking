#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

stack <int> b;
string s;
int b_out_priority[200010],b_in_priority[200010];
int bracket[200010];
int n;

int getpriority(char ch,bool before)
{
	if(ch=='-'&&before)return 2;
	if(ch=='+'||ch=='-')return 1;
	if(ch=='*'||ch=='/')return 3; 
}

void calc_out()
{
	fill(bracket,bracket+n,-1);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')b.push(i);
		if(s[i]==')')
		{
			bracket[i]=b.top();
			bracket[b.top()]=i;
			b.pop();
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			if(i>0&&s[i-1]!='(')b_out_priority[i]=max(b_out_priority[i],getpriority(s[i-1],true));
			if(bracket[i]<n-1&&s[bracket[i]+1]!=')')b_out_priority[i]=max(b_out_priority[i],getpriority(s[bracket[i]+1],false));
			b_out_priority[bracket[i]]=b_out_priority[i];
		}
	}
}

void calc_in()
{
	stack <int> priority;
	for(int i=0;i<n;i++)
	{
		if(!priority.empty()&&s[i]!='('&&s[i]!='&'&&s[i]!=')')
			priority.top()=min(priority.top(),getpriority(s[i],s[i+1]=='('));
		if(s[i]=='(')priority.push(5);
		if(s[i]==')')
		{
			b_in_priority[i]=priority.top();
			b_in_priority[bracket[i]]=priority.top();
			priority.pop();
		}
	}
}

void solve()
{
	string s1="";
	n=s.length();
	calc_out();
	calc_in();
	for(int i=0;i<n;i++)if(b_in_priority[i]>=b_out_priority[i]&&b_in_priority[i]!=0)s[i]=' ';
	for(int i=0;i<n;i++)
		if(s[i]!=' ')
			s1+=s[i];
	cout<<s1<<endl;

}

int main()
{
	cin>>s;
	solve();
}
/*
((&+&)*&)/&
&+((((&/&))))/& 
&+(&*(&-&)-(&-&))
*/
