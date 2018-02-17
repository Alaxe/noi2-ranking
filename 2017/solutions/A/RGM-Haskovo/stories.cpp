#include<iostream>
#include<queue>
using namespace std;
struct ralka
{
    long long p,d;
};

priority_queue<ralka> pq;
bool operator < (const ralka A, const ralka B)
{
    return A.p<B.p;
}

ralka t;
unsigned long long sum=0;
int main ()
{
    long long k,n;
    cin>>k>>n;

    long long f,m,a,MOD;
    cin>>f>>m>>a>>MOD;

    t.p=f;
    t.d=1+n;
    pq.push(t);
    sum=sum+f;

    for (int i=2; i<=k; i++)
    {
        f=(f*m+a)%MOD;
        t.p=f;
        t.d=i+n;
        pq.push(t);

        while (pq.top().d<=i)
        {
            pq.pop();
        }
        sum=sum+pq.top().p;
    }
    cout<<sum<<endl;

    return 0;
}
