#include<bits/stdc++.h>
using namespace std;
const int MAX_N=782;
bool check_prime(int x)
{
    if(x==2)
        return 1;
    int limit=sqrt(x)+1;
    for(int k=2; k<=limit; k++)
        if(x%k==0)
            return 0;
    return 1;
}
void deliteli(int x)
{
    for(int i=1; i<=x; i++)
        if(x%i==0)
            printf("%d ", i);
    printf("\n");
}

void brute()
{
    for(int i=3; i<=MAX_N; i++)
        if(check_prime(i))
        {
            deliteli(i*i);
            if(check_prime(i*i))
                printf("%d %d\n", i, i*i);
        }
}
int main()
{
    //brute();
    printf("0\n");
    return 0;
}
