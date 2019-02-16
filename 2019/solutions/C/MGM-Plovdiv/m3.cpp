#include <bits/stdc++.h>
using namespace std;
long long s, k, a, b, c, d, l, sec;
double m;
void f()
{
    if(sec==1)
    {
        if(l<=a)
        {
            printf("%.3f", double(l));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*a)
        {
            printf("%.3f", double(a));
            printf(" ");
            printf("%.3f", double(a-l));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*c)
        {
            m=double(l)/2;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*c+b)
        {
            m=l-2*c;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*(c+b))
        {
            m=l-2*c-b;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", m);
            return;
        }
        if(l<=4*c)
        {
            m=double(l-2*c)/2;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
        else
        {
            m=double(l)/4;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
    }
    if(sec==2)
    {
        if(l<=b)
        {
            printf("%.3f", double(l));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=(b+a))
        {
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", double(l-b));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=b+2*a)
        {
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", double(a));
            printf(" ");
            printf("%.3f", double(l-a-b));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=3*b)
        {
            m=double(l-b)/2;
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double (0));
            return;
        }
        if(l<=3*c)
        {
            m=double(l)/3;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=4*c)
        {
            m=double(l)-double(c)*3;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            return;
        }
        else
        {
            m=double(l)/4;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
    }
    if(sec==3)
    {
        if(l<=b)
        {
            printf("%.3f", double(l));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*b)
        {
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", double(l-b));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*c)
        {
            m=double(l)/2;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*c+a)
        {
            m=double(l)-2*double(c);
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=2*(a+c))
        {
             m=double(l)-2*double(c)-double(a);
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(a));
            printf(" ");
            printf("%.3f", m);
            return;

        }
        if(l<=4*c)
        {
            m=(double(l)-2*double(c))/2;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
        else
        {
            m=double(l)/4;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
    }
    else
    {
        if(l<=c)
        {
            printf("%.3f", double(l));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=c+a)
        {
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(l-c));
            printf(" ");
            printf("%.3f", double(0));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=c+2*a)
        {
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(a));
            printf(" ");
            printf("%.3f", double(l-c-a));
            printf(" ");
            printf("%.3f", double(0));
            return;
        }
        if(l<=c+2*b)
        {
            m=(double(l)-c)/2;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", double(0));
            return;

        }
        if(l<=c+3*b)
        {
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", double(b));
            printf(" ");
            printf("%.3f", double(l-c-b-b));
            return;
        }
        if(l<=4*c)
        {
            m=(double(l)-double(c))/3;
            printf("%.3f", double(c));
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;
        }
        else
        {
            m=double(l)/4;
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            printf(" ");
            printf("%.3f", m);
            return;

        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>k;
    cin>>a>>b>>c>>d;

    l=k%(4*d);
    if(((k-l)/(4*d))%4==0)
        sec=1;
    else  if(((k-l)/(4*d))%4==1)
        sec=2;
    else  if(((k-l)/(4*d))%4==2)
        sec=3;
    else
        sec=4;

    if(l==0)
    {
        printf("%.3f", double(d));
        printf(" ");
        printf("%.3f", double(d));
        printf(" ");
        printf("%.3f", double(d));
        printf(" ");
        printf("%.3f", double(d));
        return 0;
    }

    if(k>s*4*d)
    {
        m=double(k)/double(s)/4;
        printf("%.3f", m);
        printf(" ");
        printf("%.3f", m);
        printf(" ");
        printf("%.3f", m);
        printf(" ");
        printf("%.3f", m);
        return 0;
    }
    f();
    return 0;
}
