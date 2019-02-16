#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    long long S, K;
    int a, b, c, d;
    cin>>S>>K;
    cin>>a>>b>>c>>d;
    int S1=4*d;
    int br1=K/S1;
    int ost=K-br1*S1;

    if(br1>S || (br1==S && ost>0)) /// all is over
    {
        double ev=d+(ost/(4.00*S));
        cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
        return 0;
    }

    if(ost==0)
    {
        double ev=d*1.000;
        cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
        return 0;
    }

    int type=(br1+1)%4;
    if(type==0) type=4;


    if(type==1) /// sector A
    {
        if(ost>=c*4)
        {
            ost-=4*c;
            double ev=c+ost/4.00;
            cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
            return 0;
        }
        if(ost<=a)
        {
            cout<<fixed<<setprecision(3)<<ost*1.00<<" "<<0.00<<" "<<0.00<<" "<<0.00<<endl;
            return 0;
        }
        else /// new 2
        {
            ost-=a;
            if(ost<=a)
            {
                cout<<fixed<<setprecision(3)<<a*1.00<<" "<<ost*1.00<<" "<<0.00<<" "<<0.00<<endl;
                return 0;
            }
            else
            {
                ost-=a;
                if(ost<=2*(c-a))
                {
                    cout<<fixed<<setprecision(3)<<a+ost/2.00<<" "<<a+ost/2.00<<" "<<0.00<<" "<<0.00<<endl;
                    return 0;
                }
                else /// new 3
                {
                    ost-=2*(c-a);
                    if(ost<=b)
                    {
                        cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<ost*1.00<<" "<<0.00<<endl;
                        return 0;
                    }
                    else
                    {
                        ost-=b;
                        if(ost<=b)
                        {
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<b*1.00<<" "<<ost*1.00<<endl;
                            return 0;
                        }
                        else
                        {
                            ost-=b;
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<b+ost/2.00<<" "<<b+ost/2.00<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }


    if(type==2) /// sector B
    {
        if(ost>=c*4)
        {
            ost-=4*c;
            double ev=c+ost/4.00;
            cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
            return 0;
        }
        if(ost<=b)
        {
            cout<<fixed<<setprecision(3)<<ost*1.00<<" "<<0.00<<" "<<0.00<<" "<<0.00<<endl;
            return 0;
        }
        else /// new 2
        {
            ost-=b;
            if(ost<=a)
            {
                cout<<fixed<<setprecision(3)<<b*1.00<<" "<<ost*1.00<<" "<<0.00<<" "<<0.00<<endl;
                return 0;
            }
            else
            {
                ost-=a;
                if(ost<=a)
                {
                    cout<<fixed<<setprecision(3)<<b*1.00<<" "<<a*1.00<<" "<<ost*1.00<<" "<<0.00<<endl;
                    return 0;
                }
                else /// new 3
                {
                    ost-=a;
                    if(ost<=2*(b-a))
                    {
                        cout<<fixed<<setprecision(3)<<b*1.00<<" "<<a+ost/2.00<<" "<<a+ost/2.00<<" "<<0.00<<endl;
                        return 0;
                    }
                    else
                    {
                        ost-=2*(b-a);
                        if(ost<=3*(c-b))
                        {
                            cout<<fixed<<setprecision(3)<<b+ost/3.00<<" "<<b+ost/3.00<<" "<<b+ost/3.00<<" "<<0.00<<endl;
                            return 0;
                        }
                        else
                        {
                            ost-=3*(c-b);
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<c*1.00<<" "<<ost*1.00<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }


    if(type==3) /// sector C
    {
        if(ost>=c*4)
        {
            ost-=4*c;
            double ev=c+ost/4.00;
            cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
            return 0;
        }
        if(ost<=b)
        {
            cout<<fixed<<setprecision(3)<<ost*1.00<<" "<<0.00<<" "<<0.00<<" "<<0.00<<endl;
            return 0;
        }
        else /// new 2
        {
            ost-=b;
            if(ost<=b)
            {
                cout<<fixed<<setprecision(3)<<b*1.00<<" "<<ost*1.00<<" "<<0.00<<" "<<0.00<<endl;
                return 0;
            }
            else
            {
                ost-=b;
                if(ost<=2*(c-b))
                {
                    cout<<fixed<<setprecision(3)<<b+ost/2.00<<" "<<b+ost/2.00<<" "<<0.00<<" "<<0.00<<endl;
                    return 0;
                }
                else /// new 3
                {
                    ost-=2*(c-b);
                    if(ost<=a)
                    {
                        cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<ost*1.00<<" "<<0.00<<endl;
                        return 0;
                    }
                    else
                    {
                        ost-=a;
                        if(ost<=a)
                        {
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<a*1.00<<" "<<ost*1.00<<endl;
                            return 0;
                        }
                        else
                        {
                            ost-=a;
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<c*1.00<<" "<<a+ost/2.00<<" "<<a+ost/2.00<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }


    if(type==4) /// sector D
    {
        if(ost>=c*4)
        {
            ost-=4*c;
            double ev=c+ost/4.00;
            cout<<fixed<<setprecision(3)<<ev<<" "<<ev<<" "<<ev<<" "<<ev<<endl;
            return 0;
        }
        if(ost<=c)
        {
            cout<<fixed<<setprecision(3)<<ost*1.00<<" "<<0.00<<" "<<0.00<<" "<<0.00<<endl;
            return 0;
        }
        else /// new 2
        {
            ost-=c;
            if(ost<=a)
            {
                cout<<fixed<<setprecision(3)<<c*1.00<<" "<<ost*1.00<<" "<<0.00<<" "<<0.00<<endl;
                return 0;
            }
            else
            {
                ost-=a;
                if(ost<=a)
                {
                    cout<<fixed<<setprecision(3)<<c*1.00<<" "<<a*1.00<<" "<<ost*1.00<<" "<<0.00<<endl;
                    return 0;
                }
                else /// new 3
                {
                    ost-=a;
                    if(ost<=2*(b-a))
                    {
                        cout<<fixed<<setprecision(3)<<c*1.00<<" "<<a+ost/2.00<<" "<<a+ost/2.00<<" "<<0.00<<endl;
                        return 0;
                    }
                    else
                    {
                        ost-=2*(b-a);
                        if(ost<=b)
                        {
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<b*1.00<<" "<<b*1.00<<" "<<ost*1.00<<endl;
                            return 0;
                        }
                        else
                        {
                            ost-=b;
                            cout<<fixed<<setprecision(3)<<c*1.00<<" "<<b+ost/3.00<<" "<<b*1.00+ost/3.00<<" "<<b+ost/3.00<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
/**
A a c b
B b a c
C b c a
D c a b
*/

/**
3 45
1 2 3 5
*/
