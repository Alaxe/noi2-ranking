#include <bits/stdc++.h>
using namespace std;
int main()
{
    string chislo;
    cin>>chislo;
    long long a=chislo.size(),b=2,n=0,c,br=0;
    while(a!=0)
    {
        n++;
        c=b;
        while(c!=0)
        {
            c=c/10;
            br++;
        }
        a=a-br;
        br=0;
        b=b*2;
    }
    cout<<n<<endl;
    return 0;
}
