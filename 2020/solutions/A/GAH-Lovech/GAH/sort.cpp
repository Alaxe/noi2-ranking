#include <bits/stdc++.h>
using namespace std;

int DecreasingArray(int a[], int n)
{
    int sum = 0, dif = 0;


    priority_queue<int, vector<int>, less<int> > pq;


    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() > a[i]) {
            dif = -(a[i] - pq.top());
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

    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    cin>>a[i];

    cout << DecreasingArray(a, n)<<endl;

    return 0;
}
