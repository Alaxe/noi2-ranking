#include<iostream>
using namespace std;
long long average(int l, int r) { return (l+r)/2; }
int main()
{
    long long M, N;
    cin>>M>>N;
    if(M == 1 && N == 1) { cout<<0; return 0; }
    if(M == 1) M = 2;
    long long left = 1, right = M, x = right;
    while(!((x*(x-1) >= M && (x-1)*(x-2) <= M)|| x*(x-1) == M))
    {
        long long avg = average(left, right);
        if((avg-1)*avg == M) { x = avg; break; }
        if((avg-1)*avg < M) left = avg;
        if((avg-1)*avg > M) right = avg;
        x = avg;
    }
    long long a = x;
    short sign = -1;
    left = 1, right = N, x = right;
    while(!((x*(x-1) >= N && (x-1)*(x-2) <= N)|| x*(x-1) == N))
    {
        long long avg = average(left, right);
        if((avg-1)*avg == N) { x = avg; sign = 0; break; }
        if((avg-1)*avg < N) left = avg;
        if((avg-1)*avg > N) right = avg;
        x = avg;
    }
    long long b = x + sign;
    cout<<b-a+1;
}
