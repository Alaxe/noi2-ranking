#include<iostream>
using namespace std;
int a[10009];
int main()
{
    int n,c=1,pr=0,b=3,i=0;
    cin>>n;
    n--;
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    pr=c*c;
    if(pr%a[i]!=0)
    {
        c++;
        pr=pr+b;
        b=b+2;
    }
    else true;
    cout<<c<<endl;
    return 0;
}
