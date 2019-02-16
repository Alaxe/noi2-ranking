#include<iostream>
using namespace std;
const int MAXN=1024;
int a[MAXN],c[MAXN];

int main()
{
    int n,k,br=0;
    cin>>n>>k;
    c[1]=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        for(int j=1; j<=100000; j++)
        {


            if(c[j]%a[j]==0)cout<<c[j]<<endl;
            c[j]+=1;
        }
    }

    return 0;
}
