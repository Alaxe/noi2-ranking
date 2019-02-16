#include <bits/stdc++.h>
using namespace std;

int isused[44]={0};

int main ()
{
    int n,k;
    cin >> n;

    for (int i=0;i<n;i++)
    {
        cin >> k;
        for (int j=2;j<44;j++)
        {
            if (k%j==0)
            {
                int a=0;
                while (k%j==0)
                {
                    k/=j;
                    a++;
                }
                if (a>isused[j])isused[j]=a;
            }
        }
    }

    for (int i=2;i<44;i++)
    {
        if (isused[i]%2!=0)isused[i]++;
        isused[i]/=2;
    }

    uint64_t mult=1;
    for (int i=2;i<44;i++)
    {
        for (int j=0;j<isused[i];j++)
        {
           mult*=i;
        }
    }

    cout << mult << endl;

    return 0;
}
