#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::string> Generate(std::vector<std::string> prev, std::vector<char> digits)
{
    std::vector<std::string> next;
    for(int i = 0; i < digits.size(); i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < prev.size(); j++)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        else
        {
            for(int j = prev.size() - 1; j >= 0; j--)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }

    return next;
}

int dSum(std::string in)
{
    int sum = 0;
    for(int i = 0; i < in.size(); i++)
    {
        sum += (int)in[i] - 48;
    }
    return sum;
}

int main()
{
    int n, k, a, b;
    std::cin>>n>>k>>a>>b;
    std::vector<char> digits;
    std::vector<std::string> prev;
    for(int i = 0; i < n; i++)
    {
        std::string h;
        std::cin >> h;
        digits.push_back(h[0]);
        prev.push_back(h);
    }

    for(int i = 1; i < k; i++)
    {
        prev = Generate(prev, digits);
    }

    std::string m = prev[b - 1];

    int ma = 0;

    for(int i = a - 1; i < b - 2; i++)
    {
        int s = std::abs(dSum(prev[i]) - dSum(prev[i + 1]));
        if(ma < s)
        {
            ma = s;
        }
        if(m < prev[i])
        {
            m = prev[i];
        }
    }

    std::cout<<m<<std::endl;
    std::cout<<ma<<std::endl;
    return 0;
}
