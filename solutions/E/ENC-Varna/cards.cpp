#include <iostream>
using namespace std;
int main ()
{
    int m[200000],l[200000],i,n,br=1,br1=1,k;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>m[i]>>l[i];
        if (m[i]*l[i]<=m[i-1]*l[i-1])
        {
            br++;
        }
        if ((br>1)&&(m[i]*l[i]>m[i-1]*l[i-1]))break;
    }
    for (k=1;k<=n-i;k++)
    {
        cin>>m[k]>>l[k];
        if (m[k]*l[k]<=m[k-1]*l[k-1])
        {
            br1++;
        }
    }

    if (br1>=br)cout<<br1+1<<endl;
    else cout<<br<<endl;


    return 0;
}
