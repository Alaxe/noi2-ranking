#include <iostream>
using namespace std;
int main()
{
    long long n,l,e,d,s,h,dh,sh,m,n1,k,br=0;
    cin>>n;
    n=n1;
    cin>>l;
    m=n/1000000;
    n=n%1000000;
    sh=n/100000;
    n=n%100000;
    dh=n/10000;
    n=n%10000;
    h=n/1000;
    n=n%1000;
    s=n/100;
    n=n%100;
    d=n/10;
    e=n%10;
    if(l==1) {do
              {
                if(m==l||sh==l||dh==l||h==l||s==l||d==l||e==l) k++;
              
                br++;  
             } while (n1=br);}
             n1=n1-k;
             cout<<n1;
                     
                    
}