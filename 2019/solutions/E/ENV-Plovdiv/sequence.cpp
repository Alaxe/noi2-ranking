#include<iostream>
using namespace std;
int main()
{
 long long n,miasto,i;
 cin>>n;
 miasto=n;
 for(i=1;i<=n-1;i++)
 {
 miasto=(i*2-1)+miasto;
 }
 cout<<miasto<<endl;
 return 0;
}
