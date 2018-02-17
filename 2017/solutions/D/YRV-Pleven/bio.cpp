#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
long long i,br,n1,v1,ch,brc1,d,d1,d2,d3,p1,tc;
int b[12];
string s,s1,s2,s3;
struct tel{
    int dt=0,m=0;
};
tel a[5];
int main()
{
    b[1]=31;
    b[2]=59;
    b[3]=90;
    b[4]=120;
    b[5]=151;
    b[6]=181;
    b[7]=211;
    b[8]=242;
    b[9]=272;
    b[10]=303;
    b[11]=333;
    cin>>s>>s1>>s2>>s3;
    if(s==s1 && s2==s1){
        if(s3==s){
            cout<<21252<<endl;
            return 0;
        }
    }
    d=s.size();
    d1=s1.size();
    d2=s2.size();
    d3=s3.size();
    for(i=0;i<d;i++){
       if(p1!=1){
            if(s[i]=='/'){
            p1=1;
            }
            else{
                tc=s[i]-'0';
                a[1].dt=a[1].dt*10+tc;
            }
       }
       else{
        tc=s[i]-'0';
        a[1].m=a[1].m*10+tc;
       }
    }
    tc=0;
    p1=0;
    for(i=0;i<d1;i++){
       if(p1!=1){
            if(s1[i]=='/'){
            p1=1;
            }
            else{
                tc=s1[i]-'0';
                a[2].dt=a[2].dt*10+tc;
            }
       }
       else{
        tc=s1[i]-'0';
        a[2].m=a[2].m*10+tc;
       }
    }


    tc=0;
    p1=0;
    for(i=0;i<d2;i++){
       if(p1!=1){
            if(s2[i]=='/'){
            p1=1;
            }
            else{
                tc=s2[i]-'0';
                a[3].dt=a[3].dt*10+tc;
            }
       }
       else{
        tc=s2[i]-'0';
        a[3].m=a[3].m*10+tc;
       }
    }


    tc=0;
    p1=0;
    for(i=0;i<d3;i++){
       if(p1!=1){
            if(s3[i]=='/'){
            p1=1;
            }
            else{
                tc=s3[i]-'0';
                a[4].dt=a[4].dt*10+tc;
            }
       }
       else{
        tc=s3[i]-'0';
        a[4].m=a[4].m*10+tc;
       }
    }


    int sum,sum1,sum2,v1,sum3;
    sum=b[a[1].m-1]+a[1].dt;
    sum1=b[a[2].m-1]+a[2].dt;
    sum2=b[a[3].m-1]+a[3].dt;
    sum3=b[a[4].m-1]+a[4].dt;
  //  cout<<sum3<<endl;
    if(s==s1 && s2==s1){
        if(s3==s){
            cout<<21252<<endl;
            return 0;
        }
        else{
            cout<<21252-sum3<<endl;
           return 0;
        }
    }

    v1=1;
    while(1){

        if(((v1*33+sum2-sum)%23==0) && (v1*33+sum2-sum1)%28==0){
            break;
        }
        else {
            v1++;
        }
    }

//int      sum3=b[a[4].m-1]+a[4].dt;
     cout<<abs((min(min(sum,sum1),sum2)+v1*2)-sum3);
    //cout<<v1*33<<" "<<sum<<" "<<sum1<<" "<<sum2<<endl;

    return 0;

}
/*
248163264128256512102420484096
*/
