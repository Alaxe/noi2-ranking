#include <iostream>

using namespace std;

int main()
{
    int N;
    int wH, wW;
    int x[11500];
    int y[11500];
    int w[11500];
    int h[11500];
    int xp[11500];
    int yp[11500];
    int T;
    int Ssq[11005];
    int mark[11005];
    int sp[11005];
    int sh;

    cin>>wH>>wW>>N;
    sh=wH*wW;

    for(int i=1;i<=N;i++)
    {
        cin>>x[i]>>y[i]>>w[i]>>h[i];

    }
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>xp[i]>>yp[i];
        Ssq[i]=w[i]*h[i];
    }

    for(int i=1;i<=N;i++)
    {
       for(int j=2;j<=N;j++)
       {
           if(mark[i]!=1 && ((x[j]>x[i] && x[j]<x[i]+w[i]) ||(y[j]>y[i] && y[j]<y[i]+h[i]) ))
           {if((x[i]<x[j] || y[i]<y[j]) && (x[i]+w[i]>x[j] || y[i]+h[i]>y[j]))
           {
               Ssq[i]=Ssq[i]-Ssq[j];
               mark[i]=1;

           }
       }
       }
    }

    for(int i=1;i<=T;i++)
    {

        if(( xp[i]>x[i] && x[i]+w[i]>xp[i])||(yp[i]>y[i] &&  y[i]+h[i]>yp[i]) )
        {
            sp[i]=Ssq[i];


        }
cout<<Ssq[i]<<endl;
cout<<"glup"<<endl;

      /* if((xp[i]<x[i] || x[i]+w[i]<xp[i]) || (yp[i]<y[i] || y[i]+h[i]<yp[i]))
        {
            for(int j=1;j<=T;j++)
            {


                    sh-=Ssq[j];

            }
            cout<<sh<<endl;
        }
        */
    }

    return 0;
}
