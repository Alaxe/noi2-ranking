#include <iostream>
using namespace std;
long long num(int a)
{
    long long num=1;
    while (a!=1)
    {
        num*=10;
        a--;
    }
    return num;
}
int main()
{
    int n;
    long long k,minum=0;
    cin>>n>>k;
    if (k>num(n)*10-1) cout<<"NO"<<endl;
    else if (k>=num(n) && k<num(n)*10) cout<<k<<endl;
    else
    {
        for (long long i=num(n); i<num(n)*10; i++)
        {
            if (i%k==0)
            {
                minum=i;
                break;
            }
        }
        if (minum) cout<<minum<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
