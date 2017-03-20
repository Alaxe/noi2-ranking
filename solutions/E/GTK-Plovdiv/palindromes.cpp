#include<iostream>
using namespace std;
int main()
{
    long long n,a,b=0,c,p=-1;
    cin>>n;
    long long dm=n,dg;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        a=i*j;
        c=a;
        b=0;
        while(c>0)
        {
            b=b*10+c%10;
            c=c/10;
        }
        if(a==b)
        {
            if(a>p)
            {
                p=a;
                if(i<j) {dm=i; dg=j;}
                else {dm=j; dg=i;}
            }
            if(a==p)
            {
                if(i>j)
                {
                    if(j<dm) {p=a; dm=j; dg=i;}
                }
                else
                {
                    if(i<dm) {p=a; dm=i; dg=j;}
                }

            }
        }
        }
    }
    cout<<dm<<" "<<dg<<endl;
    cout<<p<<endl;
    return 0;
}
