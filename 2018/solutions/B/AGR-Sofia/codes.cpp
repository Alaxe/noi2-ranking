#include<iostream>
#include<ctime>
#define abs(x) ((x) > 0? (x): -(x))
using namespace std;
const long long maxa = 1e18+10;
long long pow(int a,int b)
{
    long long ans = 1;
    for(int i = 0; i < b; i ++)
    {
        if(maxa / ans < a) return -1;
        ans *= a;
    }
    return ans;
}
char d[100];
string get(long long n, long long k, long long i, bool odd)
{
    if(k == 0)  return "";
    long long step = pow(n, k - 1);
    if(step == -1)
    {
        if(odd == 0) return d[0] + get(n, k - 1, i, 0);
        else {
            if((n - 1) % 2 == 0)    return d[n - 1] + get(n, k - 1, i, 0);
            if((n - 1) % 2 == 1)    return d[n - 1] + get(n, k - 1, i, 1);
        }
    }
    long long batch = i / step;
    if(odd == 0)
    {
        if((batch) % 2 == 0)    return d[batch] + get(n, k - 1, i % step, 0);
        if((batch) % 2 == 1)    return d[batch] + get(n, k - 1, i % step, 1);
        return d[0] + get(n, k - 1, i, 0);
    }
    else {
        if((n - 1 - batch) % 2 == 0)    return d[n - 1 - batch] + get(n, k - 1, i % step, 1);
        if((n - 1 - batch) % 2 == 1)    return d[n - 1 - batch] + get(n, k - 1, i % step, 0);
    }
}

long long dd(string s)
{
    int a = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        a += s[i] - '0';
    }
    return a;
}

int main()
{
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    for(int i = 0; i < n; i ++)
    {
        cin >> d[i];
    }
    int same = 0;
    for(; same < k && pow(n, same) != -1; same ++){}
    string ans1;
    int ans2 = 0;
    int last = 0;
    for(long long i = a; i <= b; i ++)
    {
        string s = get(n, same, i - 1, 0);
        if(ans1 < s)    ans1 = s;
        int j = dd(s);
        if(i != a && ans2 < abs(last - j))    ans2 = abs(last - j);
        last = j;
    }
    for(int i = 0; i < k - same; i ++)  cout << d[0];
    cout << ans1 << " " << ans2;
    //cout << endl << 1.0 * clock() / CLOCKS_PER_SEC;
}
/*
3 2 3 5
7 1 5
*/
/*
3 3 10 16
7 1 5
*/
/*
3 400 3 5
7 1 5
*/
