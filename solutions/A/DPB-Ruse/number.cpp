#include <iostream.h>
#include <math.h>

int main()
{
    long long m, n;
    long long i, k;
    long long a, b;
    
    cin >> m >> n;

    a = int(sqrt(n));
    if(a*(a+1)>n)
        a--;
        
    b = int(sqrt(m));
    if(b*(b+1)>=m)
        b--;
    
    cout << a-b << endl;
}
