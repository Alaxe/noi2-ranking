#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
bool contains(T* begin, T* end, const T& val)
{
    for (T* it = begin; it < end; it++)
    {
        if (*it == val)
        {
            return true;
        }
    }
    return false;
}

static int n = 0;
static unsigned short xs[1000];

struct Prog
{
    unsigned short* vals;
    int size;

    Prog()
        : vals()
        , size()
    {
    }

    Prog(unsigned short* vals, int size)
        : vals(vals)
        , size(size)
    {
    }
};

bool operator==(const Prog& x, const Prog& y)
{
    if (x.size != y.size)
    {
        return false;
    }

    for (int i = 0; i < x.size; ++i)
    {
        if (x.vals[i] != y.vals[i])
        {
            return false;
        }
    }

    return true;
}

bool operator!=(const Prog& x, const Prog& y)
{
    return !(x == y);
}

static int prog_count = 0;

template <class T>
bool is_valid_prog(T* begin, T* end)
{
    T front = *begin++;
    if (begin == end)
    {
        return false;
    }
    T step = front - *begin;
    for (; begin != end; ++begin)
    {
        if (front - *begin != step)
        {
            return false;
        }
    }
    return true;
}

void sat_progs()
{
    if (n <= 2)
    {
        prog_count = 1;
        return;
    }

    static unsigned char selector[1000];
    for (int k = n; k >= 2; --k)
    {
        std::fill(selector, selector + n - k, 0);
        std::fill(selector + n - k, selector + n, 1);
        do
        {
            bool success = true;
            int val_count = 0;
            unsigned short* vals = new unsigned short[k];

            for (int sel_i = 1; sel_i < n; ++sel_i)
            {
                if (selector[sel_i] != 0)
                {
                    vals[val_count++] = xs[sel_i];
                    if (val_count > 2)
                    {
                        if (vals[val_count - 1] - vals[val_count - 2] != vals[1] - vals[0])
                        {
                            success = false;
                            break;
                        }
                    }
                }
            }

            delete[] vals;

            if (success)
            {
                prog_count++;
            }
        } while (std::next_permutation(selector, selector + n));
    }
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> xs[i];
    }

    sat_progs();

    std::cout << prog_count << std::endl;

    return 0;
}
