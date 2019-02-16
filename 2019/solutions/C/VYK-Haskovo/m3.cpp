#include<iostream>
#include<iomanip>


using namespace std;

int s,k,a,b,c,d;
int Vsek;
double o[10];
int type;



int main()
{
    cin >> s >> k >> a >> b >> c >> d;

    if (4*s*d < k)
    {
        double y = k - s*4*d;
        y=y/s/4;
        cout<<fixed<<setprecision(3)<<d+y<<' ';
        cout<<fixed<<setprecision(3)<<d+y<<' ';
        cout<<fixed<<setprecision(3)<<d+y<<' ';
        cout<<fixed<<setprecision(3)<<d+y<<'\n';
        return 0;
    }
    Vsek = 4*d;
    int lastSek = k/Vsek + 1;
    k = k%Vsek;
    type = lastSek%4;
    if (type == 0) type =4;


    if(type == 1) /// a c b
    {
        if(k > c*4)
        {
            double y = k;
            o[0] = y/4;
            o[1] = y/4;
            o[2] = y/4;
            o[3] = y/4;
            k =0;
        }
        else{

        if(a>k){o[0] = k; k=0;}
        else
        {
            if(c*2<k)
            {
                o[0] = c; o[1] = c;
                k -= c*2;
            }
            else
            {
                if(k>a*2)
                {
                    double y =k;
                    o[0] = y/2;o[1] = y/2;
                    k=0;
                }
                else
                {
                    o[0] = a; k-=a;
                    o[1] = k; k = 0;
                }
            }

            if(k < b)
            {
                o[2] = k; k=0;
            }
            else
            {
                if(k > b*2)
                {
                    double y=k;
                    o[2] = y/2;
                    o[3] = y/2;
                    k=0;
                }
                else
                {
                    o[2] = b; k -=b;
                    o[3] = k; k =0;
                }
            }

        }
        }
    }


    else if(type == 2)
    {
        if(c*4 < k)
        {
            double y = k;
            o[0] = y/4;
            o[1] = y/4;
            o[2] = y/4;
            o[3] = y/4;
            k=0;
        }
        else{

        if(b<k) {o[0] = b; k-=b;}
        else {o[0] = k; k =0;}

        if(a<k) {o[1] = a; k-=a; }
        else {o[1] = k;k=0;}

        if(c*3 > o[1] + o[0] + k)
        {
            if(b*3 > o[1]+o[0]+k)
            {
                if(a*2 > o[0] + k)
                {
                    o[2] = k; k =0;
                }
                else
                {
                    o[2] = a; k -=a;
                    double y = k;
                    double x = y/2;
                    o[1] += x; o[2] +=x;
                    k =0;
                }
            }
            else
            {
                double y =k +  o[1]+o[0];
                o[0] = y/3;
                o[1] = y/3;
                o[2] = y/3;
                k=0;
            }
        }
        else
        {
            cout << k << '\n';
            k = o[1] + o[0] + k;
            o[0] = c; o[1] = c; o[2] = c;
            k -= c*3;
            o[3] = k; k =0;
        }
    }}


    else if(type == 3)
    {
        if(k > c*4)
        {
            double y = k;
            o[0] = y/4;
            o[1] = y/4;
            o[2] = y/4;
            o[3] = y/4;
            k =0;
        }
        else{

        if(b>k)
        {
            o[0] = k;k=0;
        }
        else
        {
            if (c*2 > k)
            {
                if(k>b*2)
                {
                    double y = k;
                    o[0] = y/2;
                    o[1] = y/2;
                    k =0;
                }
                else
                {
                    o[0] = b; k-=b;
                    o[1] = k; k=0;
                }
            }
            else
            {
                o[0] = c;
                o[1] = c;
                k-=c*2;
                if(k>a*2)
                {
                    double y = k; k =0;
                    o[2] = y/2;
                    o[3] = y/2;
                }
                else
                {
                    o[2] = a; k-=a;
                    o[3] = k; k =0;
                }
            }
        }

        }
    }



    else if(type == 4)
    {
        if(k > c*4)
        {
            double y = k;
            o[0] = y/4;
            o[1] = y/4;
            o[2] = y/4;
            o[3] = y/4;
            k =0;
        }
        else{

        if(k < c)
        {
            o[0] = k ; k =0;
        }
        else
        {
            o[0] = c; k-=c;
            if(k>b*3)
            {
                double y = k;
                k=0;
                o[1] = y/3;
                o[2] = y/3;
                o[3] = y/3;
            }
            else
            {
                if(k>b*2)
                {
                    o[1] = b;
                    o[2] = b;
                    k -= b*2;
                    o[3] = k; k =0;
                }
                else
                {
                    if(k<a)
                    {
                        o[1] = k; k = 0;
                    }
                    else
                    {
                        if(k <2*a)
                            {
                                o[1] = a; k-=a;
                                o[2] = k; k=0;
                            }
                        else
                        {
                            double x=k;
                            o[1] = x/2;
                            o[2] = x/2;
                            k =0;
                        }
                    }
                }
            }
        }


        }
    }


        cout  <<fixed << setprecision(3) << o[0]<< ' ';
        cout  <<fixed << setprecision(3) << o[1]<< ' ';
        cout  <<fixed << setprecision(3) << o[2]<< ' ';
        cout  <<fixed << setprecision(3) << o[3]<< '\n';


    return 0;
}
/*
3 25
1 2 3 5
*/
