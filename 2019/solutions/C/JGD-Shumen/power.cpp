#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10024;
int n,k;
int a[maxn];
int d[maxn];
int z=1;
void read()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
}
void nodn()
{
    int nod=a[1];
    for(int i=2; i<=n; i++)
        for(int j=min(nod,a[i]); j<=10000; j++)
        {
            if(nod>j)
            {
                while(z!=i)
                {
                    if(j%a[z]==0&&nod%j==0&&j%a[i]==0)nod=j;
                    z++;
                }
            }
            z=1;
            if(j%nod==0&&j%a[i]==0)
            {
                nod=j;
                j=1;
                break;
            }
        }
    cout<<nod<<endl;
}
int main()
{
    read();
    nodn();
    return 0;
}
