#include<iostream>
using namespace std;
int main ()
{
long n,m,c=0,ch;
cin>>n>>m;
for (int i=n;i<=m;i++)
{
if (i<10) ch=i+i;
if (i<100&&i>9) ch=i+i/10+i%10;
if (i<1000&&i>99) ch=i+i/100+i/10%10+i%10;
if (i<10000&&i>999) ch=i+i/1000+i/100%10+i/10%10+i%10;
if (i<10000&&i>9999) ch=i+i/10000+i/1000%10+i/100%10+i/10%10+i%10;
if (i>99999) ch=i+i/100000+i/10000%10+i/1000%10+i/100%10+i/10%10+i%10;
if (ch<=m) c++;
i=ch;
}
cout<<c+1<<endl;
return 0;
}
