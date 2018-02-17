#include <iostream>
using namespace std;

long long brc (long long a)
{
    int br=0;
    for (br;a==0; )
    {
        br++;
    }
    return br;
}

int main ()
{
    int n;
    unsigned long long nmch=1,k,ch;

    cin>>n>>k;

    for(int c=n;c>1;c--)
    {
        nmch*=10;
    }

    ch=nmch;
    ch=ch/k*k;
    if (ch<nmch and ch!=0) ch+=k;

    if (ch==0)cout<<"NO"<<endl;
    else cout<<ch<<endl;

    return 0;
}
