#include <iostream>
int brcif(int a)
{
    int br=0;
    do
    {
        a=a/10;
        br++;
    }while(a!=0);
    return br;
}
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int last,p,s,s2;
    int a=n-1;
    int b=n/a;
    if(brcif(n)==2)
    {
        last=n%10;
        p=n/10;
        if(last==p)
        {
            cout<<min(a,b)<<" "<<max(a,b)<<endl;
            cout<<a*b<<endl;
            return 0;
        }
    }
    if(brcif(n)==3)
    {
       last=n%10;
       n=n/10;
       s=n%10;
       p=n%10;
       if(last==p)
       {
           cout<<min(a,b)<<" "<<max(a,b)<<endl;
           cout<<a*b<<endl;
           return 0;
       }
    }
    if(brcif(n)==4)
    {
        last=n%10;
        n=n/10;
        s=n%10;
        n=n/10;
        s2=n%10;
        n=n/10;
        p=n%10;
        if(last==p&&s2==s)
        {
            cout<<min(a,b)<<" "<<max(a,b)<<endl;
            cout<<a*b<<endl;
            return 0;
        }
    }





return 0;
}
