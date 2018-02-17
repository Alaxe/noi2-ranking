#include <iostream>
#include <vector>
using namespace std;
int w,h,n,f[1100000];
vector <int> x;
vector <int> y;
void read()
{
    int i,r,c;
    cin>>w>>h>>n;
    for(i=0;i<n;i++)
    {
        cin>>r>>c;
        x.push_back(r);
        y.push_back(c);
    }
}
void scratch()
{
    int i,j,b,e;
    for(i=0;i<n;i+=2)
    {
        b=y[i];
        e=y[i+1];
        for(j=b;j<e;j++)
        {
            if(f[j]<x[j]) f[j]=x[j]+1;
        }
    }
    for(i=1;i<=h;i++) cout<<f[i]<<endl;

}
void solve()
{
    int i,br=0;
    for(i=1;i<=h;i++)
    {
        br+=w-f[i];
    }
    cout<<br<<endl;
}
int main()
{
    read();
    scratch();
    solve();
    return 0;
}