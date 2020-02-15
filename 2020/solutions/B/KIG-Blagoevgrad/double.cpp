/*

*/
#include <bits/stdc++.h>
using namespace std;
int n, w1, w2;

bool ways(vector<int> nums, int w)
{
    int t[n+1][w+1];
    for(int i = 1; i < n+1; i++)
    {
        t[i][0] = 1;
    }
    for(int i = 1; i < w+1; i++)
    {
        t[0][i] = 0;
    }
    t[0][0] = 1;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < w+1; j++)
        {
            t[i][j] = 0;
            if(j - nums[i - 1] >= 0)
            {
                t[i][j] += t[i - 1][j - nums[i - 1]];
            }
            t[i][j] += t[i - 1][j];
        }
    }
    /*for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < w+1; j++)
        {
            cout <<t[i][j] <<" ";
        }
        cout <<endl;
    }*/
    return t[n][w] != 0;
}
int main()
{
cin >>n >>w1 >>w2;
if(w1 > w2)
{
    int x = w1;
    w1 = w2;
    w2 = x;
}
vector<int> nums(n);
int min = INT_MAX;
for(int i = 0; i < n; i++)
{
    cin >>nums[i];
    min = (min > nums[i] ? nums[i] : min);
}
sort(nums.begin(), nums.end());
int sum = w1+w2;
for(int i = sum; i > 1; i--)
{
    bool pos = ways(nums, i);
    if(pos)
    {
        cout <<"i "<<i <<endl;
        for(int j = w1; j >= 0; j--)
        {
            if(ways(nums, j) && i - j <= w2 && ways(nums, i - j))
            {
                cout <<"f = " <<j <<" s = " <<i - j <<" sum = " <<i <<endl;
                return 0;
            }
        }
    }
}
return 0;
}

