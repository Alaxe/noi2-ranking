#include <iostream>
#define MAX 202
using namespace std;

int n,w1,w2;
int dp[MAX][MAX][MAX];

int maximum(int arr[], int n, int w1, int w2, int i){
if(i==n)return 0;

int f1=0,f2=0,fn=0;
if(w1>=arr[i])
    f1 = arr[i] + maximum(arr, n, w1-arr[i], w2, i+1);
if(w2>=arr[i])
    f2 = arr[i] + maximum(arr, n, w1, w2-arr[i], i+1);

fn = maximum(arr, n, w1, w2, i+1);
return dp[i][w1][w2] = max(fn, max(f1,f2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> w1 >> w2;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout<<maximum(arr, n, w1, w2, 0);

    return 0;
}

/*
3 10 2
3 4 5

5 10 14
4 5 6 7 8

Custom Test N1
5 8 5
1 2 3 4 5

Custom Test N2
5 15 6
3 4 5 6 7

Custom Test N3
5 16 6
3 4 5 6 7
*/












