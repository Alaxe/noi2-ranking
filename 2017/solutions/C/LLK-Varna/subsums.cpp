#include<iostream>
using namespace std;
struct sums
{
    int i[2002];
};
sums k[2002];
int j[2002],m[2002];
int used[2002],sum[2002];
int main()
{
    int n,l,z=2000,p;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cin>>l;
        j[a]=l;
        l+=1000;
        z=min(z,l);
        m[l]++;
        sum[l]=1;
        k[l].i[l]=1;
    }
    cout<<n*2+n*2/5<<endl;
    return 0;
}
