#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> brackets;
	string s;
	cin>>s;
	string ans=s;
	int n=s.length();
	int erasedCnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') brackets.push(i);
		else if(s[i]==')')
		{
			int j=brackets.top();
			//cout<<i<<" "<<j<<endl;
			brackets.pop();
			if((j==0||(j>0&&(s[j-1]=='+'||s[j-1]=='(')))&&(i==n-1||(i<n-1&&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]==')'))))
			{
				//cout<<"0\n";
				//cout<<ans<<endl;
				ans.erase(i-erasedCnt,1);
				ans.erase(j,1);
				//cout<<ans<<endl;
				erasedCnt+=2;
			}
			else if(j>0&&(s[j-1]=='*'||s[j-1]=='/'))
			{
				//cout<<"1\n";
				bool can=true;
				int k=j+1;
				//cout<<"k="<<k<<endl;
				while(k<i&&can)
				{
					int unclosed=0;
					if(s[k]=='(') unclosed=1;
					while(unclosed)
					{
						if(s[k]=='(') unclosed++;
						else if(s[k]==')') unclosed--;
						k++;
					}
					k++;
					if(k<i&&(s[k]=='+'||s[k]=='-')) can=false;
					k++;
				}
				if(can)
				{
					//cout<<ans<<endl;
					ans.erase(i-erasedCnt,1);
					ans.erase(j,1);
					//cout<<ans<<endl;
					erasedCnt+=2;
				}
			}
			else if(i<n-1&&(s[i+1]=='*'||s[i+1]=='/'))
			{
				//cout<<"2\n";
				bool can=true;
				int k=i-1;
				//cout<<"k="<<k<<endl;
				while(k>j&&can)
				{
					int unclosed=0;
					if(s[k]==')') unclosed=1;
					while(unclosed)
					{
						if(s[k]==')') unclosed++;
						else if(s[k]=='(') unclosed--;
						k--;
					}
					k--;
					if(k<i&&(s[k]=='+'||s[k]=='-')) can=false;
					k--;
				}
				if(can)
				{
				//	cout<<ans<<endl;
					ans.erase(i-erasedCnt,1);
					ans.erase(j,1);
				//	cout<<ans<<endl;
					erasedCnt+=2;
				}
			}
		}
	}
	cout<<ans<<endl;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&+(((&/&)))/&

((&+&)*&)+&
&+(&*(&/(&-&))-(&-&))
&/(((&/&)))+&
*/

