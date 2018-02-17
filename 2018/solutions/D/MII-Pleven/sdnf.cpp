#include <iostream>
#include <string>
using namespace std;

string s;
long long n,sum,p=1;

string Sbor(string s1,string s2){
int r,ost,d1,d2,dr,i,p,x,y;
string rez;

    d1=s1.size();
    d2=s2.size();
    dr=d2+1;
    rez[dr-1]=s1[d1-1];

    for(i=d2-1;i>0;i--){
        x=s2[i]-'0';
        y=s1[i-1]-'0';
        r=ost+x+y;
        if(r>=10){
            ost=r/10;
            r=r%10;
        }
        else ost=0 ;

        rez[1]=r+'0';
    }
    int k,m,z;
    m=s2[0]-'0';
    z=m+ost;
    rez[0]=z+'0';

    return rez;
}

string Mult(string ss,int k){
int x,y,i,ost=0,ds,d1,d2;
string s1,s2,res;

    ds=ss.size();
    for(i=ds-1;i>=0;i--){
        x=ss[i]-'0';
        y=ost+(k%10*x);
        if(y>=10){
            ost=y/10;
            y=y%10;
        }
        else ost=0;
        s1[i]=y+'0';
    }
    if(ost!=0){
        d1=s1.size();
        for(i=d1;i>0;i--){
           s1[i]=s1[i-1];
        }
        s1[0]=ost+'0';
        ost=0;
    }

    for(i=ds-1;i>=0;i++){
        x=ss[i]-'0';
        y=ost+(k/10*x);
        if(y>=10){
            ost=y/10;
            y=y%10;
        }
        else ost=0;
        s2[i]=y+'0';
    }

    if(ost!=0){
        d2=s2.size();
        for(i=d1;i>0;i--){
           s2[i]=s2[i-1];
        }
        s2[0]=ost+'0';
        ost=0;
    }

    res=Sbor(s1,s2);

    return res;
}

int main (){
long long i;

    cin>>n;
    if(n<=40){
    for(i=2;i<=n;i++){
        p*=i;
    }

    while(p!=0){
        sum+=p%10;
        p/=10;
    }
    }
    else{
     s="3628800";
     for(i=10;i<=n;i++){d1=s1.size();
        for(i=d1;i>0;i--){
           s1[i]=s1[i-1];
        }
        s[0]=ost+'0';
        ost=0;
        s=Mult(s,i);
     }
     int d;
     d=s.size();
     for(i=0;i<d;i++){
        sum=sum+(s[i]-'0');
     }
    }

    cout<<sum;
 return 0;
}

