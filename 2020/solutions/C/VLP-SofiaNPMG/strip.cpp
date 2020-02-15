#include <iostream>
#include <vector>
using namespace std;

int dp(vector <int> arr, int n, int l, int r, int stoinost)
{
    if (arr[n-1]!=0 || arr[0]!=0) return 1;
    arr[r]=stoinost;
    int vtoro=dp(arr, n, l, r+1, stoinost+1);
    arr[r]=0;
    arr[l]=stoinost;
    int purvo=dp(arr, n, l-1, r, stoinost+1);
    return purvo+vtoro;
}

vector <int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    arr.resize(51);
    arr[k-1]=1;
    cout<<dp(arr, n, k-2, k, 2)<<'\n';

    return 0;
}
