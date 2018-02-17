#include <iostream>

using namespace std;

int main()
{
    unsigned long n, first, mul, add, mod;
    int k = 0;
    unsigned long long sumOfToldStories = 0;
    cin >> n >> k;
    cin >> first >> mul >> add >> mod;

    unsigned long stories[k];
    stories[0] = first;
    sumOfToldStories += stories[0];

    unsigned long funniestRating = 0;
    for(int i = 1; i < n; i++)
    {
        int index = 0;
        if(i < k)
        {
            index = i % k;
            stories[index] = (stories[index - 1] * mul + add) % mod;
        }
        else
        {
            for(int m = 1; m < k; m++)
            {
                stories[m - 1] = stories[m];
            }

            stories[k - 1] = (stories[k - 2] * mul + add) % mod;
            index = k - 1;
        }

        funniestRating = stories[index];
        for(int j = index - 1; j >= ((index - k) + 1); j--)
        {
            if(j >= 0)
            {
                if(stories[j] > funniestRating)
                {
                    funniestRating = stories[j];
                }
            }
        }

        sumOfToldStories += funniestRating;
    }

    cout << sumOfToldStories << endl;

    return 0;
}
