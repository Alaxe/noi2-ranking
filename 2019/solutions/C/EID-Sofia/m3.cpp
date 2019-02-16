#include<bits/stdc++.h>
using namespace std;
long long sector=0;
double S, k;
double a, b, c,d;

int main() {
    cin>>S>>k>>a>>b>>c>>d;
    while((k-4*d)>=0){
        k=k-4*d;
        sector++;
    }
    sector=sector%4+1;
    if(k==0){
        cout<<setprecision(3)<<fixed<<d<<" "<<d<<" "<<d<<" "<<d<<endl;
    }else{
        if(sector==1){
            if(a>=k){
                cout<<setprecision(3)<<fixed<<k<<" "<<0.000<<" "<<0.000<<" "<<0.000;
            }
            if(a<k and a+c>k){
                cout<<setprecision(3)<<fixed<<k/2<<" "<<k/2<<" "<<0.000<<" "<<0.000;
            }
            if(2*c<=k and k-2*c<=b){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<k-2*c<<" "<<0.000;
            }else if(2*c<=k and (k-2*c)/2>b){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<(k-2*c)/2<<" "<<(k-2*c)/2;
            }else if(2*c<=k and (k-2*c)/2<b){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<b<<" "<<(k-2*c-b);
            }
        }else if(sector==2){
            if(b>=k){
                cout<<setprecision(3)<<fixed<<k<<" "<<0.000<<" "<<0.000<<" "<<0.000;
            }
            if(b<k and a+b>k){
                cout<<setprecision(3)<<fixed<<b<<" "<<k-b<<" "<<0.000<<" "<<0.000;
            }
            if(a+b<k and (k-b)/2<=c){
                cout<<setprecision(3)<<fixed<<b<<" "<<(k-b)/2<<" "<<(k-b)/2<<" "<<0.000;
            }else if(a+b<k){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<c<<" "<<k-3*c;
            }
            if(a+b==k){
                cout<<setprecision(3)<<fixed<<b<<" "<<a<<" "<<0.000<<" "<<0.000;
            }
        }else if(sector==3){
            if(b>=k){
                cout<<setprecision(3)<<fixed<<k<<" "<<0.000<<" "<<0.000<<" "<<0.000;
            }
            if(b<k and b+c>k and k/2<=c){
                cout<<setprecision(3)<<fixed<<k/2<<" "<<k/2<<" "<<0.000<<" "<<0.000;
            }else if(b<k and b+c>k and k/2>c and k-2*c<=a){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<k-2*c<<" "<<0.000;
            }else if(b<k and b+c>k and k/2>c){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<(k-2*c)/2<<" "<<(k-2*c)/2;
            }
            if(2*c<=k){
                cout<<setprecision(3)<<fixed<<c<<" "<<c<<" "<<k-2*c<<" "<<0.000;
            }
        }else if(sector==4){
            if(c>=k){
                cout<<setprecision(3)<<fixed<<k<<" "<<0.000<<" "<<0.000<<" "<<0.000;
            }
            if(c<k and a+c>k){
                cout<<setprecision(3)<<fixed<<c<<" "<<k-c<<" "<<0.000<<" "<<0.000;
            }
            if(a+c<k){
                cout<<setprecision(3)<<fixed<<c<<" "<<(k-(2*a+c))/2+a<<" "<<(k-(c+2*a))/2+a<<" "<<0.000;
            }
            if(a+c==k){
                cout<<setprecision(3)<<fixed<<c<<" "<<a<<" "<<0.000<<" "<<0.000;
            }
        }
    }
    cout<<endl;
    return 0;
}

