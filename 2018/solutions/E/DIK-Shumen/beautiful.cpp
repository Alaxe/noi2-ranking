#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main ()
{
long long int n,k,br=0;
cin>>n>>k;
long long int ch=1,h=n;

for (long long int i=n;n>1;n--)
{
    ch=ch*10;
}

while (ch%k!=0)ch++;
long long int p=ch;
while (p!=0)
{
    br++;
    p=p/10;
}

if (br==h)
{
    cout<<ch<<endl;
}
else
{
    cout<<"NO"<<endl;
}
return 0;
}
