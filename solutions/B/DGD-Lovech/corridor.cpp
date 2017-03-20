#include <iostream>

using namespace std;

int main()
{
    long long S,s1,s[100],min,N,w,h,x[1100],y[1100],i,o,z;
    cin>>w>>h;
    cin>>N;
    for (i=0;i<N;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    min=x[0];
    S=h*w;
    for (o=1;o<N;o++)
    {
        if (x[o]<min){min=x[o];}
    }
    s1=min*h;
    for (z=0;z<N;z++)
    {
        if (x[z]<x[z-1]){s[z]=(x[z-1]-min)*(y[z-1]-y[z-2]);
        if(s[z]<0){s[z]=0;}
        s1=s1+s[z];}
        if ((z==N-1)&&(x[N-1]>min)){s[z]=(x[N-1]-min)*(h-y[N-2]);
        if(s[z]<0){s[z]=0;}
        s1=s1+s[z];}
    }
    cout<<S-s1<<endl;

    return 0;
}
