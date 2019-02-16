#include<iostream>
using namespace std;
int main()
{
long long a,b,delitel,br=0,chislo,brr=0;
cin>>a>>b;
chislo=a;
while(chislo!=b)
{
    delitel=1;

while(delitel!=chislo)
{
if(chislo%delitel==0)
{
br++;
}
delitel++;
}

if(br%2!=0)
{
    brr++;
}
chislo++;
}
cout<<brr-1<<endl;
}
