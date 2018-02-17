#include<iostream>
using namespace std;
int main(){
long long n,k,delimo,zapochvane=1,svurshvane=10,izhod=0;
cin>>n>>k;
if(1<=n<=18 and 1<=k<=10000000)
    {
    if(n>1)
        {
    for(int i=0;i<n-1;i++)
        {
        zapochvane=zapochvane*10;
        svurshvane=svurshvane*10;
        }
        }else
            {
            zapochvane=0;
            svurshvane=10;
            }
        for(delimo=zapochvane;delimo<svurshvane;delimo++)
            {
            if(delimo%k==0)
                {
                izhod=delimo;
                break;
                }
            }
        if(izhod==0)
            {
            cout<<"NO";
            }else
            {
            cout<<izhod;
            }
    }
return 0;
}
