#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

using ull = unsigned long long;
using ll = long long;
using ui = unsigned int;

struct number
{
    vector < ui > digits;
    vector < ll > counts;
    number (ui n)
    {
        digits.reserve (n);
        counts = vector <ll> (n, 0);
    }
    void push_back (ui digit)
    {
        digits.push_back(digit);
        counts [digit] ++;
    }
    /*
    ull diff (const number& n, const vector < char >& digits)
    {
        ////cout << "diff" << endl;
        ull ans = 0;
        for (int i = 0 ; i < counts.size () ; i ++)
        {
            ans += (n.counts [i] - this->counts [i]) * (digits [i] - '0');
        }
        ////cout << "end diff " << abs (ans) << endl;
        return abs (ans);
    }

*/
/*
    number& operator = (const pair < number, vector < int > >& b)
    {
        counts = b.first.counts;
        digits = b.first.digits;
        return *this;
    }*/

};

void print (const number& a)
{
    return;
    for (auto& x : a.digits)
        cout << (char)(x + 'a');
    cout << endl;
}

number gen (ui n, ui k, ull index)
{
    //ui n = digits.size ();
    ull max_power = 1, power = 0;
    for ( ; max_power * n <= index ; power ++)
        max_power *= n;
    number ans (n);
    for (int i = 0 ; i < k - 1 - power ; i ++)
        ans.push_back (0);
    while (ans.digits.size () < k)
    {
        ans.push_back(index / max_power);
        if ((index / max_power) % 2 == 0)
        {
            index -= max_power * (index / max_power);
        }
        else
        {
            index -= max_power * (index / max_power);
            index = max_power - 1 - index;
        }
        max_power /= n;
    }
    return move (ans);
}

vector < int > next (number& a, ui n)
{
    //cout << "next: ";
    print (a);
    vector < int > counts (a.counts.size (), 0);
///aac
    for (int set_digits = 0 ; set_digits < a.digits.size () ; set_digits ++)
    {
        int even_odd_last = 0; ///  0
        for (int i = 0 ; i < a.digits.size () - 1 - set_digits ; i ++)
            even_odd_last = (even_odd_last + (a.digits [i] % 2)) % 2;

        ////cout << "even_odd="<<even_odd << " " << a.digits [a.digits.size () - 1 - set_digits - 1] << " " << a.digits [a.digits.size () - 1 - set_digits] << endl;

        if (even_odd_last == 0)  /// ...(n-1) => ...(+1)(n-1)
        {
            ////cout << "even_odd=" << even_odd << " n-1=" << N - 1 << " " << a.digits [a.digits.size () - 1 - n] << endl;
            if (a.digits [a.digits.size () - 1 - set_digits] == n - 1)
            {
                ////cout << "even_odd = 0 last_digit=n-1=" << a.digits [a.digits.size () - 1 - n] << endl;
                int ind_change = a.digits.size () - 1 - set_digits;
                int even_odd = even_odd_last; /// 0

                for ( ; a.digits [ind_change] == n - 1 ; )
                {
                    ind_change --;
                    even_odd = (a.digits [ind_change] % 2 == 1) ? 1 - even_odd : even_odd;
                }

                counts [a.digits [ind_change]] --;
                a.counts [a.digits [ind_change]] --;
                if (even_odd == 0)
                    a.digits [ind_change] ++;
                else
                    a.digits [ind_change] --;
                a.counts [a.digits [ind_change]] ++;
                counts [a.digits [ind_change]] ++;
                return move (counts);
            }
            else
            {
                int ind_change = a.digits.size () - 1 - set_digits;

                counts [a.digits [ind_change]] --;
                a.counts [a.digits [ind_change]] --;
                a.digits [ind_change] ++;
                a.counts [a.digits [ind_change]] ++;
                counts [a.digits [ind_change]] ++;
                return move (counts);
            }
        }
        else if (even_odd_last == 1) /// ...0 => ...(-1)0
        {
            if (a.digits [a.digits.size () - 1 - set_digits] == 0)
            {
                int ind_change = a.digits.size () - 1 - set_digits;
                int even_odd = even_odd_last;

                for ( ; a.digits [ind_change] == 0 ; )
                {
                    ind_change --;
                    even_odd = (a.digits [ind_change] % 2 == 1) ? 1 - even_odd : even_odd;
                }
                counts [a.digits [ind_change]] --;
                a.counts [a.digits [ind_change]] --;
                if (even_odd == 0)
                    a.digits [ind_change] ++;
                else
                    a.digits [ind_change] --;
                a.counts [a.digits [ind_change]] ++;
                counts [a.digits [ind_change]] ++;
                return move (counts);
            }
            else
            {
                int ind_change = a.digits.size () - 1 - set_digits;

                counts [a.digits [ind_change]] --;
                a.counts [a.digits [ind_change]] --;
                a.digits [ind_change] --;
                a.counts [a.digits [ind_change]] ++;
                counts [a.digits [ind_change]] ++;
                return move (counts);
            }
        }
    }
}

void print (const number& a, const number& b)
{
    return;
    cout << "\t\t\t";
    for (auto& x : a.digits)
        cout << (char)(x + 'a');
    cout << " ";
    for (auto& x : b.digits)
        cout << (char)(x + 'a');
    cout << endl;
}

void print (const number& a, const vector <char>& digits)
{
    for (auto& x : a.digits)
        cout << digits [x];
}

ull calc (const vector < int >& counts, const vector < char >& digits)
{
    ll ans = 0;
    for (int i = 0 ; i < counts.size () ; i ++)
    {
        ////cout << counts [i] << "*" << (digits [i] - '0') << endl;
        ans += counts [i] * (digits [i] - '0');
    }
    return abs (ans);
}

vector < char > digits;

bool compare (ui n, ui k, ull index, const number& b)
{
    ull max_power = 1, power = 0;
    for ( ; max_power * n <= index ; power ++)
        max_power *= n;
    size_t size = 0;
    for (int i = 0 ; i < k - 1 - power ; i ++)
    {
        size ++;
        if (b.digits [i] != 0)
            return digits [0] < digits [b.digits [i]];
    }
    while (size < k)
    {
        if (b.digits [size] != index / max_power)
            return digits [index / max_power] < digits [b.digits [size]];
        size ++;
        if ((index / max_power) % 2 == 0)
        {
            index -= max_power * (index / max_power);
        }
        else
        {
            index -= max_power * (index / max_power);
            index = max_power - 1 - index;
        }
        max_power /= n;
    }
    return false;
}

int main ()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*
    for (int i = 0 ; i < 20 ; i ++)
        print (gen (4, 4, i));
    //cout << "------------------" << endl;
    auto XX = gen (3, 3, 0);
    print (gen (3, 3, 0));
    for (int i = 1 ; i < 20 ; i ++)
        print (gen (3, 3, i), XX = next (XX, 3));
*/
    unsigned int n, k;
    unsigned long long a, b;
    cin >> n >> k >> a >> b;
    a --;
    b --;
    for (int i = 0 ; i < n ; i ++)
    {
        char a;
        cin >> a;
        digits.push_back (a);
    }
    ////cout << "start" << endl;
    auto MAX = a;
    ////cout << "start" << endl;
    auto prev = gen (n, k, a);
    ////cout << "start" << endl;
    ull max_diff = 0;
    //cout << "start" << endl;
    for (ull i = a + 1 ; i <= b ; i ++)
    {
        auto _ = next(prev, n);
        //cout << "generated next - " << i << endl;
        auto diff = calc (_, digits);
        //cout << diff << endl;
        max_diff = max (max_diff, diff);
        if (compare (n, k, MAX, prev))
            MAX = i;
    }
    print (gen (n, k, MAX), digits);
    cout << " " << max_diff << endl;
    return 0;
}

