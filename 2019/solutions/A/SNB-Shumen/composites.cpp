#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	if(n<=26)cout<<26<<endl;
	else if(n<=782)cout<<782<<endl;
	else if(n<=9992)cout<<9992<<endl;
	else if(n<=99998)cout<<99998<<endl;
	else if(n<=999998)cout<<999998<<endl;
    else if(n<=9999998)cout<<9999998<<endl;
    else if(n<=99999992)cout<<99999992<<endl;
    else if(n<=999999992)cout<<999999992<<endl;
    else if(n<=9999999998)cout<<9999999998<<endl;
    else if(n<=99999999992)cout<<99999999992<<endl;
    else if(n<=999999999998)cout<<999999999998<<endl;
    else if(n<=9999999999992)cout<<9999999999992<<endl;
    else if(n<=99999999999998)cout<<99999999999998<<endl;
    else if(n<=999999999999992)cout<<999999999999992<<endl;
    else if(n<=9999999999999998)cout<<9999999999999998<<endl;
    else if(n<=99999999999999992)cout<<99999999999999992<<endl;
    else if(n<=999999999999999998)cout<<999999999999999998<<endl;
    else if(n<=9999999999999999992)cout<<9999999999999999992<<endl;
    else cout<<"99999999999999999992"<<endl;
	return 0;
}
