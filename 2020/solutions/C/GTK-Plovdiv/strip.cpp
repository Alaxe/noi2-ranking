#include<bits/stdc++.h>
using namespace std;

int arr[60];

int variations(int n, int left, int right, int k, int br)
{
    //cout<<k<<endl;
    if(k<left)
    {
        left = k;
    }
    if(k>right)
    {
        right = k;
    }
    arr[k] = br;
    if(br == n)
    {
        return 1;
    }

    if(left>0 && right<n-1)
    {
        return variations(n, left, right, left - 1, br+1) + variations(n, left, right, right + 1, br+1);
    }

    else if(right == n-1)
    {
        return variations(n, left, right, left - 1, br+1);
    }

    else if(left == 0)
    {
        return variations(n, left, right, right + 1, br+1);
    }
}

int main()
{
    int n, k, left, right;
    cin>>n>>k;

    left = k - 1;
    right = k - 1;

    cout<<variations(n, left, right, k-1, 1)<<endl;

    return 0;
}
