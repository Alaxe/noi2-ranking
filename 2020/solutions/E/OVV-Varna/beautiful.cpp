#include<iostream>
using namespace std;
int main( )
{
    long long n, i, br = 0, p, k;
    cin >> n;
    for(i=1;i<=n;i++)
    {
       if(i < 10) br++;
       if(i < 100 && i % 11 == 0) br++;
       if(i < 1000 && i % 111 == 0) br++;
       if(i < 10000 && i % 1111 == 0) br++;
       if(i < 100000 && i % 11111 == 0) br++;
       if(i < 1000000 && i % 111111 == 0) br++;
       if(i < 10000000 && i % 1111111 == 0) br++;
       if(i < 100000000 && i % 11111111 == 0) br++;
       if(i < 1000000000 && i % 111111111 == 0) br++;
       if(i < 10000000000 && i % 1111111111 == 0) br++;
       if(i < 100000000000 && i % 11111111111 == 0) br++;
       if(i < 1000000000000 && i % 111111111111 == 0) br++;
       if(i < 10000000000000 && i % 1111111111111 == 0) br++;
       if(i < 100000000000000 && i % 11111111111111 == 0) br++;
       if(i < 1000000000000000 && i % 111111111111111 == 0) br++;
       if(i < 10000000000000000 && i % 1111111111111111 == 0) br++;
       if(i < 100000000000000000 && i % 11111111111111111 == 0) br++;
       if(i < 1000000000000000000 && i % 111111111111111111 == 0) br++;
    }
    cout << br << endl;
}
