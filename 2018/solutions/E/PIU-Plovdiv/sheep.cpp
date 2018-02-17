#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N,L,ch,ch1,ch2,ch3,br=0,i,maxi=0;
    cin>>N>>L;
    if(L==1)
    {
    cin>>ch;
    for(i=1;i<=100000000;i++)
    {
        if(i!=ch&&i%10!=ch&&i/10%10!=ch&&i/100%10!=ch&&i/1000%10!=ch&&i/10000%10!=ch&&i/100000%10!=ch){br++;maxi=i;}
        if(br==N)break;
    }
    cout<<maxi<<endl;
    }
    if(L==2)
    {
    cin>>ch>>ch2;
    for(i=1;i<=100000000;i++)
    {
        if(i!=ch&&i%10!=ch&&i/10%10!=ch&&i/100%10!=ch&&i/1000%10!=ch&&i/10000%10!=ch&&i/100000%10!=ch&&i!=ch2&&i%10!=ch2&&i/10%10!=ch2&&i/100%10!=ch2&&i/1000%10!=ch2&&i/10000%10!=ch2&&i/100000%10!=ch2){br++;maxi=i;}
        if(br==N)break;
    }
    cout<<maxi<<endl;
    }
    if(L==3)
    {
    cin>>ch>>ch2>>ch3;
    for(i=1;i<=100000000;i++)
    {
        if(i!=ch&&i%10!=ch&&i/10%10!=ch&&i/100%10!=ch&&i/1000%10!=ch&&i/10000%10!=ch&&i/100000%10!=ch&&i!=ch2&&i%10!=ch2&&i/10%10!=ch2&&i/100%10!=ch2&&i/1000%10!=ch2&&i/10000%10!=ch2&&i/100000%10!=ch2&&i!=ch3&&i%10!=ch3&&i/10%10!=ch3&&i/100%10!=ch3&&i/1000%10!=ch3&&i/10000%10!=ch3&&i/100000%10!=ch3){br++;maxi=i;}
        if(br==N)break;
    }
    cout<<maxi<<endl;
    }

    return 0;
}
