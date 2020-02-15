#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long int n;
	cin>>n;
	char s;
	int br1=0;
	int br2=0;
	int bro=0;
	for (int i=0; i<n; i++)
	{
	    cin>>s;
	    if(s=='a'||s=='b')
        {
            br1++;
        }
        else
        {
            br2++;
        }
        if(br1==br2)
        {
            bro=br1+br2;
        }
	}
	cout<<bro<<endl;
	return 0;
}
