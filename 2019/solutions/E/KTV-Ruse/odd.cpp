#include<iostream>
using namespace std;
int main()
{
    long long a,b,br=0,i,j;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        for(j=1;j<=b;j++)
        {
            if(j*j==i) br++;
        }
    }
    cout<<br<<endl;
    return 0;
}