#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool used[500];
bool isPossibleSum;

void findSubset(long *arr, long n, long currSum, long index, long sum, long *solution) {

    if(currSum==sum) {
        int testSum = 0;
        for(int i=0; i<n; i++) {
            if(solution[i]) {
                testSum+=arr[i];
            }
        }
        if(testSum==sum) {
        isPossibleSum = true;
        for(int i=0; i<n; i++) {
            if(solution[i] && !used[i]) {
                used[i] = true;
            }
        }
        }
        return;

    }
    else if(index==n) {
        return;
    }
    else {
        if(used[index]) {
            findSubset(arr, n, currSum, index+1, sum, solution);
        }else {
        solution[index] = 1;
        currSum += arr[index];
        findSubset(arr, n, currSum, index+1, sum, solution);
        currSum-=arr[index];
        solution[index] = 0;
        findSubset(arr, n, currSum, index+1, sum, solution);
        }
    }
    return;
}


int main() {
    isPossibleSum = false;
    long n, w1, w2, tempw1, tempw2;
    long sum11 = 0;
    long sum21 = 0;
    long sum12 = 0;
    long sum22 = 0;
    cin>>n>>tempw1>>tempw2;
    long arr[n];
    long solution[n];


    for(long i=0; i<n; i++) {
        cin>>arr[i];
        used[i] = false;
    }

    sort(arr+0, arr+n);
    w1 = max(tempw1, tempw2);
    w2 = min(tempw1, tempw2);

    for(int i=w1; i>=0; i--) {
        findSubset(arr, n, 0, 0, i, solution);
        if(isPossibleSum) {
            sum11 = i;
            break;
        }
    }

    isPossibleSum = false;

    for(int i=w2; i>=0; i--) {
        findSubset(arr, n, 0, 0, i, solution);
        if(isPossibleSum) {
            sum12 = i;
            break;
        }
    }


    for(int i=0; i<n; i++) {
        used[i] = false;
    }

    isPossibleSum = false;

    for(int i=w2; i>=0; i--) {
        findSubset(arr, n, 0, 0, i, solution);
        if(isPossibleSum) {
            sum21 = i;
            break;
        }
    }

    isPossibleSum = false;

    for(int i=w1; i>=0; i--) {
        findSubset(arr, n, 0, 0, i, solution);
        if(isPossibleSum) {
            sum22 = i;
            break;
        }
    }

    cout<<max(sum11+sum12, sum21+sum22)<<endl;

}
