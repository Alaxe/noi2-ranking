#include<iostream>
#include<iomanip>

using namespace std;

int s,lastlevel;
int a,b,c,d;

int sec;
int k;
double num;

int main()
{
    cin>>s>>lastlevel;
    cin>>a>>b>>c>>d;

    k=lastlevel%(4*d);
    sec=lastlevel/(4*d);
    if(k!=0) sec++;
    sec=sec%4;

    if(s*4*d<lastlevel)
    {
        num=lastlevel-s*4*d;
        num=num/s/4;
        cout<<fixed<<setprecision(3)<<d+num<<" ";
        cout<<fixed<<setprecision(3)<<d+num<<" ";
        cout<<fixed<<setprecision(3)<<d+num<<" ";
        cout<<fixed<<setprecision(3)<<d+num<<"\n";
        return 0;
    }

    if(sec==1)
    {
        if(k<=a)
            cout<<k<<".000 0.000 0.000 0.000\n";
        else
        {
            if(k<=2*a)
            {
                cout<<a<<".000 "<<k-a<<".000 0.000 0.000\n";
            }
            else if(k<=c*2)
            {
                if(k%2==0)
                {
                    cout<<k/2<<".000 "<<k/2<<".000 0.000 0.000\n";
                }
                else
                {
                    num=k;
                    cout<<num/2<<"00 "<<num/2<<"00 0.000 0.000\n";
                }
            }
            else if(k-c*2<=b)
            {
                cout<<c<<".000 "<<c<<".000 "<<k-2*c<<".000 0.000\n";
            }
            else if(k-c*2<=2*b)
            {
                cout<<c<<".000 "<<c<<".000 "<<b<<".000 "<<k-2*c-b<<".000\n";
            }
            else if(k-4*c<=0)
            {
                if((k-2*c)%2==0)
                {
                    cout<<c<<".000 "<<c<<".000 "<<(k-2*c)/2<<".000 "<<(k-2*c)/2<<".000\n";
                }
                else
                {
                    num=k-2*c;
                    cout<<c<<".000 "<<c<<".000 "<<num/2<<"00 "<<num/2<<"00\n";
                }
            }
            else if(k%4==0)
                cout<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000\n";
            else if(k%4==2)
            {
                num=k;
                cout<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00\n";
            }
            else
            {
                num=k;
                cout<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0\n";
            }
        }
    }
    else if(sec==2)
    {
        if(k<=b)
            cout<<k<<".000 0.000 0.000 0.000\n";
        else
        {
            if(k-b<=a)
                cout<<b<<".000 "<<k-b<<".000 0.000 0.000\n";
            else if(k-b<=2*b)
            {
                if((k-b)%2==0)
                    cout<<b<<".000 "<<(k-b)/2<<".000 "<<(k-b)/2<<".000 0.000\n";
                else
                {
                    num=k-b;
                    cout<<b<<".000 "<<num/2<<"00 "<<num/2<<"00 0.000\n";
                }
            }
            else if(k-3*c<=0)
            {
                if(k%3==0)
                    cout<<k/3<<".000 "<<k/3<<".000 "<<k/3<<".000 0.000\n";
                else if(k%3==1)
                {
                    cout<<k/3<<".333 "<<k/3<<".333 "<<k/3<<".333 0.000\n";
                }
                else
                {
                    cout<<k/3<<".667 "<<k/3<<".667 "<<k/3<<".667 0.000\n";
                }
            }
            else if(k-3*c<=c)
            {
                cout<<c<<".000 "<<c<<".000 "<<c<<".000 "<<k-3*c<<".000\n";
            }
            else if(k%4==0)
                cout<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000\n";
            else if(k%4==2)
            {
                num=k;
                cout<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00\n";
            }
            else
            {
                num=k;
                cout<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0\n";
            }
        }
    }
    else if(sec==3)
    {
        if(k<=b)
            cout<<k<<".000 0.000 0.000 0.000\n";
        else
        {
            if(k<=2*b)
                cout<<b<<".000 "<<k-b<<".000 0.000 0.000\n";
            else if(k<=c*2)
            {
                if(k%2==0)
                {
                    cout<<k/2<<".000 "<<k/2<<".000 0.000 0.000\n";
                }
                else
                {
                    num=k;
                    cout<<num/2<<"00 "<<num/2<<"00 0.000 0.000\n";
                }
            }
            else if(k-c*2<=a)
            {
                cout<<c<<".000 "<<c<<".000 "<<k-2*c<<".000 0.000\n";
            }
            else if(k-c*2<=2*a)
            {
                cout<<c<<".000 "<<c<<".000 "<<a<<".000 "<<k-2*c-a<<".000\n";
            }
            else if(k-4*c<=0)
            {
                if((k-2*c)%2==0)
                {
                    cout<<c<<".000 "<<c<<".000 "<<(k-2*c)/2<<".000 "<<(k-2*c)/2<<".000\n";
                }
                else
                {
                    num=k-2*c;
                    cout<<c<<".000 "<<c<<".000 "<<num/2<<"00 "<<num/2<<"00\n";
                }
            }
            else if(k%4==0)
                cout<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000\n";
            else if(k%4==2)
            {
                num=k;
                cout<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00\n";
            }
            else
            {
                num=k;
                cout<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0\n";
            }
        }
    }
    else
    {
        if(k<=c)
            cout<<k<<".000 0.000 0.000 0.000\n";
        else
        {
            if(k-c<=a)
                cout<<c<<".000 "<<k-c<<".000 0.000 0.000\n";
            else if(k-c<=2*a)
                cout<<c<<".000 "<<a<<".000 "<<k-c-a<<".000 0.000\n";
            else if(k-c<=2*b)
            {
                if((k-c)%2==0)
                {
                    cout<<c<<".000 "<<(k-c)/2<<".000 "<<(k-c)/2<<".000 0.000\n";
                }
                else
                {
                    num=k-c;
                    cout<<c<<".000 "<<num/2<<"00 "<<num/2<<"00 0.000\n";
                }
            }
            else if(k-c-2*b<=b)
            {
                cout<<c<<".000 "<<b<<".000 "<<b<<".000 "<<k-c-2*b<<".000\n";
            }
            else if(k<=4*c)
            {
                if((k-c)%3==0)
                    cout<<c<<".000 "<<(k-c)/3<<".000 "<<(k-c)/3<<".000 "<<(k-c)/3<<".000\n";
                else if((k-c)%3==1)
                {
                    cout<<c<<".333 "<<(k-c)/3<<".333 "<<(k-c)/3<<".333 "<<(k-c)/3<<".333\n";
                }
                else
                {
                    cout<<c<<".000 "<<(k-c)/3<<".667 "<<(k-c)/3<<".667 "<<(k-c)/3<<".667\n";
                }
            }
            else if(k%4==0)
                cout<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000 "<<k/4<<".000\n";
            else if(k%4==2)
            {
                num=k;
                cout<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00 "<<num/4<<"00\n";
            }
            else
            {
                num=k;
                cout<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0 "<<num/4<<"0\n";
            }
        }
    }
    return 0;
}
