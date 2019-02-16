#include<iostream>
using namespace std;
int n,k,br,i,a,b;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        if(a==1 && b==0)
            b++;
        if(a==1 && b==1)
            a++;
        if(a==b+1)
        {
            a++;
            b++;
        }
        if(a==k && b==k-1)
        {
            a--;
            b++;
        }
        if(a==b-1)
        {
            a--;
            b--;
        }
        br++;
    }
    b==a;
    if(a==n)
        cout<<br<<endl;
    return 0;
}
