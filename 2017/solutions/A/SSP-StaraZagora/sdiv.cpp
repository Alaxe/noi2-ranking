#include <iostream>
#include <string>
using namespace std;

bool nextComb (int *a, int n, int k)
{
    for(int i=k-1; i>=0; --i)
        if(a[i]<n-k+i)
        {
            ++a[i];
            for(++i; i<k; ++i) a[i]=a[i-1]+1;
            return true;
        }
    return false;
}

long long atoiMod (const char *a, long long mod)
{
    unsigned long long r=0;
    while (*a>='0' && *a<='9') r=(10ULL*r+*a++-'0')%mod;
    return r;
}

void init (int *a, size_t n)
{
    for(size_t i=0; i<n; ++i) a[i]=i;
}

void makeStr (string& num, const string& s, const int *a, int n)
{
    for(int i=0; i<n; ++i)
        num[i]=s[a[i]];
}

int main ()
{
    long long n,m,c=0;
    int a[16384];
    string s, num;
    cin >> s >> n >> m;
    num.reserve(s.size());
    for(size_t i=1; i<=s.size(); ++i)
    {
        num.push_back(0);
        init(a,i);
        do
        {
            makeStr(num,s,a,i);
            if(!atoiMod(num.c_str(),n)) ++c;
        }
        while(nextComb(a,s.size(),i));
    }
    cout << c%m << endl;
    return 0;
}
