#include<iostream>
using namespace std;
bool check(int, long, long[]);
int main()
{
    int n;
    cin >> n;
    int nums[n+1];
    long after[100000];
    long count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int j = 0;
    int sum = NULL;
    int lastSum = 0;
    int sumFromNumber = 0;
    int sumFromSpecificNumbers = 0;
    while(j < n)
    {
        lastSum = nums[j];
        for(int i = 0; i < n; i++)
        {
            sumFromSpecificNumbers = nums[j];
            sumFromNumber = nums[j];
            if(i != j)
            {
                lastSum += nums[i];
            }
            if(i != j)
            {
                sum = nums[j] + nums[i];
            }
            if(i != j)
            {
                for(int g = i; g < n; g++)
                {
                    //cout << "sumFromSpecificNumbers: " << sumFromSpecificNumbers << endl;
                    if(g != j)
                    {
                      sumFromSpecificNumbers += nums[g];
                    }

                }
            }
            else
            {
                for(int g = i+1; g < n; g++)
                {
                    //cout << "sumFromSpecificNumbers: " << sumFromSpecificNumbers << endl;
                    if(g != j)
                    {
                      sumFromSpecificNumbers += nums[g];
                    }
                }
            }
            if(i != j)
            {
                for(int i = j+1; i < n; i++)
                {
                    sumFromNumber += nums[i];
                }
            }
            if(check(sumFromNumber,count,after))
            {
                after[count] = sumFromNumber;
                count++;
                //cout << "sumFromNumber: " << sumFromNumber << " " << j << endl;
            }
            if(check(sum,count,after) && sum != NULL)
            {
                after[count] = sum;
                count++;
                //cout << "sum: " << sum << endl;
            }
            if(check(sumFromSpecificNumbers,count,after) && sumFromSpecificNumbers != NULL)
            {
                after[count] = sumFromSpecificNumbers;
                count++;
                //cout << "sumsumFromSpecificNumbers: " << sumFromSpecificNumbers << endl;
            }
            if(check(nums[j],count,after))
            {
                after[count] = nums[j];
                count++;
                //cout << "nums: " << nums[j] << endl;
            }
            if(check(lastSum,count,after))
            {
                after[count] = lastSum;
                count++;
                //cout << "lastSum: " << lastSum << endl;
            }
        }
        j++;
    }
    cout << count;
    return 0;
}
//Checks if the number is alreay in the array
bool check(int a, long count, long after[])
{
    if(count == 0)
    {
        return true;
    }
    for(int i = 0; i < count; i++)
    {
        if(a == after[i])
        {
            return false;
        }
    }
    return true;
}
