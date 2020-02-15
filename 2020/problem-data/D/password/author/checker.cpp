//Author: Martin Marinov
#include <bits/stdc++.h>

using namespace std;

int broi[300];
int main(int argc, char *argv[])
{
	ifstream test(argv[1]);
	ifstream prav(argv[2]);
	ifstream cont(argv[3]);
	string inp,ver,sust;
	getline(test,inp);
	getline(prav,ver);
	getline(cont,sust);
	bool flag=1;
	for(int i=0;i<300;i++)broi[i]=0;
	if(sust.size()&&sust[sust.size()-1]<'a'||sust[sust.size()-1]>'z')sust.erase(sust.size()-1,1);
	if(inp.size()&&inp[inp.size()-1]<'a'||inp[inp.size()-1]>'z')inp.erase(inp.size()-1,1);
	if(ver.size()&&ver[ver.size()-1]<'a'||ver[ver.size()-1]>'z')ver.erase(ver.size()-1,1);
	if(sust.size()!=ver.size())
	{
		cout<<0;
		cerr<<"Passwords should have an equal size!";
		return 0;
	}
	for(int i=2;i<sust.size();i++)
	{
		if(sust[i-2]==sust[i-1]&&sust[i-1]==sust[i])
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
	{
		cout<<0;
		cerr<<"There must not be three or more same neighbouring letters ";
		return 0;
	}
	for(int i=0;i<sust.size();i++)
	{
		broi[int(sust[i]-'a')]++;
		if(broi[int(sust[i]-'a')]>sust.size()/2)
		{
			cout<<0;
			cerr<<"There mustn't be the same characters more than half of size times ";
			return 0;
		}
	}
	int brjp=0,brcp=0;
	for(int i=0;i<sust.size();i++)
	{
		if(inp[i]!=ver[i])brjp++;
		if(inp[i]!=sust[i])brcp++;
	}
	if(brjp<brcp)
	{
			cout<<0;
			cerr<<"You should do this with minimum number of changes. Author's changes: "<<brjp<<" Your changes: "<<brcp;
			return 0;
	}
	else if(brjp==brcp)
	{
		cout<<1;
		cerr<<"Correct answer";
	}
	else
	{
		cout<<1;
		//cerr<<"Better than author's one";
	}
	//cout<<1;
	return 0;
}
