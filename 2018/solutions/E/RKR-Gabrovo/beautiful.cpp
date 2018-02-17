#include<iostream>
using namespace std;
int main()
{
    int n,k,i,j,x=0,minr=0,a;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        if (x>0) x=x*10;
        if (x==0) x++;
    }
    //---------------------------------------------------------
    a=x*10-10;
    for (j=1;j<=a;j++)
    {
        if (x%k==0) {minr=x;break;}
        else x++;
    }
     if (minr==0) cout<<"NO"<<endl;
     else cout<<minr<<endl;
     return 0;
}
