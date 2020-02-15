#include <iostream>
using namespace std;
int main()
{
    long long n,k=1,a,b,counter=0,brs=0,brs2=0,c;
    cin>>n;
    for(int i=1;n >= i;i++)
    {
        c=k;
        b=k%10;
        while(c > 0)
        {
            a=c%10;
            c=c/10;
            brs++;
            if(a == b)brs2++;
        }
        k=k+1;
        if(brs == brs2)
        {
            counter++;
        }
        brs=0;brs2=0;
    }
    cout<<counter<<endl;
    return 0;
}
