#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n, k;
    list<int> num;

    int a[10000];
    int p[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    int numPc, numPm[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    long long answ = 1;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            numPc = 0;
            if(a[i]%p[j]!=0)
                continue;
            while(a[i]%p[j]==0)
            {
                a[i]/=p[j];
                numPc ++;
            }

            if(numPm[j]<numPc)
                numPm[j]=numPc;
        }
    }

    for(int i = 0; i < 13; i++)
    {
        int x = numPm[i]/k;

        if(numPm[i] < k && numPm[i] != -1)
            x = 1;
        else if(numPm[i]%k==0 && numPm[i] != -1)
            x++;

        for(int j = 0; j < x; j++)
            answ*=p[i];
    }

    cout << answ << endl;

    return 0;
}
