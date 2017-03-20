#include<iostream>
using namespace std;
int main()
{
    long long k,m,sb=0,a;
    cin>>m>>k;
    cin>>a;
    long long maxx=a,a1;
    if (a%2==0) sb=a;
    
    if (a>k || a==200)
    {
        cout<<1<<" "<<a<<endl;
    }
    else
    {
        for (long long i=2;a1!=200;i++)
        {
            if(sb>k) {break;cout<<maxx<<" "<<sb<<endl;}
           cin>>a1;
           if (a1%2==0) sb=sb+a1;

           if(a1>m && m>maxx)
           {
               if (a1-m<=m-maxx)maxx=i;
           }
           
           if (a1>m && maxx>m)
           {
               if(a1-m<=maxx-m) maxx=i;
           }
           
           if(a1<m && maxx<m)
           {
               if (m-a1<=m-maxx) maxx=i;
           }
           
           if (a1<m && maxx>m)
           {
               if (m-a1<=maxx-m) maxx=i;
           }
        }
        cout<<maxx<<" "<<sb<<endl;
        
    }
    return 0;
    
}