#include <iostream>
#include <cmath>
using namespace std;

long long m=3ll, n=10ll;

void inp()
{
    cin>>m>>n;
}

bool hasfp(double a, long long b)
{
    if (a-(double(b)) == 0) return false;
    return true; 
}

long long sol()
{
    long long f = sqrt(m);
    long long res = f*(f+1);
    long long c = 0ll;
    while(res<=n) 
    {
        cout<<f<<endl;
        f++;
        res = f*(f+1);
        c++;
    }
    cout<<c<<endl;
    return c;
}

long long sol2()
{
    long long first = (1.0+sqrt(1.0+4*m))/2.0;
    if (!hasfp((1.0+sqrt(1.0+4*m))/2.0, first)) first--;
    long long last = (1.0+sqrt(1.0+4*n))/2.0;
    //cout<<(1.0+sqrt(1.0+4*m))/2.0<<' '<<(1.0+sqrt(1.0+4*n))/2.0<<endl;
    cout<<last-first<<endl;
    return last-first;
}

int main()
{
    inp();
    
    sol2();
    return 0;
}