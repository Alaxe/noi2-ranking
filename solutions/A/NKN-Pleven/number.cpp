#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
long long n,m,a1=0,a2=1,br=0;
cin>>m>>n;
if(m>=n)
{
return 0;
}
if(m<1)
{
    return 0;
}
else
{
while(a1*a2<=n)
{
    a1++;
    a2++;
    if(a1*a2>=m&&a1*a2<=n)
    {
        br++;
    }
}
cout<<br;

}
return 0;
}
