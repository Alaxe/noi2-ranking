#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int m, n, p,q, x=1, y, z, sum, br=0, j, gl, i;
    long long k=pow(2,30);
    cin>>m>>n>>p>>q;
    z=n-m;
    z=z-p;
    do
    {
        z=z+q;
        z=z-p;
        x++;
    }
    while(z>0);
    z=n-m;

    for(i=x; i>0; i--)
    {

        for(y=i-1;  y>=0; y--)
        {

            j=y+1;
            sum=p*i-q*y;
            gl=z-p;
            if(sum>z)
            {
                br++;
                if((i!=y+1)&&gl>z) {br--; break;}
            }
        }
        if(i*p<z) break;
    }
    br=br%k;
    cout<<br<<endl;
}
