#include <bits/stdc++.h>

using namespace std;

int DecreasingArray(int a[],int n){

int sum = 0, dif = 0;
    priority_queue<int, vector<int>, less<int> > pq;
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() > a[i]) {
            dif = pq.top()-a[i];
            sum += dif;
            pq.pop();
            pq.push(a[i]);
        }
        pq.push(a[i]);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    const int s = n;
    int arr[s];
    for(int i =0;i<n;++i){
        cin>>arr[i];
    }
    cout << DecreasingArray(arr, n);
    return 0;
}
