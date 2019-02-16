#include <iostream>
using namespace std;
int main()
{
long long a,b,c,n,d;
cin>>a>>b;
n=0;
c=a;
while(c<=b)
{
     d=0;
    for(int j=0;j<c;j++)
    {
    if(c%j==0)d++;
    }
    if(d%2==1)n++;
    c++;
}

cout<<n<<endl;

    return 0;
}
