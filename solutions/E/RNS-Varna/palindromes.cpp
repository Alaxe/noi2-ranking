#include<iostream>
using namespace std;
int main()
{
    long N,a,b,k,z=0,l;
    cin>>N;
    a=N-1;
    while(a>0)
    {
       b=a;
       while(b>0)
       {
           k=a*b;
           while(k>0)
           {
               l=k%10;
               z=z*10+l;
               k=k/10;
           }
           if(k==z)
           {cout<<b<<" "<<a<<endl;
            cout<<k;return 0;}
           b--;
        }
        a--;
    }
}
