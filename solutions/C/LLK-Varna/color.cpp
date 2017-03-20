#include<iostream>
#include<cstring>
using namespace std;
int m[100000];
int i[11];
int main()
{
    int t,n,z=100000;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        cin>>n;
        memset(m,0,sizeof(m));
        z=1;
        for(int b=1; b<=n; b++)
        {
            int k;
            cin>>k;
            m[b]++;
            m[k]++;
        }
        for(int b=1; b<=n; b++)
        z=max(m[b],z);
        i[a]=z;
    }
    for(int a=0; a<t; a++)
    cout<<i[a]<<endl;
    return 0;
}
/**
2
4
4 1 2 3
5
4 1 2 3 4
*/
