#include <iostream>
#include <math.h>

using namespace std;

long long int M,N;
long long int result;
long long int h;
double res1, res2;

void For_Small()
{

    for(int a=sqrt(M)-2; a<N; a++)
    {
        h=a*(a+1);
        if(h>=M && h<=N) result++;
        if(h>N) break;
    }

    cout<<result<<endl;
}

int main()
{
    cin>>M>>N;

    if(M<1000000 && N-M<5000000)
    {
        For_Small();
        return 0;
    }

    if(M<1000000)
    {
        for(int a=1; a<M; a++)
        {
            h=a*(a+1);
            if(h>=1 && h<=M) res1++;
            if(h>M) break;
        }
    }
    else res1=sqrt(M);

    if(N<1000000)
    {
        for(int a=1; a<N; a++)
        {
            h=a*(a+1);
            if(h>=1 && h<=N) res2++;
            if(h>N) break;
        }
    }
    else res2=sqrt(N);
    cout<<(long long int)(res2-res1)<<endl;

    return 0;
}
