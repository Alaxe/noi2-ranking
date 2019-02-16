#include<iostream>

int a, div[50];

uint64_t pow(uint64_t a, uint64_t b)
{
    //std::cout << "asdf";
    if(b == 0)
    {
        return 1;
    }

    int r = pow(a, b / 2);
    r *= r;

    if(b % 2 == 1)
    {
        r *= a;
    }

    return r;
}

int main()
{

    std::cin.tie();
    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    for(int i = 0; i < n; ++ i)
    {
        std::cin >> a;

        for(int j = 2; j < 43; ++ j)
        {
            int curr = 0;

            while(a % j == 0)
            {
                ++ curr;
                a /= j;
            }

            div[j] = std::max(((curr + k - 1) / k), div[j]);
        }
    }

    uint64_t c = 1;

    for(uint64_t i = 2; i < 43; ++ i)
    {
        //std::cout << i << ' ' << div[i] << '\n';
        //c *= pow(i, div[i]);
        while(div[i] --)
        {
            c *= i;
        }
    }

    std::cout << c << '\n';

    return 0;
}
/*
42 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
1787852280
*/

//8,543347399844057e+18
