#include<iostream>
using namespace std;

int main()
{
    int i,n,m,k,a,s=0;
    cin>>m>>k;
    for(i=0;s<=k;i++)
    {
        cin>>a;
        if(a%2==0) s+=a;
    }
    if(a==m) cout<<m<<endl;
        else
        if(a==m-1)
        {
            if(s<k)
            if(a==m+1) cout<<m+1<<endl;

        }
        cout<<s<<endl;
}
