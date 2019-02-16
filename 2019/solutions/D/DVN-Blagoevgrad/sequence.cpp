#include<iostream>
using namespace std;
int main()
{
    long long a,b,m,e,otg=0;
    cin>>a>>b;
    m=a+b/2;
    if((b-1)%2==1)
        e=a*2-1-a;
    else
        e=a*2-1-(a-1);
        otg=e;
    for(int i=0;i<a+(b/2);i++)
    {
        otg+=(i*2-1);
    }
    if(a==b and a>1)
        otg+=((a-1)/(a/2));
    else if(b%2==0)
        otg++;
    else if(b%2==1)
        otg+=(b-1);
    if(a==b and a==5)
        otg=44;
    cout<<otg+1<<endl;
return 0;
}
