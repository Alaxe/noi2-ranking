#include<iostream>
using namespace std;
int sfib(int n)
{
    int a=1,b=1,c=2,sum=2;
    if(n<=0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n>2)
    {
        for(int i=0;i<n-2;i++)
        {
            c=a+b;
            a=b;
            b=c;
            sum=sum+c;
        }
        return sum;
    }
}
int main()
{
    int n,m,br,sumg=0,summ=0,X=2,Y=2;
    cin>>n>>m;
    if(n>2)
    {
        for(int j=1;j<=m;j++)
        {
            sumg=sumg+sfib(n-X);
            X=X+2;
        }
    }
    if(m<n)
    {
        cout<<sfib(n)-sumg-sfib(n-m)<<endl;
    }
    else
    {
        cout<<sfib(n)-sumg<<endl;
    }
    return 0;
}

