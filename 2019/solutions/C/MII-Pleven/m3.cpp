#include <bits/stdc++.h>
using namespace std;

int s,k,a,b,c,d;
float p,q,m,n;

int main (){

    cin>>s>>k;
    cin>>a>>b>>c>>d;

    int v, t, otd;
    v=k%(d*4);
    t=k/d+1;
    otd=s*4;

    if(k>=s*d*4){  /// prelivane
       float x;
       x=(1.0*k-(s*d*4))/otd;
       p=q=m=n=x+d;
       cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
       return 0;
    }
     else
     if(t%4==1){  /// sektor A - a c b d
        if(v<=a){  /// ne preminava otd 1
            p=1.0*v;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
        }
         else
         if(v>a && v<=2*a){  /// preminava otd 1 bez prepulvane
            p=1.0*a;
            q=1.0*v-a;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>2*a && v<=2*c){  /// preminava otd 1 s prepulvane
            p=q=1.0*v/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>2*c && v-2*c<=b){  /// preminava otd 2 bez prepulvane
            p=q=1.0*c;
            m=1.0*v-2*c;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-2*c>b && v-2*c<=2*b){  /// preminava otd 3 bez prepulvane
            p=q=1.0*c;
            m=1.0*b;
            n=1.0*v-2*c-b;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-2*c>2*b && v<=4*c){  /// preminava otd 3 s prepulvane
            p=q=1.0*c;
            m=n=(1.0*v-2*c)/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>4*c){  /// preminava otd 2 s prepulvane
            p=q=m=n=1.0*v/4;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
     }
     else
     if(t%4==2){  /// sektor B - b a c d
        if(v<=b){  /// ne preminava otd 1
            p=1.0*v;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
        }
         else
         if(v>b && v-b<=a){  /// preminava otd 1 bez prepulvane
            p=1.0*b;
            q=1.0*v-b;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-b>a && v-b<=2*a){  /// preminava otd 2 bez prepulvane
            p=1.0*b;
            q=1.0*a;
            m=1.0*v-b-a;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-b>2*a && v<=3*b){  /// preminava otd 2 s prepulvane
            p=1.0*b;
            q=m=(1.0*v-b)/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>3*b && v<=3*c){  /// preminava otd 1 s prepulvane
            p=q=m=1.0*v/3;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>3*c && v<=4*c){  /// preminava otd 3 bez prepulvane
            p=q=m=1.0*c;
            n=1.0*v-3*c;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>4*c){  /// preminava otd 3 s prepulvane
            p=q=m=n=1.0*v/4;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
     }
     else
     if(t%4==3){  /// sektor V - b c a d
        if(v<=b){  /// ne preminava otd 1
            p=1.0*v;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
        }
         else
         if(v>b && v<=2*b){  /// preminava otd 1 bez prepulvane
            p=1.0*b;
            q=1.0*v-b;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>2*b && v<=2*c){  /// preminava otd 1 s prepulvane
            p=q=1.0*v/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>2*c && v-2*c<=a){  /// preminava otd 2 bez prepulvane
            p=q=1.0*c;
            m=1.0*v-2*c;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-2*c>a && v-2*c<=2*a){  /// preminava otd 3 bez prepulvane
            p=q=1.0*c;
            m=1.0*a;
            n=1.0*v-2*c-a;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-2*c>2*a && v<=4*c){  /// preminava otd 3 s prepulvane
            p=q=1.0*c;
            m=n=(1.0*v-2*c)/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>4*c){  /// preminava otd 2 s prepulvane
            p=q=m=n=1.0*v/4;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
     }
     else
     if(t%4==0){  /// sektor G - c a b d
        if(v<=c){  /// ne preminava otd 1
            p=1.0*v;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
        }
         else
         if(v>c && v-c<=a){  /// preminava otd 1 bez to da se prepulva
            p=1.0*c;
            q=1.0*v-c;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-c>a && v-c<=2*a){  /// preminava otd 2 bez prepulvane
            p=1.0*c;
            q=1.0*a;
            m=1.0*v-c-a;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-c>2*a && v-c<=2*b){  /// preminava otd 2 s prepulvane
            p=1.0*c;
            q=m=(1.0*v-c)/2;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-c>2*b && v-c-2*b<=b){  /// preminava otd 3 bez prepulvane
            p=1.0*c;
            q=m=1.0*b;
            n=1.0*v-c-2*b;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v-c-2*b>b && v<=4*c){  /// preminava otd 3 s prepulvane
            p=1.0*c;
            q=m=n=(1.0*v-c-2*b)/3;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
         else
         if(v>4*c){  /// preminava otd 1 s prepulvane
            p=q=m=n=1.0*v/4;
            cout<<fixed<<setprecision(3)<<p<<" "<<q<<" "<<m<<" "<<n;
            return 0;
         }
     }


 return 0;
}
/*
3 25
1 2 3 5
 out: 2.000 1.500 1.500 0.000
*/
