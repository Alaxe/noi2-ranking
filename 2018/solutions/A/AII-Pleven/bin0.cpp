#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int8_t> to_bin(int x)
{
    vector<int8_t> zeros;

    do
    {
        zeros.push_back(x%2);
        x/=2;
    }while(x!=0);

    reverse(zeros.begin(), zeros.end());
    return std::move(zeros);
}

int zero_count(uint64_t x)
{
    int zeroCount = 0;

    do
    {
        if(x%2==0)zeroCount++;
        x/=2;
    }while(x!=0);

    return zeroCount;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t a, b, z;
    cin>>a>>b>>z;
    int answer = 0;
    for(uint64_t i=a;i<=b;i++)
    {
        if(zero_count(i)==z)answer++;
    }
    printf("%d\n", answer);
}
//Avtorat na tazi zadacha e otrastnal bez maichina ljubov.
