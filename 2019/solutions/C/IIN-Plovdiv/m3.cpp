#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long S,K,a,b,c,d,sek,ot1=0,ot2=0,ot3=0,ot4=0;
    cin>>S>>K;
    cin>>a>>b>>c>>d;

    sek=K/(d*4)+1;
    if(sek%4==0) sek=4;
    else sek=sek%4;

    if(sek==1){swap(b,c);}
    if(sek==2){swap(a,b);}
    if(sek==3){swap(a,c);swap(a,b);}
    if(sek==4){swap(a,c);swap(b,c);}

    long long ost=K%(d*4);
    if(ost<=a) cout<<ost<<".000 0.000 0.000 0.0000"<<endl;
    return 0;
}

