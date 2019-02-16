#include <iostream>
using namespace std;
int main () {
    long long s,k,a,b,c,d,i;
    double x1=0,x2=0,x3=0,x4=0,br=0;
    cin>>s>>k>>a>>b>>c>>d;
    i=k/(4*d)+1;
    if(i%4==1) {
        swap(b,c);
    }
    else if(i%4==2) {
        swap(a,b);
    }
    else if(i%4==3) {
        swap (a,b);
        swap (c,b);
    }
    else {
            swap(c,b);
            swap(a,c);
    }
    k=k%(4*d);
    if(a>=k) {
        x1=k;
        cout<<x1<<".000 0.000 0.000 0.000"<<endl;
    }else {
        x1=a;
        k=k-a;
        br=2;
        while(k>0) {
            if(x3<c and x2>=b and x2<a and x3>0) {
                x2=x2+0.5;
                x3=x3+0.5;
            }
            else if(x2<b and x2>0 and x2>a) {
                x2=x2+0.5;
                x1=x1+0.5;
            }
            else if(x1>a and x2>b and x2>a and x3>a and x3>b and x3>c and x4>a and x4>b and x4>c) {
                x1=x1+0.25;
                x2=x2+0.25;
                x3=x3+0.25;
            }
            else if(x2<b and x1==a) {
                x2++;
            }else if (x3<c and x2==b) {
                x3++;
            }else if(x4<c and x3==c ) {
                x4++;
            }
            k--;

        }
         cout<<x1<<".000 "<<x2<<"00 "<<x3<<"00 "<<x4<<".000"<<endl;
    }
    return 0;
}

