#include<iostream>
#include<cstring>
using namespace std;
int step(unsigned long long x)
{int l=0;
while(x!=1)
{x=x/2;
l++;
}
return l;
}
int main(){
    string s;
    cin>>s;
    int n,k=1,l,a=0,j=0;
    n=s.size();
    l=n;
    for(int i=1;i<=3;i++)
    {if(i*3>=n) { k=i; n=n-i*3; break;}
    k=i;
    n=n-i*3;
    }
    if(n<=16 && n>=1) {k=4; n=n-k*4;}
    while(n>0){

    for(int i=k;i<k+2;i++)
    {if(i*3>=n) {k=i; n=n-i*3; break;}
    k=i;
    n=n-i*3;
    }
    if(n>0) {k=k+1; n=n-k*4;}
    }
    for(int i=l-k;i<l;i++)
    {
    a=a*10+(s[i]-'0');

    }
    cout<<step(a)<<endl;
    return 0;}
    /*24816326412825651210242048409681921638432768655361310722621445242881048576*/

