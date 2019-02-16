#include<iostream>
using namespace std;
int main()
{
 int n,m,a,br=1,e,d,s,h,e1,d1,s1,h1;bool fl=1;
 cin>>n>>m;
 e=n%10;d=n/10%10;s=n/100%10;h=n/1000;
 a=n+e+d+s+h;
 do{e1=a%10;d1=a/10%10;s1=a/100%10;h1=a/1000;
    a=a+e1+d1+s1+h1;
    if(a<=m)br++;
    else fl=0;
    }while(fl==1);
    cout<<br+1<<endl;
}
