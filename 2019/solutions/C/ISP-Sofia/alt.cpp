#include <iostream>

int m, k, n;

uint64_t ans = 0, anss[60][60];

void rec(int val, int pos)
{
    if(pos == n)
    {
        ++ ans;
        return;
    }
    if(val + k < m)
    {
        if(anss[val + k][pos + 1] == 0 || anss[m - val - k][pos + 1] == 0)
        {
            uint64_t ans1 = ans;
            rec(val + k, pos + 1);
            anss[val + k][pos + 1] = anss[m - val - k][pos + 1] = ans - ans1;
        }else
        {
            ans += anss[val + k][pos + 1];
        }
    }
    if(val - k > 0)
    {
        if(anss[val - k][pos + 1] == 0 || anss[m - val + k][pos + 1] == 0)
        {
            uint64_t ans1 = ans;
            rec(val - k, pos + 1);
            anss[val - k][pos + 1] = anss[m - val + k][pos + 1] = ans - ans1;
        }else
        {
            ans += anss[val - k][pos + 1];
        }
    }
}

int main()
{

    std::cin >> k >> m >> n;

    for(int i = 0; i < 60; ++ i)
    {
        for(int j = 0; j < 60; ++ j)
        {
            anss[i][j] = 0;
        }
    }

    for(int i = 1; i < m; ++ i)
    {
        rec(i, 1);
    }

    std::cout << ans << '\n';

    return 0;
}
///13541080453928136336
///4957951410356825912
///14253203637969124780


///16985217558122985060
///1232203683468231768
///1637577318643882164






