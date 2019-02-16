#include <iostream>
using namespace std;

int s,a,b,c,d;
long long k;



int main()
{
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    if(k >= d*4*s){
        if(k%(4*s) != 0){
            double r = k/(4*s);
            cout<<r<<" "<<r<<" "<<r<<" "<<r<<endl;
        }
        else{
            int r = k/(4*s);
            cout<<r<<".000 "<<r<<".000 "<<r<<".000 "<<r<<".000"<<endl;
        }
        return 0;
    }
    int p; p = 4*d;
    int q; q = k/p;
    int ostl;  ostl = k%p;
    q++;  q = q%4;
    if(q==0)q=4;
   // cout<<q<<" "<<ostl<<endl;
    if(q == 2){
        if(ostl <= b)cout<<ostl<<".000 0.000 0.000 0.000"<<endl;
        else
        if(ostl <= b+a)cout<<b<<".000 "<<ostl-b<<".000 0.000 0.000"<<endl;
        else
        if(ostl <= 3*b){
            cout<<b<<".000 ";
            int p;
            p = ostl - b;
            if(p%2 == 0)cout<<p/2<<".000 "<<p/2<<".000 0.000"<<endl;
            else
                cout<<p/2<<".500 "<<p/2<<".500 0.000"<<endl;
        }
        else
        if(ostl <= 3*c){
            if(ostl%3 == 0)cout<<ostl/3<<".000 "<<ostl/3<<".000 "<<ostl/3<<".000 0.000"<<endl;
            if(ostl%3 == 1)cout<<ostl/3<<".333 "<<ostl/3<<".333 "<<ostl/3<<".333 0.000"<<endl;
            if(ostl%3 == 2)cout<<ostl/3<<".667 "<<ostl/3<<".667 "<<ostl/3<<".667 0.000"<<endl;
        }
        else
        if(ostl <= 4*c)cout<<c<<".000 "<<c<<".000 "<<c<<".000 "<<ostl- 3*c<<".000"<<endl;
        else{
            if(ostl%4 == 0)cout<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000"<<endl;
            if(ostl%4 == 1)cout<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250"<<endl;
            if(ostl%4 == 2)cout<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500"<<endl;
            if(ostl%4 == 3)cout<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750"<<endl;
        }
        return 0;
    }
    if(q == 1){
        if(ostl <= a)cout<<ostl<<".000 0.000 0.000 0.000"<<endl;
        else
        if(ostl <= 2*a)cout<<a<<".000 "<<ostl - a<<".000 0.000 0.000"<<endl;
        else
        if(ostl <= 2*c){
            if(ostl%2 == 0)cout<<ostl/2<<".000 "<<ostl/2<<".000 0.000 0.000"<<endl;
            else
                cout<<ostl/2<<".500 "<<ostl/2<<".500 0.000 0.000"<<endl;
        }
        else
        if(ostl <= 2*c+b)cout<<c<<".000 "<<c<<".000 "<<ostl - 2*c<<".000 0.000"<<endl;
        else
        if(ostl <= 2*c+2*b)cout<<c<<".000 "<<c<<".000 "<<b<<".000 "<<ostl -2*c-b<<".000"<<endl;
        else
        if(ostl <= 4*c){
            cout<<c<<".000 "<<c<<".000 ";
            int p;
            p = ostl - 2*c;
            if(p%2 == 0)cout<<p/2<<".000 "<<p/2<<".000"<<endl;
            else
                cout<<p/2<<".500 "<<p/2<<".500"<<endl;

        }
        else{
            if(ostl%4 == 0)cout<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000"<<endl;
            if(ostl%4 == 1)cout<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250"<<endl;
            if(ostl%4 == 2)cout<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500"<<endl;
            if(ostl%4 == 3)cout<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750"<<endl;
        }
        return 0;

    }
    if(q == 3){
        if(ostl<=b)cout<<ostl<<".000 0.000 0.000 0.000"<<endl;
        else
        if(ostl <= 2*b)cout<<b<<".000 "<<ostl-b<<".000 0.000 0.000"<<endl;
        else
        if(ostl <= 2*c){
            if(ostl%2 == 0)cout<<ostl/2<<".000 "<<ostl/2<<".000 0.000 0.000"<<endl;
            else
                cout<<ostl/2<<".500 "<<ostl/2<<".500 0.000 0.000"<<endl;
        }
        else
        if(ostl <= 2*c+a)cout<<c<<".000 "<<c<<".000 "<<ostl - 2*c<<".000 0.000"<<endl;
        else
        if(ostl <= 2*c+2*a)cout<<c<<".000 "<<c<<".000 "<<a<<".000 "<<ostl -2*c-a<<".000"<<endl;
        else
        if(ostl <= 4*c){
            cout<<c<<".000 "<<c<<".000 ";
            int p;
            p = ostl - 2*c;
            if(p%2 == 0)cout<<p/2<<".000 "<<p/2<<".000"<<endl;
            else
                cout<<p/2<<".500 "<<p/2<<".500"<<endl;
        }
        else{
            if(ostl%4 == 0)cout<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000"<<endl;
            if(ostl%4 == 1)cout<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250"<<endl;
            if(ostl%4 == 2)cout<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500"<<endl;
            if(ostl%4 == 3)cout<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750"<<endl;
        }


    }
    if(q == 4){
        if(ostl <= c)cout<<ostl<<".000 0.000 0.000 0.000"<<endl;
        else
        if(ostl <= c+a)cout<<c<<".000 "<<ostl-c<<".000 0.000 0.000"<<endl;
        else
        if(ostl <= c+2*a)cout<<c<<".000 "<<a<<".000 "<<ostl-c-a<<".000 0.000"<<endl;
        else
        if(ostl <= c+2*b){
            cout<<c<<".000 ";
            int p = ostl - c;
            if(p%2 == 0)cout<<p/2<<".000 "<<p/2<<".000 0.000"<<endl;
            else
                cout<<p/2<<".500 "<<p/2<<".500 0.000"<<endl;
        }
        else
        if(ostl <= c+3*b)cout<<c<<".000 "<<b<<".000 "<<b<<".000 "<<ostl-c-2*b<<".000"<<endl;
        else{
            if(ostl%4 == 0)cout<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000 "<<ostl/4<<".000"<<endl;
            if(ostl%4 == 1)cout<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250 "<<ostl/4<<".250"<<endl;
            if(ostl%4 == 2)cout<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500 "<<ostl/4<<".500"<<endl;
            if(ostl%4 == 3)cout<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750 "<<ostl/4<<".750"<<endl;
        }
    }




    return 0;
}
