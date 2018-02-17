#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long A,B;

long long calculate1(long long x){
    double y1=(-1+sqrt(1+4*x))/2;

    long long y=y1;

    if(y*(y+1)<x)y++;

    if(y*(y+1)>=A && y*(y+1)<=B){
        return y;
    }

    return 0;
}

long long calculate2(long long x){
    double y1=(-1+sqrt(1+4*x))/2;
    long long y=y1;

    if((y+1)*(y+2)<x)y++;

    if(y*(y+1)>=A && y*(y+1)<=B){
        return y;
    }

    return 0;
}


long long a1,a2;
int main(){
cin>>A>>B;
    a1=calculate1(A);
    a2=calculate2(B);

    if(a1==0 || a2==0){
        cout<<0<<endl;
    }
    else
    cout<<a2-a1+1<<endl;
return 0;
}
