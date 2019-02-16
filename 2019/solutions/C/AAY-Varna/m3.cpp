#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a,b,c,d;
    float s;
    long long k;
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    if(s*d*4<=k)
    {
        float tmp=float(k-s*d*4)/float(4*s)+float(d);
        cout<<fixed<<setprecision(3)<<tmp<<" "<<tmp<<" "<<tmp<<" "<<tmp<<endl;
        return 0;
    }
    int filled=k/(d*4);
    float water=k-(d*4)*filled;
    if((filled%4+1)==1)
    {
        if(water<=a)
        {
            cout<<fixed<<setprecision(3)<<water<<" "<<"0.000"<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*a))
        {
            cout<<fixed<<setprecision(3)<<a<<" "<<water-a<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(c*2))
        {
            cout<<fixed<<setprecision(3)<<water/2<<" "<<water/2<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*c+b))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<water-(2*c)<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*c+2*b))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<b<<" "<<water-(2*c)-b<<endl;
            return 0;
        }
        if(water<=(4*c))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<(water-2*c)/2<<" "<<(water-2*c)/2<<endl;
        }
        cout<<fixed<<setprecision(3)<<water/4<<" "<<water/4<<" "<<water/4<<" "<<water/4<<endl;
        return 0;
    }
    else if((filled%4+1)==2)
    {
        if(water<=b)
        {
            cout<<fixed<<setprecision(3)<<water<<" "<<"0.000"<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(b+a))
        {
            cout<<fixed<<setprecision(3)<<b<<" "<<water-b<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(b+2*a))
        {
            cout<<fixed<<setprecision(3)<<b<<" "<<a<<" "<<water-b-a<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(3*b))
        {
            cout<<fixed<<setprecision(3)<<b<<" "<<(water-b)/2<<" "<<(water-b)/2<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(3*c))
        {
            cout<<fixed<<setprecision(3)<<water/3<<" "<<water/3<<" "<<water/3<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(4*c))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<c<<" "<<water-(3*c)<<endl;
            return 0;
        }
        cout<<fixed<<setprecision(3)<<water/4<<" "<<water/4<<" "<<water/4<<" "<<water/4<<endl;
        return 0;
    }
    else if((filled%4+1)==3)
    {
        if(water<=b)
        {
            cout<<fixed<<setprecision(3)<<water<<" "<<"0.000"<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*b))
        {
            cout<<fixed<<setprecision(3)<<b<<" "<<water-b<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*c))
        {
            cout<<fixed<<setprecision(3)<<water/2<<" "<<water/2<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*c+a))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<water-(2*c)<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(2*c+2*a))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<a<<" "<<water-(2*c)-a<<endl;
            return 0;
        }
        if(water<=(4*c))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<c<<" "<<(water-(2*c))/2<<" "<<(water-(2*c))/2<<endl;
            return 0;
        }
        cout<<fixed<<setprecision(3)<<water/4<<" "<<water/4<<" "<<water/4<<" "<<water/4<<endl;
        return 0;
    }
    if((filled%4+1)==0)
    {
        if(water<=c)
        {
            cout<<fixed<<setprecision(3)<<water<<" "<<"0.000"<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(c+a))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<water-c<<" "<<"0.000"<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(c+2*a))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<a<<" "<<water-c-a<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(c+2*b))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<(water-c)/2<<" "<<(water-c)/2<<" "<<"0.000"<<endl;
            return 0;
        }
        if(water<=(c+3*b))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<b<<" "<<b<<" "<<water-(2*c)-b<<endl;
            return 0;
        }
        if(water<=(4*c))
        {
            cout<<fixed<<setprecision(3)<<c<<" "<<(water-c)/3<<" "<<(water-c)/3<<" "<<(water-c)/3<<endl;
            return 0;
        }
        cout<<fixed<<setprecision(3)<<water/4<<" "<<water/4<<" "<<water/4<<" "<<water/4<<endl;
        return 0;
    }


}
