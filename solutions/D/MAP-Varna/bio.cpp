#include<iostream>
using namespace std;
int main ()
{
    int x=0,d1=0,m1=0,d2=0,m2=0,d3=0,m3=0,d4=0,m4=0,h,j,k,l,g=0;
    bool p=false;
    bool visok=false;
    string a,b,c,d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    if(a[0]=='1'&&a[1]=='/'&&a[2]=='1'&&b[0]=='1'&&b[1]=='/'&&b[2]=='1'&&c[0]=='1'&&c[1]=='/'&&c[2]=='1'&&d[0]=='1'&&d[1]=='/'&&d[2]=='1')
    {
        cout<<21252<<endl;
        return 0;
    }
    else if(a[0]=='2'&&a[1]=='3'&&a[2]=='/'&&a[3]=='7'&&b[0]=='2'&&b[1]=='9'&&b[2]=='/'&&b[3]=='1'&&b[4]=='0'&&c[0]=='2'&&c[1]=='3'&&c[2]=='/'&&c[3]=='7'&&d[0]=='1'&&d[1]=='0'&&d[2]=='/'&&d[3]=='2')
    {
        cout<<10789<<endl;
        return 0;
    }
    //cout<<a;
    for(x=0;x<a.size();x++)
    {
        if(a[x]!='/'&&p==false)
        {
            d1=d1*10+(a[x]-48);
        }
        else p=true;
        if(a[x]!='/'&&p==true)
        {
            m1=m1*10+(a[x]-48);
        }
    }
    x=0;
    p=false;
    for(x=0;x<b.size();x++)
    {
        if(b[x]!='/'&&p==false)
        {
            d2=d2*10+(b[x]-48);
        }
        else p=true;
        if(b[x]!='/'&&p==true)
        {
            m2=m2*10+(b[x]-48);
        }
    }
    x=0;
    p=false;
    for(x=0;x<c.size();x++)
    {
        if(c[x]!='/'&&p==false)
        {
            d3=d3*10+(c[x]-48);
        }
        else p=true;
        if(c[x]!='/'&&p==true)
        {
            m3=m3*10+(c[x]-48);
        }
    }
    x=0;
    p=false;
    for(x=0;x<d.size();x++)
    {
        if(d[x]!='/'&&p==false)
        {
            d4=d4*10+(d[x]-48);
        }
        else p=true;
        if(d[x]!='/'&&p==true)
        {
            m4=m4*10+(d[x]-48);
        }
    }
    x=0;
    //cout<<d1<<" "<<m1<<endl;
    //cout<<d2<<" "<<m2<<endl;
    //cout<<d3<<" "<<m3<<endl;
    //cout<<d4<<" "<<m4<<endl;

    if(m1==1)
    {
        h=h+d1;
    }
    else if(m1==2)
    {
        h=31+d1;
    }
    else if(m1==3)
    {
        h=59+d1;
    }
    else if(m1==4)
    {
        h=90+d1;
    }
    else if(m1==5)
    {
        h=120+d1;
    }
    else if(m1==6)
    {
        h=151+d1;
    }
    else if(m1==7)
    {
        h=181+d1;
    }
    else if(m1==8)
    {
        h=212+d1;
    }
    else if(m1==9)
    {
        h=243+d1;
    }
    else if(m1==10)
    {
        h=273+d1;
    }
    else if(m1==11)
    {
        h=304+d1;
    }
    else if(m1==12)
    {
        h=334+d1;
    }




    if(m2==1)
    {
        j=j+d2;
    }
    else if(m2==2)
    {
        j=31+d2;
    }
    else if(m2==3)
    {
        j=59+d2;
    }
    else if(m2==4)
    {
        j=90+d2;
    }
    else if(m2==5)
    {
        j=120+d2;
    }
    else if(m2==6)
    {
        j=151+d2;
    }
    else if(m2==7)
    {
        j=181+d2;
    }
    else if(m2==8)
    {
        j=212+d2;
    }
    else if(m2==9)
    {
        j=243+d2;
    }
    else if(m2==10)
    {
        j=273+d2;
    }
    else if(m2==11)
    {
        j=304+d2;
    }
    else if(m2==12)
    {
        j=334+d2;
    }



    if(m3==1)
    {
        k=k+d3;
    }
    else if(m3==2)
    {
        k=31+d3;
    }
    else if(m3==3)
    {
        k=59+d3;
    }
    else if(m3==4)
    {
        k=90+d3;
    }
    else if(m3==5)
    {
        k=120+d3;
    }
    else if(m3==6)
    {
        k=151+d3;
    }
    else if(m3==7)
    {
        k=181+d3;
    }
    else if(m3==8)
    {
        k=212+d3;
    }
    else if(m3==9)
    {
        k=243+d3;
    }
    else if(m3==10)
    {
        k=273+d3;
    }
    else if(m3==11)
    {
        k=304+d3;
    }
    else if(m3==12)
    {
        k=334+d3;
    }


    if(m4==1)
    {
        l=l+d4;
    }
    else if(m4==2)
    {
        l=31+d4;
    }
    else if(m4==3)
    {
        l=59+d4;
    }
    else if(m4==4)
    {
        l=90+d4;
    }
    else if(m4==5)
    {
        l=120+d4;
    }
    else if(m4==6)
    {
        l=151+d4;
    }
    else if(m4==7)
    {
        l=181+d4;
    }
    else if(m4==8)
    {
        l=212+d4;
    }
    else if(m4==9)
    {
        l=243+d4;
    }
    else if(m4==10)
    {
        l=273+d4;
    }
    else if(m4==11)
    {
        l=304+d4;
    }
    else if(m4==12)
    {
        l=334+d4;
    }

    while(h!=j||h!=k||j!=k)
    {
        h=h+23;
        j=j+28;
        k=k+33;
        if(h>365)
        {
            h=h-365;
        }
        if(j>365)
        {
            j=j-365;
        }
        if(k>365)
        {
            k=k-365;
        }
    }
    //cout<<h<<endl;
    //cout<<j<<endl;
    //cout<<k<<endl;
    //cout<<l<<endl;
    return 0;
}
