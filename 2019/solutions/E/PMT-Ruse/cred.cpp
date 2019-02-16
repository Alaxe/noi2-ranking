#include<iostream>
using namespace std;
int main()
{
    long long br=0,n,m,a,b,c,d;
    cin>>n>>m;
    if(n/100>=1){a=n/10/10;b=n/10%10;c=n%10;do{n=n+a+b+c;a=n/10/10;b=n/10%10;c=n%10;br++;}while(n<=m);}
    if(n==1000){a=n/10/10/10;b=n/10/10%10;c=n/10%10;d=n%10;do{n=n+a+b+c+d;a=n/10/10/10;b=n/10/10%10;c=n/10%10;d=n%10;br++;}while(n<=m);}
    if(n/10>=1 && n/10<=9)
    {
        a=n/10;
        b=n%10;
        do
        {
            n=n+a+b;
            a=n/10;
            b=n%10;
            br++;
        }while(n<=m);
    }
        if(n/10==0)
    {
        do
        {
            n=n*2;
            br++;
        }while(n<=m);
    }

    cout<<br<<endl;
    return 0;
}
