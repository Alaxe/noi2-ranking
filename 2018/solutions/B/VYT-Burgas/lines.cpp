#include <iostream>
#include <cmath>
using namespace std;
int main() {
    short n,nx[999],ny[999],a1[999],b1[999],nod,p,br=0;
    cin>>n;
    short x[999],y[999];
    for(short i=0;i<n;i++)cin>>x[i]>>y[i];
    for(short i=0;i<n;i++)
    {
        for(short j=i+1;j<n;j++)
        {
            nx[j]=x[i]-x[j];
            ny[j]=y[i]-y[j];
            if(nx[j]==0)ny[j]=1;
            if(ny[j]==0)nx[j]=1;
            if(nx[j]<0 && ny[j]<0){nx[j]=-nx[j];ny[j]=-ny[j];}
            if(nx[j]<0 && ny[j]>0){nx[j]=-nx[j];ny[j]=-ny[j];}
            if(nx[j]!=0 && ny[j]!=0)
            {
                if(nx[j]<ny[j])nod=nx[j];
                else nod=ny[j];
            }
            while(nod>1)
            {
                if(nx[j]%nod==0 && ny[j]%nod==0)break;
                nod--;
            }
            nx[j]=nx[j]/nod;
            ny[j]=ny[j]/nod;
            for(short a=x[j],b=y[j],p=-200;p<1;p++)
            {
                if(nx==0){a1[j]=0;b1[j]=-99;break;}
                if(a+p*nx[j]>-100){a1[j]=a+p*nx[j];b1[j]=b+p*ny[j];break;}
            }
        }
        for(int j=0;j<n;j++)
        {
            p=1;
            while(j+p<n)
            {
                if(nx[j]==nx[j+p])
                {
                    if(ny[j]==ny[j+p])
                    {
                        if(a1[j]==a1[j+p])
                        {
                            if(b1[j]==b1[j+p])br++;
                        }
                    }
                }
                p++;
            }
        }
    }
    cout<<ceil(sqrt(br))<<endl;
return 0;
}
