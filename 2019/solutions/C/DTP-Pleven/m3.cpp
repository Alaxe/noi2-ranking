#include<iostream>
#include<iomanip>
using namespace std;
long long i,j,p,q,sa,sb,sc,sd,l,r,n;
double t,k,a,b,c,d;
int main()
{
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    if(k>=4*d*n)
    {
        t=4*n;
        cout<<fixed<<setprecision(3)<<k/t<<" "<<k/t<<" "<<k/t<<" "<<k/t;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(i%4==1)
        {
            if(k>a)
            {
                k-=a;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<t<<" "<<0.000<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k+=a;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<a<<" "<<t<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>2*c)
            {
                k-=2*c;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<k/(2)<<" "<<k/(2)<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>b)
            {
                k-=b;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<t<<" "<<0.000;
                return 0;
            }
            if(k>b)
            {
                k+=b;//cout<<k<<endl;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<b<<" "<<t;
                return 0;
            }
            if(k>2*c)
            {
                //cout<<k<<endl;
                k+=2*c;
            }
            else
            {
                t=k/(2);
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<t<<" "<<t;
                return 0;
            }
            if(k>4*d)
            {

                k-=4*d;//cout<<k<<endl;
            }
            else
            {
                t=k/4;
                cout<<fixed<<setprecision(3)<<t<<" "<<t<<" "<<t<<" "<<t;
                return 0;
            }
        }
        else if(i%4==2)
        {
            if(k>b)
            {
                k-=b;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<t<<" "<<0.000<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k-=a;
            }
            else
            {
                t=k;
                cout<<fixed<<setprecision(3)<<b<<" "<<t<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k+=a;
            }
            else
            {
                t=k;
                cout<<fixed<<setprecision(3)<<b<<" "<<a<<" "<<t<<" "<<0.000;
                return 0;
            }
            if(k>2*b)
            {
                k+=b;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<b<<" "<<k/2<<" "<<k/2<<" "<<0.000;
                return 0;
            }
            if(k>3*c)
            {
                k-=3*c;
            }
            else
            {
                t=k/3;
                cout<<fixed<<setprecision(3)<<t<<" "<<t<<" "<<t<<" "<<0.000;
                return 0;
            }
            if(k>c)
            {
                k+=3*c;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<c<<" "<<k;
                return 0;
            }
            if(k>4*d)
            {
                k-=4*d;
            }
            else
            {
                t=k/4;
                cout<<fixed<<setprecision(3)<<t<<" "<<t<<" "<<t<<" "<<t;
                return 0;
            }
        }
        else if(i%4==3)
        {
            if(k>b)
            {
                k-=b;//cout<<k<<endl;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<t<<" "<<0.000<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>b)
            {
                k+=b;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<b<<" "<<k<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>2*c)
            {
                k-=2*c;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<k/2<<" "<<k/2<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k-=a;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<k<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k+=a;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<a<<" "<<k;
                return 0;
            }
            if(k>2*c)
            {
                k+=2*c;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<k/2<<" "<<k/2;
                return 0;
            }
            if(k>4*d)
            {
                //cout<<k<<endl;
                k-=4*d;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<k/4<<" "<<k/4<<" "<<k/4<<" "<<k/4;
                return 0;
            }
        }
        else
        {
            //cout<<k<<endl;
            if(k>c)
            {
                k-=c;
            }
            else
            {
                t=k/1;
                cout<<fixed<<setprecision(3)<<t<<" "<<0.000<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                k-=a;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<k<<" "<<0.000<<" "<<0.000;
                return 0;
            }
            if(k>a)
            {
                //cout<<k<<endl;
                k+=a;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<a<<" "<<k<<" "<<0.000;
                return 0;
            }
            if(k>2*b)
            {
                k-=2*b;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<k/2<<" "<<k/2<<" "<<0.000;
                return 0;
            }
            if(k>b)
            {
                k+=2*b;
                //cout<<k<<endl;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<b<<" "<<b<<" "<<k;
                return 0;
            }
            if(k>3*c)
            {
                k+=c;
            }
            else
            {
                cout<<fixed<<setprecision(3)<<c<<" "<<k/3<<" "<<k/3<<" "<<k/3;
                return 0;
            }
            if(k>4*d)
            {
                k-=4*d;
            }
            else
            {
                //cout<<k<<endl;
                cout<<fixed<<setprecision(3)<<k/4<<" "<<k/4<<" "<<k/4<<" "<<k/4;
                return 0;
            }
        }
    }
    return 0;
}
/*
3 19
1 2 3 5

3 45 1 2 3 5
*/
