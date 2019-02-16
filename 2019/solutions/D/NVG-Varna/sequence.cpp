#include<iostream>
using namespace std;


int main()
{
    long long  n,k;
    cin >> n >> k;
    long long  o = 1;
    long long  max = 1;
    long long  br = 0;
    for(long long  i = 1;;i++)
    {
        if(i == n)br += 1;
        if(i > n)br += 2;
        //cout << i << ' ' << o << endl;
        if(br >= k)break;
        o += max;
        max += 2;
    }
    if(br - k == 0) o = o + (k-1) * 2;
    else if (br - k > 0) o = o + (k-1);

    cout << o << endl;
}
