#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n,nok=1,b,ch;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        nok=(ch*nok)/(__gcd(ch,nok));
    }
    for(b=2;;b++)
    {
        if(((b%nok)*(b%nok))%nok==0) {cout<<b<<endl;return 0;}
    }
}
