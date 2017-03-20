#include <iostream>
using namespace std;
int main()
{
    long long arrt[1000],ct[1000],a,b,i=0,t,min1=721,min2=721,ctm1,ctm2,arrt2=0,min3;
    bool flag=true;
    while(cin)
    {
        cin>>a>>b;
        arrt[i]=a;
        ct[i]=b;
        i++;
    }
    for(int l=0;l<i;l++)
    {
        if(arrt[l]<min1){min1=arrt[l];ctm1=l;}
    }
    t=min1+ct[ctm1];
    do
    {
        arrt2=min2;
        min2=721;
        for(int k=0;k<i;k++)
        {
            if(arrt[k]<min2&&arrt[k]>min1){min2=arrt[k];ctm2=k;}
        }
        if(min2==721){flag=false;break;}
        if(min2>=t)t=min2+ct[ctm2];
        else
        if(t>min2)t=t+ct[ctm2];
        min1=min2;
    }
    while(flag==true);
    cout<<t-arrt2<<endl;

    return 0;
}
