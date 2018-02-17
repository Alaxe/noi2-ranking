#include<iostream>
#include<cmath>
using namespace std;

long long int M, N;
bool isGood(long long a)
{
 a=4*a+1;
 long long t=(long long)floor(sqrt(a)+0.2);
 return t*t==a;
}
int main()
{
    cin >> M >> N;
    long long int br=0;
    for (long long i=M;i<=N;i++)
        if (isGood(i)) br++;
    cout << br << endl;
}
