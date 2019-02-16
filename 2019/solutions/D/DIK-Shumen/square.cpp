#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[45];
bool ai[45];
void raz(long long x)
{
    long long i=2;
    while(x!=1)
    {
        long long cnt=0;
        while(x%i==0)
        {
            cnt++;
            x/=i;
        }
        if (cnt>a[i])a[i]=cnt;
        i++;
    }
}
int main()
{
    long long n;
    cin>>n;
    long long x;
    for (long long i=0;i<n;i++)
    {
        cin>>x;
        if (!ai[x])
        {
            raz(x);
            ai[x]=1;
        }
    }
    long long ch=1;
    for (long long i=2;i<43;i++)
    {
        if (a[i]!=0)
        {
            for (int j=0;j<a[i];j++)ch=ch*i;
        }
    }
    long long i=1;
    long long kor=sqrt(ch);
    long long p=ch;
    while(kor*kor!=ch)
    {
        i++;
        ch=p*i;
        kor=sqrt(ch);
    }
    cout<<kor<<endl;
    return 0;
}
