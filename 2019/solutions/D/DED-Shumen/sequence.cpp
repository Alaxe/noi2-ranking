#include<iostream>
using namespace std;
int main()
{
    int m=1,n,k,cntk=0,cntm=2,cntmch=2,l=0;
    cin>>n>>k;
    if(n==1&&k==1)
    {
        cout<<1<<endl;
        return 0;
    }
    while(cntk!=k)
    {
        if(l==0)
        {
            m++;
            cntm++;
        }
        if(l==1)
        {
            m--;
            cntm++;
        }
        if(m==cntmch)
        {
            l=1;
        }
        if(m==k)
        {
            cntk++;
        }
        if(m==1&&l==1)
        {
            m=0;
            cntmch++;
            l=0;
        }
    }
    cout<<cntm<<endl;
    return 0;
}
