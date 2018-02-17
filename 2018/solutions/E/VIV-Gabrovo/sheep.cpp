#include <iostream>
using namespace std;
int main()
{
    int n, l;
    int br=0, c1j, c2j, j;
    int big=0;
    cin>>n;
    cin>>l;
    for(int i=1; i<=l; i++)
    {
        cin>>l;
        for(int j=1; j<=n; j++)
        {
                c1j=(j/10)%10;
                c2j=j%10;
                if (c1j==l)c1j++;
                if (c2j==l)c2j++;
                br++;
                if (c1j==l && c2j==l) br--;
                if (br==n)break;
        }

    }
    big=c1j*10+c2j*1;
    cout<<" "<<endl;
    cout<<big<<endl;
    return 0;
}
