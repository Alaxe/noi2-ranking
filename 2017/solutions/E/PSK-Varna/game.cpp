#include <iostream>
using namespace std;
int main ()
{
    long long K,M,n,sum=0,br=0,a,min=100000,b,c;
    cin>>K>>M;
    for(int i=0; i<200; i++)
    {
        cin>>n;
        br++;
        if(n%2==0) sum+=n;
        if(n>K) {a=n-K;}
        else {a=K-n;}
        if(a<min) {min=a; b=br;}
        if(sum>M) break;
    }
    cout<<b<<" "<<sum<<endl;
    return 0;
}
