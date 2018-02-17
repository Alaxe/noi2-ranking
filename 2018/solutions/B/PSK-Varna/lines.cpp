#include <iostream>
using namespace std;
struct points
{
    double x;
    double y;
};
int main ()
{
    int n;
    double xx[1000],yy[1000],oo[1000];
    int brx[1000],bry[1000],bro[1000],maxx=0,maxy=0,maxo=0;
    points p[1000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].x>>p[i].y;
        xx[i]=p[i].x;
        yy[i]=p[i].y;
        if(p[i].y!=0) oo[i]=(p[i].x)/(p[i].y);
        else oo[i]=101;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(xx[i]==xx[j]) brx[i]++;
        }
        if(brx[i]>maxx) maxx=brx[i];
        for(int k=0; k<n; k++)
        {
            if(yy[i]==yy[k]) bry[i]++;
        }
        if(bry[i]>maxy) maxy=bry[i];
        for(int l=0; l<n; l++)
        {
            if(oo[i]==oo[l]) bro[i]++;
            if(oo[i]==101) bro[l]++;
        }
        if(bro[i]>maxo) maxo=bro[i];
    }
    //cout<<maxx<<" "<<maxy<<" "<<maxo<<" "<<endl;
    cout<<max(max(maxx,maxy),maxo)<<endl;
    return 0;
}
