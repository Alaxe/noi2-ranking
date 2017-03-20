#include <iostream>

inline long long area(long long a, long long b)
{
    return a * b;
}

inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    long long max_value;
    std::cin >> max_value;

    long long length;
    std::cin >> length;

    int n;
    std::cin >> n;

    long long dirty_area = 0;

    long long prev_pos = 0;
    long long back_mov = 0;
    for (int i = 0; i < n; ++i)
    {
        long long value, pos;
        std::cin >> value >> pos;

        long long dist = pos - prev_pos;
        long long dirty_value = max_value - value;
        if (dist > 0)
        {
            if (dist - back_mov >= 0)
            {
                long long area_chunk = area(dist - back_mov, dirty_value);
                dirty_area += area_chunk;
            }
            back_mov = max(back_mov - dist, 0);
        }
        else if (dist < 0)
        {
            back_mov -= dist;
        }

        prev_pos = pos;
    }

    std::cout << dirty_area << std::endl;
}
