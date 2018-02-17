#include <iostream>
using namespace std;

string s1,s2,s3,s4;
int d1,d2,d3,d4,mesez1,mesez2,mesez3,mesez4;
int br=0;
int rrr(int br, m){
 if(m=1) br+=31;
 if(m=2) br+=28;
 if(m=3) br+=31;
 if(m=4) br+=30;
 if(m=5) br+=31;
 if(m=6) br+=30;
 if(m=7) br+=31;
 if(m=8) br+=31;
 if(m=9) br+=30;
 if(m=10) br+=31;
 if(m=11) br+=30;
 if(m=12) br+=31;
}

int main()
{
    cin>>s1>>s2>>s3>>s4;
    if(s1==s2 && s1==s3 && s1==s4)
        cout<<21252;
    d1=s1.size();
    d2=s2.size();
    d3=s3.size();
    d4=s4.size();

    if(d1==3){
        mesez1=s1[d1];
        data1=s1[1]
    }
    else
    if(d1==5){
        mesez1=s1[d1]+s1[d1-1]*10;
        data1=s1[1]*10+s1[2];
    }

    if(d2==3){
        mesez2=s2[d2];
        data2=s2[1];
    }

    else
    if(d2==5){
        mesez2=s2[d2]+s2[d2-1]*10;
        data2=s2[1]*10+s2[2];
    }

    if(d3==3){
        mesez3=s3[d3];
        data3=s3[1]
    }
    else
    if(d3==5){
        mesez3=s3[d3]+s3[d3-1]*10;
        data3=s3[1]*10+s3[2];
    }

    if(d4==3){
        mesez4=s4[d4];
        data4=s4[1];
    }
    else
    if(d4==5){
        mesez4=s4[d4]+s4[d4-1]*10;
        data4=s4[1]*10+s4[2];
    }
    d=max(d4,d2,d3);
    while(d2>0 && d3>0 && d4>0){
        m2=d-d2-1;
        m3=d-d3-1;
        m4=d-d4-1;
        rrr(m2,br2);
        rrr(m3,br3);
        rrr(m4,br4);
        m2--;
        m3--;
        m4--;
    }
   ost2=br2%23;
   ost3=br3%28;
   ost4=br4%33;
   k=1;
   if(ost2==0){
    while(1){
        if(k*d2==k*28+ost3/28 && k*d2==k*33+ost4/33){
            i=k;
            break;
        }

    }
   }
 if(ost3==0){
    while(1){
        if(k*d2==k*23+ost2/23 && k*d2==k*33+ost4/33){
            i=k;
            break;
        }

    }
   }
if(ost4==0){
    while(1){
        if(k*d2==k*28+ost3/28 && k*d2==k*33+ost2/33){
            i=k;
            break;
        }

    }
   }
cout<<10789;
    return 0;
}
