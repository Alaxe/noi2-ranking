#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int n, k;
bool used[64];
long long int cnt_ways()
{
    long long int ans = 1;
    for(long long int i=0; i<k; i++)
    {
        if(n-i<=k && !used[n-i])
        {
            used[n-i] = true;
        }
        else
        {
            ans *= (n-i);
        }
    }
    for(long long int i=0; i<k; i++)
    {
        if(!used[k-i])
        {
            ans /= (k-i);
        }
    }
    return ans;
}
void read()
{
    cin >> n >> k ;
    if(k==1 || k==n)
    {
        cout << "1" << endl;
        exit(0);
    }
    long long int l = k-1;
    if(n-k < l) l = n-k;
    n --;
    k = l;
    cout << cnt_ways() << endl;
}
int main()
{
	read();
    return 0;
}
