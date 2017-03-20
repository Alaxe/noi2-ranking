#include <iostream>
using namespace std;
int main ()
{
    int N,d,a,b,c,p,br=0;
    long long pr,pr1=0;
    cin>>N;
    for(int i=N-1; i>0; i--)
    {
        a=i;
        for(int j=N-1; j>0; j--)
        {
            b=j;
            pr=a*b;
            p=pr;
            while(pr)
            {
                d=pr%10;
                pr=pr/10;
                pr1=10*pr1+d;
                c=pr1;
            }
            if(p==c)
            {
                if(a<=b)
                {
                    cout<<a<<" "<<b<<endl;
                    cout<<p<<endl;
                }
                else
                {
                    cout<<b<<" "<<a<<endl;
                    cout<<p<<endl;
                }
                return 0;
            }
        }
    }
    return 0;
}
