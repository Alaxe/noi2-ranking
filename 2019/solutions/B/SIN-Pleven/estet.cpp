#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int n, ans;
vector<int> nums;

int main ()
{
    cin>>n;

    int up[n], down[n], prevhigher[n], prevsmaller[n];

    for (int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    up[0] = 1;
    prevhigher[0] = -1;
    prevsmaller[0] = -1;

    for (int i=1; i<n; i++)
    {
        int cur=i-1;
        int mx=0, mxindex=-1;
        prevhigher[i] = -1;
        bool foundbigger=false, foundsmaller=false;
        while (1)
        {
            if (nums[cur] >= nums[i])
            {
                if (foundbigger == false)
                {
                    prevhigher[i] = cur;
                    foundbigger = true;
                }
                if (prevsmaller[cur] == -1) break;
                cur = prevsmaller[cur];
            }
            else
            {
                if (foundsmaller == false)
                {
                    prevsmaller[i] = cur;
                    foundsmaller = true;
                }
                if (mx < up[cur])
                {
                    mx = up[cur];
                    //mxindex = cur;
                }
                if (prevhigher[cur] == -1) break;
                cur = prevhigher[cur];
            }
        }
        if (foundsmaller == false) prevsmaller[i] = -1;
        if (foundbigger == false) prevhigher[i] = -1;
        //prevsmaller[i] = mxindex;
        up[i] = mx + 1;
    }

//    for (int i=0; i<n; i++) cout<<i<<": "<<up[i]<<" "<<prevsmaller[i]<<" "<<prevhigher[i]<<endl;
//    cout<<endl;

    down[n-1] = 1;
    prevhigher[n-1] = -1;
    prevsmaller[n-1] = -1;

    for (int i=n-2; i>=0; i--)
    {
        int cur=i+1;
        int mx=0, mxindex=-1;
        prevhigher[i] = -1;
        bool foundbigger=false, foundsmaller=false;
        while (1)
        {
            if (nums[cur] >= nums[i])
            {
                if (foundbigger == false)
                {
                    prevhigher[i] = cur;
                    foundbigger = true;
                }
                if (prevsmaller[cur] == -1) break;
                cur = prevsmaller[cur];
            }
            else
            {
                if (foundsmaller == false)
                {
                    prevsmaller[i] = cur;
                    foundsmaller = true;
                }
                if (mx < down[cur])
                {
                    mx = down[cur];
                }
                if (prevhigher[cur] == -1) break;
                cur = prevhigher[cur];
            }
        }
        if (foundsmaller == false) prevsmaller[i] = -1;
        if (foundbigger == false) prevhigher[i] = -1;
        down[i] = mx + 1;
    }

//    for (int i=0; i<n; i++) cout<<i<<": "<<down[i]<<" "<<prevsmaller[i]<<" "<<prevhigher[i]<<endl;
//    cout<<endl;

    for (int i=0; i<n; i++)
    {
        int curbest = up[i] + down[i] - 1;
        if (ans < curbest) ans = curbest;
    }
    cout<<ans<<endl;
}
/**
11
3 1 5 8 9 11 7 3 5 4 9

16
2 7 3 5 9 8 10 7 11 4 8 7 2 5 6 3
*/
