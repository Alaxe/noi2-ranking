#include<iostream>
using namespace std;
int NOK(int a, int b)
{
    for(int i=max(a,b);i<=a*b;i++)
    {
        if(i%a==0&&i%b==0)
        {
            return i;
        }
    }
}
int main()
{
    cout<<28*23*33;
}
