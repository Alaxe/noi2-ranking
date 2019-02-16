#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s,a,d;
    long long k,c,b;
    cin>>s>>k>>a>>b>>c>>d;
    int i,m;
    double x[4]= {0};
    if(4*d*s<=k)
    {
        x[0]=k/(4*s);
        cout<<setprecision(4)<<x[0]<<" ";
        cout<<setprecision(4)<<x[0]<<" ";
        cout<<setprecision(4)<<x[0]<<" ";
        cout<<setprecision(4)<<x[0]<<endl;
    }
    else
    {
        m=k/(4*d);
        k=k-(m*4*d);
        if(k==0)
        {
            x[0]=d;
            cout<<setprecision(4)<<x[0]<<".000 ";
            cout<<setprecision(4)<<x[0]<<".000 ";
            cout<<setprecision(4)<<x[0]<<".000 ";
            cout<<setprecision(4)<<x[0]<<".000"<<endl;
        }
        else
        {
            if(m%4==0)
            {
                if(k<=a)
                {
                    x[1]=k;
                    x[0]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                }
                else if(k<=2*c)
                {
                    x[1]=k/2.0;
                    x[0]=0;
                    if(k%2==0)
                    {
                        cout<<setprecision(4)<<x[1]<<".000 ";
                        cout<<setprecision(4)<<x[1]<<".000 ";
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[1]<<"00 ";
                        cout<<setprecision(4)<<x[1]<<"00 ";
                    }
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                }
                else if((k-2*c)<=b)
                {
                    x[1]=c;
                    x[2]=k-2*c;
                    x[0]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                }
                else if((k-2*c)<=2*c)
                {
                    x[1]=c;
                    x[2]=(k-2*c)/2.0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    if((k-2*c)%2==0)
                    {
                        cout<<setprecision(4)<<x[2]<<".000 ";
                        cout<<setprecision(4)<<x[2]<<".000"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[2]<<"00 ";
                        cout<<setprecision(4)<<x[2]<<"00"<<endl;
                    }
                }
                else
                {
                    x[0]=k/4.0;
                    if(k%4==0)
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000"<<endl;
                    }
                    else if(k%4==2)
                    {
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0"<<endl;
                    }
                }
            }
///xddddddddddddddddddddddddddddd
            else if(m%4==1)
            {
                if(k<=b)
                {
                    x[1]=k;
                    x[0]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 "<<endl;
                }
                else if(k-b<=a)
                {
                    x[1]=b;
                    x[0]=k-b;
                    x[2]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 "<<endl;
                }
                else if((k-b-a)<=a)
                {
                    x[1]=b;
                    x[2]=a;
                    x[0]=k-b-a;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000 "<<endl;
                }
                else if((k-b)<=2*c)
                {
                    x[1]=b;
                    x[2]=(k-b)/2.0;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    if((k-b)%2==0)
                    {
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    }
                    else
                    {
                       cout<<setprecision(4)<<x[2]<<"00 ";
                    cout<<setprecision(4)<<x[2]<<"00 ";
                    }
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if(k<=3*c)
                {
                    x[0]=k/3;
                    x[1]=0;
                    if(k%3!=0)
                    {
                    cout<<setprecision(4)<<x[0]<<" ";
                    cout<<setprecision(4)<<x[0]<<" ";
                    cout<<setprecision(4)<<x[0]<<" ";
                    cout<<setprecision(4)<<x[1]<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000"<<endl;
                    }
                }
                else
                {
                    x[0]=k/4.0;
                    if(k%4==0)
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000"<<endl;
                    }
                    else if(k%4==2)
                    {
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0"<<endl;
                    }
                }
            }
///xddddddddddddddddddddddddddddddddddddddddddddddd
            else if(m%4==2)
            {
                if(k<=b)
                {
                    x[1]=k;
                    x[0]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                }
                else if(k-b<=b)
                {
                    x[1]=b;
                    x[0]=k-b;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if(k<=2*c)
                {
                    x[1]=k/2.0;
                    x[0]=0;
                    if(k%2==0)
                    {
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[1]<<"00 ";
                    cout<<setprecision(4)<<x[1]<<"00 ";
                    cout<<setprecision(4)<<x[0]<<"00 ";
                    cout<<setprecision(4)<<x[0]<<"00"<<endl;
                    }
                }
                else if((k-2*c)<=a)
                {
                    x[1]=c;
                    x[2]=k-2*c;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if(k-2*c-a<=a)
                {
                    x[0]=c;
                    x[1]=a;
                    x[2]=k-2*c-a;
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000"<<endl;
                }
                else if(k-2*c<=2*c)
                {
                    x[0]=c;
                    x[1]=k/2.0-c;
                    if(k%2==0)
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<"00 ";
                    cout<<setprecision(4)<<x[0]<<"00 ";
                    cout<<setprecision(4)<<x[1]<<"00 ";
                    cout<<setprecision(4)<<x[1]<<"00"<<endl;
                    }
                }
                else
                {
                    x[0]=k/4.0;
                    if(k%4==0)
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000"<<endl;
                    }
                    else if(k%4==2)
                    {
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0"<<endl;
                    }
                }
            }
///xddddddddddddddddddddddddddddd
            else

            {
                if(k<=c)
                {
                    x[1]=k;
                    x[0]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000"<<endl;
                }
                else if(k-c<=a)
                {
                    x[1]=c;
                    x[0]=k-c;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if((k-c-a)<=a)
                {
                    x[1]=c;
                    x[2]=a;
                    x[0]=k-c-a;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 ";
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if(k-c<=2*b)
                {
                    x[1]=c;
                    x[2]=(k-c)/2.0;
                    x[3]=0;
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    if((k-c)%2==0)
                    {
                        cout<<setprecision(4)<<x[2]<<".000 ";
                        cout<<setprecision(4)<<x[2]<<".000 ";
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[2]<<"00 ";
                        cout<<setprecision(4)<<x[2]<<"00 ";
                    }
                    cout<<setprecision(4)<<x[3]<<".000"<<endl;
                }
                else if(k-c-2*b<=b)
                {
                    x[0]=c;
                    x[1]=b;
                    x[2]=k-c-2*b;
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[2]<<".000 "<<endl;
                }
                else if(k-c<=3*c)
                {
                    x[0]=c;
                    x[1]=(k-c)/3;
                    cout<<setprecision(4)<<x[0]<<".000 ";
                    if(k%3!=0)
                    {
                    cout<<setprecision(4)<<x[1]<<" ";
                    cout<<setprecision(4)<<x[1]<<" ";
                    cout<<setprecision(4)<<x[1]<<endl;
                    }
                    else
                    {
                         cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000 ";
                    cout<<setprecision(4)<<x[1]<<".000"<<endl;
                    }
                }
                else
                {
                    x[0]=k/4.0;
                    if(k%4==0)
                    {
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000 ";
                        cout<<setprecision(4)<<x[0]<<".000"<<endl;
                    }
                    else if(k%4==2)
                    {
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00 ";
                        cout<<setprecision(4)<<x[0]<<"00"<<endl;
                    }
                    else
                    {
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0 ";
                        cout<<setprecision(4)<<x[0]<<"0"<<endl;
                    }
                }
            }
        }
    }
}
