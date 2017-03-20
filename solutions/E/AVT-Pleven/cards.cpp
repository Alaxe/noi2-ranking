#include<iostream>
using namespace std;
int main()
{
    long long N,a,b,c,d,n,sum;
    cin>>N;
    sum=0;
   cin>>a>>b>>c>>d;
    if(a<d)
    {
        sum+1;
    }
    if(b<c)
    {
        sum+1;
    }
    if (b>=d and a>=c)
    {
        sum-0;
    }
  n=N-sum;
    cout<<n<<endl;
    return 0;
}
