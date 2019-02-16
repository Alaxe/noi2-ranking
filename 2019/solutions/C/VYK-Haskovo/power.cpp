#include<iostream>

using namespace std;

int n, k;
int a[10005];

int max2[50];

void split(int x)
{
    int d = 2;
    while(x!=1)
    {
        if(x%d==0)
        {
            int br = 0;
            while(x%d==0)
            {
                x/=d;
                br++;
            }

            max2[d] = max(max2[d], br);
        }
        else
        {
            d++;
        }
    }
}

int main()
{
    long long ans = 1;

    cin >> n >> k;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
        split(a[i]);
    }

    for(long long i = 2;i<50;i++)
    {
        long long div = max2[i]/k;
        if(div*k<max2[i]) div++;

        for(int j = 0;j<div;j++)
        {
            ans *= i;
        }
    }

    cout << ans << endl;
    return 0;
}

///
