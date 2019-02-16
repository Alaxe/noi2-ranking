#include<iostream>
using namespace std;
int main()
{
    int n,b=1,c=1,a;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        if(b*b%a!=0 && a%b!=0)
        {
            b=b*a;
        }
        if(b*b%a!=0 && a%b==0)
        {
            b=a;
        }

        n--;
    }
    while(b!=c*c)
    {
        c++;
    }
    cout<<c<<endl;
    return 0;
}
