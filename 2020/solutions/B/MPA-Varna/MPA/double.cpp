#include<iostream>
#include<algorithm>
using namespace std;
int numbers[200];
bool used[200];
int minn = 0;
int w1max = 0;
int w2max = 0;
int n, w1, w2;

int maxWeight(int startIndex, int totalWeight, int currentWeight)
{
    used[startIndex] = true;

    for(int j = startIndex + 1; j < n; j++)
    {
        if(totalWeight >= numbers[j])
        {
            if(used[j] == false) return maxWeight(j, totalWeight - numbers[j], currentWeight + numbers[j]);
        }

    }
    return currentWeight;
}

int main()
{
    cin>>n>>w1>>w2;
    for(int i = 0 ; i < n; ++i)
    {
        cin>>numbers[i];
    }
    sort(numbers, numbers + n);
    reverse(numbers, numbers + n);
    minn = numbers[n - 1];
    for(int i = 0; i < n; ++i)
    {

        int maxWeight1 = -13;
        int maxWeight2 = -13;
        if(numbers[i] <= w1 && used[i] == false)
        {
            maxWeight1 = maxWeight(i, w1 - numbers[i], numbers[i]);
            if(maxWeight1 > w1max) w1max = maxWeight1;
        }
        if(numbers[i] <= w2 && used[i] == false)
        {
            maxWeight2 = maxWeight(i, w2 - numbers[i], numbers[i]);
            if(maxWeight2 > w2max) w2max = maxWeight2;
        }
    }

    cout<<w1max + w2max<<endl;
    return 0;
}
