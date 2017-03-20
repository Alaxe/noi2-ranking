#include<iostream>
#include<cstring>
using namespace std;
int main (){
bool gotovo=false;
long long len, m=1, i, n, m1, p=0, n1, x=0, otg=0;
char a[160000];
cin>>a;
len=strlen(a);
if(len<120){
for(i=1;gotovo==false;i++){
    m=m*2;
    m1=m;
    n1=n;
    n=0;
    if(n1>=15){
        while(m1>0 and m1>100000000000000){
            m1=m1/1000000000000000;
            n=n+15;
            //cout<<" petna ";
        }
    }
    if(n1>=5){
        while(m1>0 and m1>10000){
            m1=m1/100000;
            n=n+5;
                //cout<<" pet ";
        }
    }
    if(n1>=2){
        while(m1>0 and m1>10){
            m1=m1/100;
            n=n+2;
        }
    }
    while(m1>0){
        m1=m1/10;
        n++;
    }
    p=p+n;
    //cout<<n<<" ";
    if(p>=len){
        gotovo=true;
    }
}
cout<<i-1;
}else{
    for(i=1;true;i++){
    otg++;
    x=x+i;
    if(len<=x){
        gotovo=true;
        if(otg<50){
        cout<<otg+otg/31;
        }else{
            cout<<otg+otg/31+1;
        }
        return 0;
    }
    otg++;
    x=x+i;
    if(len<=x){
        gotovo=true;
        if(otg<50){
        cout<<otg+otg/31;
        }else{
            cout<<otg+otg/31+1;
        }
        return 0;
    }
    otg++;
    x=x+i;
    if(len<=x){
        gotovo=true;
        if(otg<50){
            cout<<otg+otg/31;
        }else{
            cout<<otg+otg/31+1;
        }
        return 0;
    }
}
}
return 0;
}
