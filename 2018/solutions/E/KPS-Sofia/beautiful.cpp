#include <iostream>
using namespace std;
int main () {
long long n, k,ncif=1,c;
bool q=false;
cin>>n>>k;
for(long long a=1;a<=18;a++)
{
    if(n>1)
    {
        ncif=ncif*10;
        n--;
    }
}
c=ncif;
while(ncif<c*10)
{
    if(ncif%k==0 and q==false)
    {
        q=true;
        cout<<ncif;
    }
    ncif++;
}
if(q==false)
{
    cout<<"NO";
}


return 0;
}
