#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
    unsigned long long n, k, a=1;
bool pr (unsigned long long h)
{
    int i=0;
while(h%10>0)
{
    h=h/10;
    i++;
}
if (i==n)
{
    return true;
}else
{
    return false;
}
}
int main()
{

    cin>>n>>k;
    if (k%10==0)
    {
    cout<<pow(10,n-1);
    return 0;
    }
    for(int i=2;true;i++)
    {

        a=k*i;
        //cout <<a;
        if(pr(a))
        {
            break;
        }
    }
    cout<<a;
    return 0;
}
