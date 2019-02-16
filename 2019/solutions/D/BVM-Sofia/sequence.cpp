#include <iostream>
using namespace std;
int main ()
{
    long long chislo = 1;
    long long n, k;
    cin >> n >> k;
    for(long long j = 1 ; j < k ; ++j)
    {
        if(j % 2 == 1)++chislo;
        else chislo += j;
    }
    if(n == 1){
        cout << chislo << '\n';
        return 0;
    }
    long long sb = ((k+1+int(k%2==0))/2)*2;
    for(int i = 2 ; i < n ; ++i)
    {
        chislo += sb;
        sb += 2;
    }
    cout << chislo + sb << '\n';
    return 0;
}
