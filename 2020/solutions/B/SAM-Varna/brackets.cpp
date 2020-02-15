#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
string without(string s)
{
	string s1="";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='&') s1+=s[i];
		}
		return s1;
}
string s;
int n;
void Read()
{
	cin>>s;

	s=without(s);

	s="_"+s+"_";
	n=s.size();
}
//CHISTI &!!!!
struct bra
{
	bool ib;
	bool t1;
	bool mc;
};
bra br[200001];
stack <int> a;
	string s1="";

void where()
{
//	int lp=-1;
	for(int i=0;i<n;i++)
	{
		//cout<<i<<" ";
		//if(a.size()!=0) cout<<a.top()<<" *"<<endl;else cout<<" /"<<endl;
		if(a.size()!=0)
		{
			if(s[i]=='+'||s[i]=='-') br[a.top()].t1=1;
		}
		if(s[i]=='(')
		{
			a.push(i);
			br[i].ib=true;
		}
		if(s[i]==')')
		{
			br[i].ib=true;
			if(s[a.top()-1]=='/')
			{
				br[a.top()].mc=0;
				br[i].mc=0;
				//cout<<i<<endl;
			}
			else if(br[a.top()].t1==1)
			{
				if((s[a.top()-1]=='-')||(s[a.top()-1]=='*')||(s[i+1]=='*')||(s[i+1]=='/'))
					{br[a.top()].mc=0;br[i].mc=0;}
					else {br[a.top()].mc=1;br[i].mc=1;}
					//cout<<a.top()<<" "<<i<<endl;
			}
			else
			{
				br[a.top()].mc=1;
				br[i].mc=1;
				//cout<<i<<endl;
			}

			a.pop();
		}
	}
	for(int i=1;i<n-1;i++)
	{
		if(br[i].mc!=1)
		{
			s1+=s[i];
		}
	}

}

void reconstruction()
{
		s1="_"+s1+"_";
		s="";
		for(int i=1;i<s1.size();i++)
		{
			if(s1[i]!='('&&s1[i-1]!=')')
			{
				s+="&";
			}
			if(i!=s1.size()-1) s+=s1[i];
		}
		cout<<s<<endl;
}
int main()
{
	Read();
	where();
	reconstruction();
	return 0;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&+((((&/&))))/&
*/
