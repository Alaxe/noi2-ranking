#include<iostream>
using namespace std;
int main()
{
    long long N, K, first, add, mul, mod, next, sum = 0, majInd = 0, minor = -1, minInd = -1;
    cin>>N>>K;
    cin>>first>>mul>>add>>mod;
    long long curr = first, major = first;
    for(long long i = 0; i < N; i++)
    {
        sum += major;
        //cout<<"sum="<<sum;
        next = (curr * mul + add) % mod;
        if(minInd + K <= i + 1 )
        {
            minor = -1;
            minInd = -1;
        }
        if(next >= minor)
        {
            minor = next;
            minInd = i+1;
        }
        if(majInd + K <= i + 1)
        {
            major = minor;
            majInd = minInd;
            minor = -1;
            minInd = -1;
        }
        if(next >= major)
        {
            major = next;
            majInd = i+1;
            minor = -1;
            minInd = -1;
        }
        //cout<<i<<" "<<major<<" "<<minor<<endl;
        cout<<curr<<" ";
        curr = next;

    }
    cout<<sum;
}
