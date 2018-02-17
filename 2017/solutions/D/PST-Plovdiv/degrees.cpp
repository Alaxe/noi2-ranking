#include <iostream>
#include <cstring>
using namespace std;
int main()
{
char a[160000],b[1000];
long long l=100,i,ch=2,ch1,n=0,p=0,flag,k=0,j;
cin.getline(a,160000);
l=strlen(a);
cout<<l<<endl;
while(k!=l+1)
{
ch1=ch;
i=1000;
j=0;
while(ch1!=0)
{
b[i]=ch1%10;
ch1=ch1/10;
i=i-1;
j++;
}
for(i=i;i<=1000;i++)
{
if(a[k]==b[i])
{
k++;
}
}
n++;
ch=ch*2;
cout<<k<<endl;
}
cout<<n<<endl;
return 0;
}
