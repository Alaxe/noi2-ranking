#include<iostream>
using namespace std;
int main()
{
    long long n,br=0,v[19];
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        int i2=i;
        v[0]=i%10;
        i=i/10;
        for(int j=1; i!=0; j++)
        {
            v[j]=i%10;
            if(v[j]!=v[j-1])
            {
                break;
            }
            i=i/10;
        }
        if(i==0)
        {
            br++;
        }
        i=i2;
    }
    cout<<br<<endl;
    return 0;
}
