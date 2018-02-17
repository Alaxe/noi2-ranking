#include<iostream>
using namespace std;
class Rectangle
{
    public:
    int xA,yA,w,h,xB,yB,Size;
};


int main()
{
    int Pw,Ph,n,x,y,w,h,t;

    cin>>w>>h;
    cin>>n;
    Rectangle Rec[n+1];
    Rec[0].xA=0;
    Rec[0].yA=0;
    Rec[0].w=w;
    Rec[0].h=h;
    Rec[0].Size=Rec[0].w*Rec[0].h;
    Rec[0].xB=Rec[0].xA+Rec[0].w;
    Rec[0].yB=Rec[0].yA+Rec[0].h;
    for(int i=1;i<=n;i++)
    {
        cin>>Rec[i].xA;
        cin>>Rec[i].yA;
        cin>>Rec[i].w;
        cin>>Rec[i].h;
        Rec[i].Size=Rec[i].w*Rec[i].h;
        Rec[i].xB=Rec[i].xA+Rec[i].w;
        Rec[i].yB=Rec[i].yA+Rec[i].h;
    }

    for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(Rec[i].Size > Rec[j].Size)swap(Rec[i],Rec[j]);
    int allsize=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //if(Rec[i].Size > Rec[i].Size)swap(Rec[i],Rec[j]);
            if(Rec[i].xA<Rec[j].xA && Rec[i].yA<Rec[j].yA && Rec[i].xB>Rec[j].xB && Rec[i].yB>Rec[j].yB)
            {
                Rec[i].Size-=Rec[j].Size;
            }
            if(Rec[j].xA<Rec[i].xA && Rec[j].yA<Rec[i].yA && Rec[j].xB>Rec[i].xB && Rec[j].yB>Rec[i].yB)
            {
                Rec[j].Size-=Rec[i].Size;
            }
        }
        allsize=allsize+Rec[i].Size;
    }
    Rec[n].Size=Rec[n].Size-allsize;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int X,Y;
        cin>>X>>Y;
         for(int j=0;j<=n;j++)
            {
                if(X>Rec[j].xA && Y>Rec[j].yA && X<Rec[j].xB && Y<Rec[j].yB){cout<<Rec[j].Size<<endl;break;}
            }
    }
    return 0;
}
