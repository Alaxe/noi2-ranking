#include <bits/stdc++.h>
using namespace std;
long long brs[40],k,po;
string t;
int main()
{
    cin>>t;
    brs[1]=3;
    brs[2]=3;
    brs[3]=3;
    brs[4]=4;
    for ( int i=5 ; i<=39 ; i++)
    {
        if((i-4)%3==0)brs[i]=4;
        else brs[i]=3;
    }
    k=t.size();
    po=0;
    for(int i=1 ; i<=60 ; i++)
    {
        po+=brs[i];
        k=k-brs[i]*i;
        if(k<0){k=k+i;po--;}
        if(k==0)break;
        if(k<0){k=k+i;po--;}
        if(k==0)break;
        if(k<0){k=k+i;po--;}
        if(k==0)break;
        if(k<0){k=k+i;po--;}
        if(k==0)break;
    }
    cout<<po<<endl;
    return 0;
}
