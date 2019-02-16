#include <iostream>
using namespace std;

long long longestDecreasingWithPivot(long long arr[], long long n, long long startIndex, long long endIndex)
{
    long long maxLen = 0;
    long long lds[n];

    for (long long i = startIndex; i < endIndex; i++) {
        lds[i] = 1;
    }

    for (long long i = startIndex+1; i < endIndex; i++) {
        for (long long j = startIndex; j < i; j++) {
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    for (long long i = startIndex; i < endIndex; i++) {
        if (maxLen < lds[i]) {
            maxLen = lds[i];
        }
    }

    return maxLen;
}
long long longestDecreasing(long long arr[], long long n) {
    long long maxLen = 0;
    long long lds[n];

    for (long long i = 0; i < n; i++) {
        lds[i] = 1;
    }

    for (long long i = 1; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    for (long long i = 0; i < n; i++) {
        if (maxLen < lds[i]) {
            maxLen = lds[i];
        }
    }

    return maxLen;
}
long long longestIncreasing(long long arr[], long long n) {
    long long maxLen = 0;
    long long lis[n];

    for (long long i = 0; i < n; i++) {
        lis[i] = 1;
    }

    for (long long i = 1; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (long long i = 0; i < n; i++) {
        if (maxLen < lis[i]) {
            maxLen = lis[i];
        }
    }

    return maxLen;
}
long long longestIncreasingAndDecreasing(long long arr[], long long n) {
    long long answer = 0;

    for(long long pivot=1; pivot<n-1; pivot++){
            if(longestIncreasing(arr, pivot)+longestDecreasingWithPivot(arr, n, pivot, n)>answer) {
                if(pivot%2==0) {
                    answer = longestIncreasing(arr, pivot)+longestDecreasingWithPivot(arr,n, pivot-1, n)-1;
                }else {
                    answer = longestIncreasing(arr, pivot)+longestDecreasingWithPivot(arr,n, pivot, n);
                }
            }
        }

        return answer;
    }

int main() {
    long long n;
    cin>>n;
    long long arr[n];

    for(long long i=0; i<n; i++) {
        cin>>arr[i];
    }

    if(longestIncreasing(arr, n)> longestDecreasing(arr, n) && longestIncreasing(arr, n)>longestIncreasingAndDecreasing(arr, n)) {
        cout<<longestIncreasing(arr, n)<<endl;
    }else if(longestDecreasing(arr, n)>longestIncreasing(arr,n) && longestDecreasing(arr, n) > longestIncreasingAndDecreasing(arr, n)){
        cout<<longestDecreasing(arr, n)<<endl;
    }else {
        cout<<longestIncreasingAndDecreasing(arr, n)<<endl;
    }

}
