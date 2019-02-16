#include <iostream>
using namespace std;
int main ()
{
    long long n , m , br=0 , c , copyn , s=0;
    cin >> n >> m;
    while (n<=m)
    {
        copyn=n;
        while (copyn>0)
        {
            c=copyn%10;
            copyn=copyn/10;
            s+=c;
        }
        n+=s;
        br++;
        s=0;
    }
    cout << br << endl;
}
