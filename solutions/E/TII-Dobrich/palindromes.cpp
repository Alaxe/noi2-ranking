#include<iostream>
using namespace std;
int main()
{
    int i,j,n,pr,a[10],p1,br=0,k,p2=0,p3,x=0;
    cin>>n;
    for(i=n-1; i>0; i--)
    {
        if(x==1)
        {
            break;
        }
        for(j=n-1; j>0; j--)
        {
            pr=i*j;
            p3=pr;
            do
            {
                p2=p2*10+p3%10;
                p3=p3/10;
            }while(p3);
            if(p2-pr==0)
            {
                cout<<i<<" "<<j<<endl<<pr<<endl;
                x=1;
                break;
            }
            p2=0;
        }
    }
}
