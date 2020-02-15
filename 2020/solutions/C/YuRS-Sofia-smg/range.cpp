#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAXN 100005
typedef long long lon;
lon br, arr[MAXN];
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> br;
    for(lon i = 0; i < br; ++i){
        cin >> arr[i];
    }
    lon queries; cin >> queries;
    sort(arr, arr + br);
    for(lon i = 0; i < queries; ++i){
        lon from, to; cin >> from >> to;
        cout << upper_bound(arr, arr + br, to) - lower_bound(arr, arr + br, from) << endl;
    }
    return 0;
}
