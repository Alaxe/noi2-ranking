#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long s,k,a,b,c,d;
    cin >> s >> k >> a >> b >> c >> d;

    if(k>=s*4*d)
    {
        cout << d << ".000 " << d << ".000 " << d << ".000 " << d << ".000" << endl;
        return 0;
    }

    int p=k/(4*d);
    int q=k%(4*d);

    if(q==0)
    {
        cout << d << ".000 " << d << ".000 " << d << ".000 " << d << ".000" << endl;
        return 0;
    }

    p++;
    p=p%4;
    if(p==0) p=4;

    double n1=0,n2=0,n3=0,n4=0;
    if(p==1)
    {
        // a,c,b
        if(q<a)
        {
            n1=q;
            q=0;
        }
        else
        {
            n1=a;
            q=q-a;
        }
        if(q<a)
        {
            n2=q;
            q=0;
        }
        else
        {
            n2=a;
            q=q-a;
        }
        if(q<2*(c-a))
        {
            n1+=double(1.0*q/2);
            n2+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n1=c;
            n2=c;
            q=q-2*(c-a);
        }
        if(q<b)
        {
            n3=q;
            q=0;
        }
        else
        {
            n3=b;
            q=q-b;
        }
        if(q<b)
        {
            n4=q;
            q=0;
        }
        else
        {
            n4=b;
            q=q-b;
        }
        if(q<2*(c-b))
        {
            n3+=double(1.0*q/2);
            n4+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n3=c;
            n4=c;
            q=q-2*(c-b);
        }
        n1+=double(1.0*q/4);
        n2+=double(1.0*q/4);
        n3+=double(1.0*q/4);
        n4+=double(1.0*q/4);

        cout << fixed << setprecision(3) << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    }
    else if(p==2)
    {
        // b,a,c
        if(q<b)
        {
            n1=q;
            q=0;
        }
        else
        {
            n1=b;
            q=q-b;
        }
        if(q<a)
        {
            n2=q;
            q=0;
        }
        else
        {
            n2=a;
            q=q-a;
        }
        if(q<a)
        {
            n3=q;
            q=0;
        }
        else
        {
            n3=a;
            q=q-a;
        }
        if(q<2*(b-a))
        {
            n2+=double(1.0*q/2);
            n3+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n2=b;
            n3=b;
            q=q-2*(b-a);
        }
        if(q<3*(c-b))
        {
            n1+=double(1.0*q/3);
            n2+=double(1.0*q/3);
            n3+=double(1.0*q/3);
            q=0;
        }
        else
        {
            n1=c;
            n2=c;
            n3=c;
            q=q-3*(c-b);
        }
        if(q<c)
        {
            n4=q;
            q=0;
        }
        else
        {
            n4=c;
            q=q-c;
        }
        n1+=double(1.0*q/4);
        n2+=double(1.0*q/4);
        n3+=double(1.0*q/4);
        n4+=double(1.0*q/4);

        cout << fixed << setprecision(3) << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    }
    else if(p==3)
    {
        // b,c,a
        if(q<b)
        {
            n1=q;
            q=0;
        }
        else
        {
            n1=b;
            q=q-b;
        }
        if(q<b)
        {
            n2=q;
            q=0;
        }
        else
        {
            n2=b;
            q=q-b;
        }
        if(q<2*(c-b))
        {
            n1+=double(1.0*q/2);
            n2+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n1=c;
            n2=c;
            q=q-2*(c-b);
        }
        if(q<a)
        {
            n3=q;
            q=0;
        }
        else
        {
            n3=a;
            q=q-a;
        }
        if(q<a)
        {
            n4=q;
            q=0;
        }
        else
        {
            n4=a;
            q=q-a;
        }
        if(q<2*(c-a))
        {
            n3+=double(1.0*q/2);
            n4+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n3=c;
            n4=c;
            q=q-2*(c-a);
        }
        n1+=double(1.0*q/4);
        n2+=double(1.0*q/4);
        n3+=double(1.0*q/4);
        n4+=double(1.0*q/4);

        cout << fixed << setprecision(3) << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    }
    else if(p==4)
    {
        // c,a,b
        if(q<c)
        {
            n1=q;
            q=0;
        }
        else
        {
            n1=c;
            q=q-c;
        }
        if(q<a)
        {
            n2=q;
            q=0;
        }
        else
        {
            n2=a;
            q=q-a;
        }
        if(q<a)
        {
            n3=q;
            q=0;
        }
        else
        {
            n3=a;
            q=q-a;
        }
        if(q<2*(b-a))
        {
            n2+=double(1.0*q/2);
            n3+=double(1.0*q/2);
            q=0;
        }
        else
        {
            n2=b;
            n3=b;
            q=q-2*(b-a);
        }
        if(q<b)
        {
            n4=q;
            q=0;
        }
        else
        {
            n4=b;
            q=q-b;
        }
        if(q<3*(c-b))
        {
            n2+=double(1.0*q/3);
            n3+=double(1.0*q/3);
            n4+=double(1.0*q/3);
            q=0;
        }
        else
        {
            n2=c;
            n3=c;
            n4=c;
            q=q-3*(c-b);
        }
        n1+=double(1.0*q/4);
        n2+=double(1.0*q/4);
        n3+=double(1.0*q/4);
        n4+=double(1.0*q/4);

        cout << fixed << setprecision(3) << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    }

    return 0;
}
