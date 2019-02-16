#include <iostream>
using namespace std;
int main()
{
    int a,b,e=0;
    cin>>a>>b;

    while(a<=b)
    {
        e++;
        a=a/1000+(a/100)%10+(a%100)/10+a%10+a;
    }
    cout<<e;
}
