#include<iostream>
#define MAX 100001
using namespace std;
int n;
int input[MAX];
int moves=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n;
	for(int a=0; a<n; a++)
	{
        cin>>input[a];
	}
	for(int a=1; a<n; a++)
	{
		if(input[a]<input[a-1])
		{
			moves=input[a-1]-input[a];
		}
	}
	cout<<moves<<endl;
	return 0;
}
