#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> memory;
vector<long long> transformed;

void print(vector<long long> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    long long ans = 0;
    int n, k;
    cin >> n >> k;
    long long first, mul, add, mod;
    cin >> first >> mul >> add >> mod;

    long long a = first;
    int i = 0;
    do
    {
        memory.push_back(a);
        i++;
        a = (a * mul + add) % mod;
    } while (i < n);
    for (long long i = 0; i < memory.size(); i++)
    {
        transformed.push_back(memory[i]);
    }

    for (long long j  = 0; j < k; j++)
    {
        for (long long i = 0; i < memory.size(); i++)
        {
            int checkPos;
            if (i + j < memory.size())
            {
                checkPos = i + j;
            }
            else
            {
                //checkPos = i + j - memory.size();
                break;
            }

            if  (memory[i] > transformed[checkPos])
            {
                transformed[checkPos] = memory[i];
            }
        }
    }
    for (long long i = 0; i < n; i++)
    {
        ans += transformed[i];
    }
    cout << ans << endl;



    return 0;
}
