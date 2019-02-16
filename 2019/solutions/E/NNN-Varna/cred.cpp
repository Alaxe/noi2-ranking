#include<iostream>
using namespace std;
int main()
{
int m,n,c,i,ch=0,slel;
cin>>n>>m;
do
{
ch++;
slel=n+(n%10)+(n/10%10)+(n/100%10)+(n/1000%10)+(n/10000%10)+(n/100000%10);
}
while(slel<m);
cout<<ch+1<<endl;
return 0;
}
