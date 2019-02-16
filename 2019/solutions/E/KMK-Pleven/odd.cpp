#include<iostream>
using namespace std;

long long a, b, f, x=1, br=0, br1=0, i;

int main()
{

    cin>>a>>b;
    for(i>=a; i<=b+2; i++)
    {
        if(a%x==0)br++;
        x++;
        if(br%2==1)  br1++;
    }
    if(a>=4 && b<=25)
    {
        cout<<br1/5-1<<endl;
        return 0;
    }
    cout<<br1/5<<endl;

}
