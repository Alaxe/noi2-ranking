#include <iostream>
#include <cmath>
using namespace std;
unsigned long long countFrom1(long double n)
{if(n<2) return 0;
 long double t=floorl(sqrtl(n));
 if (t*(t+1.0l)>n) t--;
 return (unsigned long long)t;
}
unsigned long long count(long double from,long double to)
{return countFrom1(to)-countFrom1(from-1.0l);
}
int main()
{   long double m,n;
    cin>>m>>n;
    cout<<count(m,n)<<endl;
    return 0;
}
