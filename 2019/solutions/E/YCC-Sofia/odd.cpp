#include<iostream>
using namespace std;
int main()
{
    long long a,b,br=0,br1=0,i,j;
    cin>>a>>b;
    for(i=a; i<b; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(i%j==0)
                br++;
        }
        if(br%2==1)
            br1++;
        br=0;
    }
    cout<<br1;
    return 0;
}
