#include <iostream>

void print(int64_t a, char b)
{
    if(a % 1000 == 666)
    {
        a ++;
    }
    std::cout << a / 1000 << '.';
    std::cout << (a % 1000) / 100;
    std::cout << (a % 100) / 10;
    std::cout << a % 10;
    std::cout << b;
}

int main()
{

    std::cin.tie();
    std::ios_base::sync_with_stdio(false);

    int64_t s, k, a, b, c, d;
    std::cin >> k >> s >> a >> b >> c >> d;

    int64_t ost = s % (d * 4), sec = ((s + (d * 4) - 1) / (d * 4)) % 4, aa = 0, ab = 0, ac = 0, ad = 0;

    if(ost == 0)
    {
        std::cout << d << ".000 " << d << ".000 " << d << ".000 " << d << ".000\n";
        return 0;
    }

    a *= 1000;
    b *= 1000;
    c *= 1000;
    d *= 1000;
    ost *= 1000;

    //std::cout << ost << ' ' << sec;

    if(sec == 1)
    {
        if(ost - a > 0)
        {
            ost -= a;
            aa += a;
        }else
        {
            aa += ost;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ab += a;
        }else
        {
            ab += ost;
            ost = 0;
        }

        if(ost - (2 * (c - a)) > 0)
        {
            ost -= (2 * (c - a));
            ab += (c - a);
            aa += (c - a);
        }else
        {
            ab += ost / 2;
            aa += ost / 2;
            ost = 0;
        }

        if(ost - b > 0)
        {
            ost -= b;
            ac += b;
        }else
        {
            ac += ost;
            ost = 0;
        }

        if(ost - b > 0)
        {
            ost -= b;
            ad += b;
        }else
        {
            ad += ost;
            ost = 0;
        }

        if(ost - (2 * (c - b)) > 0)
        {
            ost -= (2 * (c - b));
            ac += (c - b);
            ad += (c - b);
        }else
        {
            ac += ost / 2;
            ad += ost / 2;
            ost = 0;
        }

        if(ost - (4 * (d - c)) > 0)
        {
            ost -= (4 * (d - c));
            aa += (d - c);
            ab += (d - c);
            ac += (d - c);
            ad += (d - c);
        }else
        {
            aa += ost / 4;
            ab += ost / 4;
            ac += ost / 4;
            ad += ost / 4;
            ost = 0;
        }
    }
    if(sec == 2)
    {

        if(ost - b > 0)
        {
            ost -= b;
            aa += b;
        }else
        {
            aa += ost;
            ost = 0;
        }


        if(ost - a > 0)
        {
            ost -= a;
            ab += a;
        }else
        {
            ab += ost;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ac += a;
        }else
        {
            ac += ost;
            ost = 0;
        }

        if(ost - (2 * (b - a)) > 0)
        {
            ost -= (2 * (b - a));
            ab += (b - a);
            ac += (b - a);
        }else
        {
            ab += ost / 2;
            ac += ost / 2;
            ost = 0;
        }

        if(ost - (3 * (c - b)) > 0)
        {
            ost -= (3 * (c - b));
            aa += (c - b);
            ab += (c - b);
            ac += (c - b);
        }else
        {
            aa += ost / 3;
            ab += ost / 3;
            ac += ost / 3;
            ost = 0;
        }

        if(ost - c > 0)
        {
            ost -= c;
            ad += c;
        }else
        {
            ad += ost;
            ost = 0;
        }

        if(ost - (4 * (d - c)) > 0)
        {
            ost -= (4 * (d - c));
            aa += (d - c);
            ab += (d - c);
            ac += (d - c);
            ad += (d - c);
        }else
        {
            aa += ost / 4;
            ab += ost / 4;
            ac += ost / 4;
            ad += ost / 4;
            ost = 0;
        }
    }
    if(sec == 3)
    {
        if(ost - b > 0)
        {
            ost -= b;
            aa += b;
        }else
        {
            aa += ost;
            ost = 0;
        }

        if(ost - b > 0)
        {
            ost -= b;
            ab += b;
        }else
        {
            ab += ost;
            ost = 0;
        }

        if(ost - (2 * (c - b)) > 0)
        {
            ost -= (2 * (c - b));
            aa += (c - b);
            ab += (c - b);
        }else
        {
            aa += ost / 2;
            ab += ost / 2;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ac += a;
        }else
        {
            ac += ost;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ad += a;
        }else
        {
            ad += ost;
            ost = 0;
        }

        if(ost - (2 * (c - a)) > 0)
        {
            ost -= (2 * (c - a));
            ac += (c - a);
            ad += (c - a);
        }else
        {
            ac += ost / 2;
            ad += ost / 2;
            ost = 0;
        }

        if(ost - (4 * (d - c)) > 0)
        {
            ost -= (4 * (d - c));
            aa += (d - c);
            ab += (d - c);
            ac += (d - c);
            ad += (d - c);
        }else
        {
            aa += ost / 4;
            ab += ost / 4;
            ac += ost / 4;
            ad += ost / 4;
            ost = 0;
        }
    }
    if(sec == 0)
    {
        if(ost - c > 0)
        {
            ost -= c;
            aa += c;
        }else
        {
            aa += ost;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ab += a;
        }else
        {
            ab += ost;
            ost = 0;
        }

        if(ost - a > 0)
        {
            ost -= a;
            ac += a;
        }else
        {
            ac += ost;
            ost = 0;
        }

        if(ost - (2 * (b - a)) > 0)
        {
            ost -= (2 * (b - a));
            ab += (b - a);
            ac += (b - a);
        }else
        {
            ab += ost / 2;
            ac += ost / 2;
            ost = 0;
        }

        if(ost - b > 0)
        {
            ost -= b;
            ad += b;
        }else
        {
            ad += ost;
            ost = 0;
        }

        if(ost - (3 * (c - b)) > 0)
        {
            ost -= (3 * (c - b));
            ab += (c - b);
            ac += (c - b);
            ad += (c - b);
        }else
        {
            ab += ost / 3;
            ac += ost / 3;
            ad += ost / 3;
            ost = 0;
        }

        if(ost - (4 * (d - c)) > 0)
        {
            ost -= (4 * (d - c));
            aa += (d - c);
            ab += (d - c);
            ac += (d - c);
            ad += (d - c);
        }else
        {
            aa += ost / 4;
            ab += ost / 4;
            ac += ost / 4;
            ad += ost / 4;
            ost = 0;
        }
    }

    print(aa, ' ');
    print(ab, ' ');
    print(ac, ' ');
    print(ad, '\n');

    return 0;
}
/**
4 3 1 2 3 5
*/
