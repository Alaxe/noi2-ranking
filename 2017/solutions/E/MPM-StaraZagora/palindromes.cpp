#include <iostream>
using namespace std;

int main()
{
    int n,a,b,c,d,e,f,z;

    cin>>n;

    for(int x=n; x>=1; x--)
    {
        for(int y=n; y>=1; y--)
        {
            z=x*y;
            if(y-x>=0)
            {
                if(z-100000<0)
                {
                    if(z-10000<0)
                    {
                        if(z-1000<0)
                        {
                            if(z-100<0)
                            {
                                if(z-10<0)
                                {


                                }
                                else
                                {
                                    a=z%10;
                                    z=z/10;
                                    b=z%10;
                                    z=z/10;
                                    if(a==b)
                                    {
                                        cout<<x<<" "<<y<<endl;
                                        cout<<a<<b<<endl<<endl;
                                        return 0;
                                    }
                                }
                            }
                            else
                            {
                                a=z%10;
                                z=z/10;
                                b=z%10;
                                z=z/10;
                                c=z%10;
                                z=z/10;
                                if(a==c)
                                {
                                    cout<<x<<" "<<y<<endl;
                                    cout<<a<<b<<c<<endl<<endl;
                                    return 0;
                                }
                            }
                        }
                        else
                        {
                            a=z%10;
                            z=z/10;
                            b=z%10;
                            z=z/10;
                            c=z%10;
                            z=z/10;
                            d=z%10;
                            z=z/10;
                            if(a==d&&b==c)
                            {
                                cout<<x<<" "<<y<<endl;
                                cout<<a<<b<<c<<d<<endl<<endl;
                                return 0;
                            }

                        }
                    }
                    else
                    {
                        a=z%10;
                        z=z/10;
                        b=z%10;
                        z=z/10;
                        c=z%10;
                        z=z/10;
                        d=z%10;
                        z=z/10;
                        e=z%10;
                        z=z/10;
                        if(a==e&&b==d)
                        {
                            cout<<x<<" "<<y<<endl;
                            cout<<a<<b<<c<<d<<e<<endl<<endl;
                            return 0;
                        }
                    }
                }
                else
                {
                    a=z%10;
                    z=z/10;
                    b=z%10;
                    z=z/10;
                    c=z%10;
                    z=z/10;
                    d=z%10;
                    z=z/10;
                    e=z%10;
                    z=z/10;
                    f=z%10;
                    z=z/10;

                    if(a==f&&b==e&&c==d)
                    {
                        cout<<x<<" "<<y<<endl;
                        cout<<a<<b<<c<<d<<e<<f<<endl<<endl;
                        return 0;
                    }
                }
            }
            else
            {
                if(z-100000<0)
                {
                    if(z-10000<0)
                    {
                        if(z-1000<0)
                        {
                            if(z-100<0)
                            {
                                if(z-10<0)
                                {


                                }
                                else
                                {
                                    a=z%10;
                                    z=z/10;
                                    b=z%10;
                                    z=z/10;
                                    if(a==b)
                                    {
                                        cout<<y<<" "<<x<<endl;
                                        cout<<a<<b<<endl<<endl;
                                        return 0;
                                    }
                                }
                            }
                            else
                            {
                                a=z%10;
                                z=z/10;
                                b=z%10;
                                z=z/10;
                                c=z%10;
                                z=z/10;
                                if(a==c)
                                {
                                    cout<<y<<" "<<x<<endl;
                                    cout<<a<<b<<c<<endl<<endl;
                                    return 0;
                                }
                            }
                        }
                        else
                        {
                            a=z%10;
                            z=z/10;
                            b=z%10;
                            z=z/10;
                            c=z%10;
                            z=z/10;
                            d=z%10;
                            z=z/10;
                            if(a==d&&b==c)
                            {
                                cout<<y<<" "<<x<<endl;
                                cout<<a<<b<<c<<d<<endl<<endl;
                                return 0;
                            }

                        }
                    }
                    else
                    {
                        a=z%10;
                        z=z/10;
                        b=z%10;
                        z=z/10;
                        c=z%10;
                        z=z/10;
                        d=z%10;
                        z=z/10;
                        e=z%10;
                        z=z/10;
                        if(a==e&&b==d)
                        {
                            cout<<y<<" "<<x<<endl;
                            cout<<a<<b<<c<<d<<e<<endl<<endl;
                            return 0;
                        }
                    }
                }
                else
                {
                    a=z%10;
                    z=z/10;
                    b=z%10;
                    z=z/10;
                    c=z%10;
                    z=z/10;
                    d=z%10;
                    z=z/10;
                    e=z%10;
                    z=z/10;
                    f=z%10;
                    z=z/10;

                    if(a==f&&b==e&&c==d)
                    {
                        cout<<y<<" "<<x<<endl;
                        cout<<a<<b<<c<<d<<e<<f<<endl<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
