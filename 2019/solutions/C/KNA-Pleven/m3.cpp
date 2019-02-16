#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    long double a,b,c,d,r1=0,r2=0,r3=0,r4=0,k;
    int s,br=0,bufer=0,bufer1=0,bufer3=0;
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    while(k>d*4)
    {
        k=k-d*4;
        br++;
    }
    if(br>s)
    {
        cout<<d<<" "<<d<<" "<<d<<" "<<d;
        return 0;
    }
    if(br%4==0)
    {
        ///a c b
        if(k<=2*c)
        {r3=0;r4=0;
            if(k>=a*2){r1=k/2;r2=k/2;}
            else
            {
                if(k>a){r1=a;r2=k-a;}
                else{r1=k;r2=0;}
            }
        }
        else
        {
            if(k>=4*c){r1=k/4;r2=k/4;r3=k/4;r4=k/4;}
            else
            {r1=c;r2=c;k=k-c*2;
                if(k>=2*b){r3=k/2;r4=k/2;}
                else
                {
                    if(k>=b){r3=b;r4=k-b;}
                    else{r3=k;r4=0;}
                }
            }
        }
    }
    if(br%4==1)
    {
        ///b a c
        if(k<c*3)
        {
            r4=0;if(k>=b*3){r1=k/3;r2=k/3;r3=k/3;}
            else
            {
                if(k>b)
                {r1=b;k=k-b;
                if(k>=a*2){r2=k/2;r3=k/2;}
                else{r2=a;r3=k-a;}
                }
                else{r1=k;r2=0;r3=0;}
            }
        }
        else
        {
            if(k>=4*c){r1=k/4;r2=k/4;r3=k/4;r4=k/4;}
            else{r1=c;r2=c;r3=c;r4=k-3*c;}
        }
    }
    if(br%4==2)
    {
        ///b c a
        if(k>=c*4){r1=k/4;r2=k/4;r3=k/4;r4=k/4;}
        else
        {
            if(k>c*2)
            {r1=c;r2=c;k=k-2*c;
                if(k>2*a){r3=k/2;r4=k/2;}
                else
                {
                  if(k>=a){r3=a;r4=k-a;}else{r3=k;r4=0;}
                }
            }
           else
            {   r3=0;r4=0;if(k>=b*2){r1=k/2;r2=k/2;}
                else
                {if(k>b){r1=b;r2=k-b;}
                    else{r1=k;r2=0;}
                }
            }
        }

    }
    if(br%4==3)
    {
        ///c a b
        if(k>=4*c){r1=k/4;r2=k/4;r3=k/4;r4=k/4;}
        else
        {
            if(k>=c)
            {
                r1=c;
                k=k-c;
                if(k>=b*3){r2=k/3;r3=k/3;r4=k/3;}
                else
                {
                    if(k>=b*2){r2=b;r3=b;r4=k-2*b;}
                    else
                    {
                        r4=0;
                        if(k>=2*a){r2=k/2;r3=k/2;}
                        else
                        {
                            if(k>a){r2=a;r3=k-a;}
                            else{r2=k;r3=0;}
                        }
                    }
                }
            }
        }
    }
    bufer=r1;
        r1=r1-bufer;
        r1=r1*10000;
        bufer1=r1;
        bufer3=bufer1%10;
        bufer1=bufer1/10;
        if(bufer3>=5)bufer1++;
        if(bufer1==0) cout<<bufer<<'.'<<bufer1<<bufer1<<bufer1<<" ";
        else cout<<bufer<<'.'<<bufer1<<" ";
        bufer=r2;
        r2=r2-bufer;
        r2=r2*10000;
        bufer1=r2;
        bufer3=bufer1%10;
        bufer1=bufer1/10;
        if(bufer3>=5)bufer1++;
        if(bufer1==0) cout<<bufer<<'.'<<bufer1<<bufer1<<bufer1<<" ";
        else cout<<bufer<<'.'<<bufer1<<" ";
        bufer=r3;
        r3=r3-bufer;
        r3=r3*10000;
        bufer1=r3;
        bufer3=bufer1%10;
        bufer1=bufer1/10;
        if(bufer3>=5)bufer1++;
        if(bufer1==0) cout<<bufer<<'.'<<bufer1<<bufer1<<bufer1<<" ";
        else cout<<bufer<<'.'<<bufer1<<" ";
        bufer=r4;
        r4=r4-bufer;
        r4=r4*10000;
        bufer1=r4;
        bufer3=bufer1%10;
        bufer1=bufer1/10;
        if(bufer3>=5)bufer1++;
        if(bufer1==0) cout<<bufer<<'.'<<bufer1<<bufer1<<bufer1;
        else cout<<bufer<<'.'<<bufer1;
    return 0;
}
