#include<bits/stdc++.h>
using namespace std;
int a[45], prime[16]= {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}, primec[16]={0}, maxi[16]={0};
int main ()
{
    int n, nok=1;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(int j=1; j<=14; j++)
        {
            while(a[i]%prime[j] == 0 && a[i] != 0)
            {
                a[i] /= prime[j];
                maxi[j] ++;
            }
            if(maxi[j] > primec[j]) primec[j] = maxi[j];
            maxi[j] = 0;
        }
    }

    int t;
    for(int j=1; j<=14; j++)
    {
        t = (primec[j]/2) + (primec[j]%2);
        for(int i=1; i <= t; i++) nok *= prime[j];
    }
    cout << nok << endl;
    return 0;
}

