#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxNum(long long a, long long b) {
    if(a > b) {
        return a;
    }

    return b;
}

int main() {
    long long n, k;

    cin>>n>>k;

    long long first, mul, add, mod;

    cin>>first>>mul>>add>>mod;

    long long lastNum = 0;

    lastNum = first;

    long long res = 0;

    long long maxNow = lastNum;
    long long maxNowDay = 0;

    vector<long long> allNums;

    allNums.push_back(lastNum);
    
    res += maxNow;

    for(int i = 1; i < n; ++i) {
        lastNum = (lastNum * mul + add) % mod;

        allNums.push_back(lastNum);

        if(lastNum >= maxNow) {
            maxNow = lastNum;
            maxNowDay = i;
        } 
        else if(i - k >= maxNowDay) {
            long long startIndex = maxNum(0, i + 1 - k);
            maxNow = 0;

            for(int j = startIndex; j <= i; ++j) {
                if(allNums[j] >= maxNow) {
                    maxNow = allNums[j];
                    maxNowDay = j;
                }
            }
        }

        res += maxNow;
    }

    cout<<res<<endl;

    return 0;
}

/*
7 3
5 3 2 23

133742 666
20 3 17 1000000007
*/

