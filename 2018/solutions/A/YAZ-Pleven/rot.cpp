#include<iostream>
using namespace std;

int cntNumbers(int n)
{
    int rt=0;
    while(n!=0)
    {
        n/=10;
        rt++;
    }
    return rt;
}

long long pow10(int a)
{
    long long rt=1;
    for(int i=1;i<=a;i++)
        rt*=10;
    return rt;
}

bool check(int a,int b,int p)
{
    int c=(a%p)*10+(a/p);
    return c==b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b;
    cin>>b;
    for(int i=1;i<=4;i++)
    {
        bool flag=false;
        long long a;
        cin>>a;
        long long cnt=cntNumbers(a);
        long long p=pow10(cnt);
        for(long long i=p/10;i<=a;i++)
        {
            long long dif=a+i;
            if(check(i,dif, p/10))
            {
                flag=true;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag)cout<<0<<endl;
    }
    return 0;
}
/*
10
216
1318
2349
44444
*/
