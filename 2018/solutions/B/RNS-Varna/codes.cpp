#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<string> generate(vector<string> prev, vector<char> digits);
int convert(string number);
int sum(int f);
int main()
{
	int a,b,max1=0, R[100000],y=0;
	long long N,K,A,B;
	vector<int> vec4,vec5;
	vector<string> vec1,vec2;
	vector<char> vec3;
	char k;
	cin>>N>>K>>A>>B;
	for(int i=0;i<A;i++)
	{
		string a;
		cin>>a;
		k=a[0];
		vec1.push_back(a);
		vec3.push_back(k);
	}
		vec2=generate(vec1,vec3);

		for(int i=A-1;i<B;i++,y++)
		{
			string str=vec2[i];
			//cout<<str<<endl;
			R[y]=convert(str);
		}
		a=sum(R[0]);
		for(int i=1;i<y;i++)
			{
				b=sum(R[i]);
				if(abs(a-b)>max1)max1=abs(a-b);
				a=b;
			}
			sort(R,R+y);
			cout<<R[y-1]<<" "<<max1<<endl;



}
int sum(int f)
{
	int sum1;
	while(f!=0)
	{
		sum1=sum1+f%10;
		f=f/10;
	}
	return sum1;
}
int convert(string number)
{
	string str=number;
	int sum=0;
	for(int i=0;i<str.size();i++)
	{
		sum=sum*10+(str[i]-'0');
	}
	return sum;
}
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
		else {
			for(int j=prev.size()-1;j>=0;j--)
			{
				next.push_back(digits[i]+prev[j]);
			}
		}
	}
	return next;
}
