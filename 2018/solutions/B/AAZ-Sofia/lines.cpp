#include<iostream>
#include<cmath>
using namespace std;
int comb[101], nc=0;
int main()
{
    int n;
    cin>>n;
    int x[1001], y[1001];
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
        x[i] = abs(x[i]);
        y[i] = abs(y[i]);
    }

    for(int j=0; j<n; j++)
    {

        for(int _c=1; _c<=10; _c++)
        {
            int inc_x = x[j];
            int inc_y = y[j];

            for(int i=0; i<n; i++)
            {
                inc_x += _c;
                inc_y += _c;
                if(i!=j && inc_x == x[i] && inc_y == y[i])
                {
                    comb[nc]++;
                }
            }

            nc++;
        }
    }
    int mx = comb[0];
    for(int i=1; i<nc; i++)
    {
        if(mx < comb[i])
        {
            mx = comb[i];
        }
    }
    cout<<mx<<"\n";
    return 0;
}
