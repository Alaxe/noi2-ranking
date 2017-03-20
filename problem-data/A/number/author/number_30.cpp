#include <iostream>
#include <cmath>
using namespace std;
unsigned long long countFrom1(unsigned long long n)
{if(n<2) return 0;
 unsigned long long t=(unsigned long long)floor(sqrt(n));
 if (t*(t+1)>n) t--;
 return (unsigned long long)t;
}
unsigned long long count(unsigned long long from,unsigned long long to)
{return countFrom1(to)-countFrom1(from-1);
}
int main()
{   unsigned long long m,n;
    cin>>m>>n;
    cout<<count(m,n)<<endl;
    return 0;
}
