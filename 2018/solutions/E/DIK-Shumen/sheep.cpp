#include<iostream>
using namespace std;

int main()
{
long long int n,l,a,br=0,o=0,br2=0;
cin>>n>>l;
for (long long int i=0;i<l;i++)
{
    cin>>a;
    br=br*10+a;
}
long long int ed=10,des=10,stot=10;
if (br>=0&&br<=9)
{
    ed=br%10;
}
else
if (br>=10&&br<=99)
{
    ed=br%10;
    des=br/10%10;
}
else
if (br>=100&&br<=999)
{
    ed=br%10;
    des=br/10%10;
    stot=br/100%10;
}

for (long long int j=1;j<=n;j++)
{

    long long int p=j;
    while (p!=0)
    {

        long long int d=p%10;
       if ((d==ed||d==des||d==stot))br2++;

       p=p/10;
    }
    if (!(br2==0))
    {
        n++;
        }o=j;

   br2=0;

}
cout<<o<<endl;
return 0;
}
