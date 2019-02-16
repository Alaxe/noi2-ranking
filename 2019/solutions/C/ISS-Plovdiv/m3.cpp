#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long S, k;
    long long a, b, c, d;
    long long a1=0, b1=0, c1=0, d1=0;
    cin>>S>>k;
    cin>>a>>b>>c>>d;
    long long ost=S%4;
    long long chas=S/4;
    if (chas>0)
    {
    if(ost==0)
        for (int i=1; i<=chas; i++)
    {
      if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=c) {a1=k;}
        else
        if (k<=c+a && k>c) { a1=c; b1=k-c;}
        else
            if(k<=c+2*a && k>a+c) { a1=c; b1=a; c1=k-c-a;}
            else
                if(k<=b*2+c && k>c+a*2) { a1=c; b1=(k-c)/2; c1=(k-c)/2;}
                else
                    if(k<=c+b*3 && k>c+b*2) { a1=c; b1=b; c1=b; d1=k-(c+b*2);}
                    else
                        if(k>c+b*3 && k<=4*c) { a1=c; b1=(k-c)/3; c1=(k-c)/3; d1=(k-c)/3;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                    k=0;
    }
    else k=k-d*4;
    }
    if (ost==1)
    {
        for (int i=1; i<=chas; i++)
    {
         if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=c) {a1=k;}
        else
        if (k<=c+a && k>c) { a1=c; b1=k-c;}
        else
            if(k<=c+2*a && k>a+c) { a1=c; b1=a; c1=k-c-a;}
            else
                if(k<=b*2+c && k>c+a*2) { a1=c; b1=(k-c)/2; c1=(k-c)/2;}
                else
                    if(k<=c+b*3 && k>c+b*2) { a1=c; b1=b; c1=b; d1=k-(c+b*2);}
                    else
                        if(k>c+b*3 && k<=4*c) { a1=c; b1=(k-c)/3; c1=(k-c)/3; d1=(k-c)/3;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    }
    if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    }
    if (ost==2)
    {
        for (int i=1; i<=chas; i++)
    {
                 if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=c) {a1=k;}
        else
        if (k<=c+a && k>c) { a1=c; b1=k-c;}
        else
            if(k<=c+2*a && k>a+c) { a1=c; b1=a; c1=k-c-a;}
            else
                if(k<=b*2+c && k>c+a*2) { a1=c; b1=(k-c)/2; c1=(k-c)/2;}
                else
                    if(k<=c+b*3 && k>c+b*2) { a1=c; b1=b; c1=b; d1=k-(c+b*2);}
                    else
                        if(k>c+b*3 && k<=4*c) { a1=c; b1=(k-c)/3; c1=(k-c)/3; d1=(k-c)/3;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    }
if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    }
    if (ost==3)
    {
        for (int i=1; i<=chas; i++)
    {
        if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=c) {a1=k;}
        else
        if (k<=c+a && k>c) { a1=c; b1=k-c;}
        else
            if(k<=c+2*a && k>a+c) { a1=c; b1=a; c1=k-c-a;}
            else
                if(k<=b*2+c && k>c+a*2) { a1=c; b1=(k-c)/2; c1=(k-c)/2;}
                else
                    if(k<=c+b*3 && k>c+b*2) { a1=c; b1=b; c1=b; d1=k-(c+b*2);}
                    else
                        if(k>c+b*3 && k<=4*c) { a1=c; b1=(k-c)/3; c1=(k-c)/3; d1=(k-c)/3;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else  k=k-d*4;
    }
        if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else  k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else  k=k-d*4;
    }
    }
    else
    {
    if(ost==1)
        {
           if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
        }
    if(ost==2)
    {
                if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else  k=k-d*4;
    }
    if(ost==3)
    {
             if (k<=d*4)
    {
        if (k<=a) {a1=k;}
        else
        if (k<=a*2 && k>a) { a1=a; b1=k-a;}
        else
            if(k<=c*2 && k>a*2) { a1=k/2; b1=k/2;}
            else
                if(k<=b+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+b*2 && k>c*2+b) { a1=c; b1=c; c1=b; d1=k-(c*2+b);}
                    else
                        if(k>c*2+b*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k>b && k<=b+a) { a1=b; b1=k-b;}
        else
            if(k<=b+a*2 && k>b+a) { a1=b; b1=a; c1=k-b-a;}
            else
                if(k<=b*3 && k>b+a*2) { a1=b; b1=(k-b)/2; c1=(k-2)/2;}
                else
                    if(k<=c*3 && k>b*3) { a1=k/3; b1=k/3; c1=k/3;}
                    else
                        if(k>c*3 && k<=4*c) { a1=c; b1=c; c1=c; d1=k-3*c;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                        k=0;
    }
    else k=k-d*4;
    if (k<=d*4)
    {
        if (k<=b) {a1=k;}
        else
        if (k<=b*2 && k>b) { a1=b; b1=k-b;}
        else
            if(k<=c*2 && k>b*2) { a1=k/2; b1=k/2;}
            else
                if(k<=a+c*2 && k>c*2) { a1=c; b1=c; c1=k-2*c;}
                else
                    if(k<=c*2+a*2 && k>c*2+a) { a1=c; b1=c; c1=a; d1=k-(c*2+a);}
                    else
                        if(k>c*2+a*2 && k<=4*c) { a1=c; b1=c; c1=(k-2*c)/2; d1=(k-2*c)/2;}
                        else
                        if(k>4*c) { a1=k/4; b1=k/4; c1=k/4; d1=k/4;}
                         k=0;
    }
    else k=k-d*4;
    }
    }
    cout<<a1<<".000 "<<b1<<".000 "<<c1<<".000 "<<d1<<".000"<<endl;


    return 0;
}
