#include <iostream>

using namespace std;

int abs(int n){
    if(n < 0){
        n = -n;
    }

    return n;
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long minresult = 9999999999999;
    for(int maxindex = 0; maxindex < n; maxindex++){
        long long result = 0;
        int totalmax = nums[maxindex];
        int currmax = nums[0];
        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(curr < currmax){
                result += abs(currmax - curr);
            }
            if(curr > currmax){
                currmax = curr > totalmax ? totalmax : curr;
                result += abs(currmax - curr);
            }
        }
        //cout << "res: " << result << endl;
        if(result < minresult){
            minresult = result;
        }
    }

    cout << minresult << endl;
}
