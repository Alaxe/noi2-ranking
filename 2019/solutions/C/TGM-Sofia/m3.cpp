#include <iostream>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie();
    long long s,k,a,b,c,d,n;
    cin >> s >> k;
    cin >> a >> b >> c >> d;
    if(k%(d*4)==0){
        cout << d << ".000" << " " << d << ".000" << " " << d << ".000" << " " << d << ".000" << endl;
        return 0;
    }
    if(s*d*4<k){
        cout << d << ".000" << " " << d << ".000" << " " << d << ".000" << " " << d << ".000" << endl;
        return 0;
    }
    n=((k/(d*4))+1)%4;
    int m=k%(d*4);
    if(n==1){
        if(m<=a){
            cout << m << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m<=2*a){
            cout << a << ".000" << " " << m-a << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*a && m<=2*c && m%2==0){
            cout << m/2 << ".000" << " " << m/2 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*a && m<=2*c){
            cout << m/2 << "00" << " " << m/2 << "00" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*c && m<=(2*c)+b){
            cout << c << ".000" << " " << c << ".000" << " " << m-(2*c) << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>(2*c)+b && m<=2*(c+b)){
            cout << c << ".000" << " " << c << ".000" << " " << b << ".000" << " " << m-((2*c)+b) << ".000" << endl;
            return 0;
        }
        if(m>2*(c+b) && m<=4*c && (m-(2*c))%2==0){
            cout << c << ".000" << " " << c << ".000" << " " << (m-(2*c))/2 << ".000" << " " << (m-(2*c))/2 << ".000" << endl;
            return 0;
        }
        if(m>2*(c+b) && m<=4*c){
            cout << c << ".000" << " " << c << ".000" << " " << (double)(m-(2*c))/2 << "00" << " " << (double)(m-(2*c))/2 << "00" << endl;
            return 0;
        }
        if(m>4*c){
            if(m%4==0){
                cout << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << endl;
                return 0;
            }
            if(m%4==2){
                cout << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << endl;
                return 0;
            }
            cout << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << endl;
            return 0;
        }
    }
    if(n==2){
        if(m<=b){
            cout << m << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>b && m<=a+b){
            cout << b << ".000" << " " << m-b << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>a+b && m<=2*a+b){
            cout << b << ".000" << " " << a << ".000" << " " << m-(a+b) << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*a+b && m<=3*b){
            cout << b << ".000" << " " << (double)(m-b)/2 << "00" << " " << (double)(m-b)/2 << "00" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>3*b && m<=3*c){
            if(m%3==1){
                cout << (double)m/3-0.00033 << " " << (double)m/3-0.00033 << " " << (double)m/3-0.00033 << " " << 0 << ".000" << endl;
                return 0;
            }
            if(m%3==2){
                cout << (double)m/3-0.00067 << " " << (double)m/3-0.00067 << " " << (double)m/3-0.00067 << " " << 0 << ".000" << endl;
                return 0;
            }
            if(m%3==0){
                cout << m/3 << ".000" << " " << m/3 << ".000" << " " << m/3 << ".000" << " " << 0 << ".000" << endl;
                return 0;
            }
        }
        if(m>3*c && m<4*c){
            cout << c << ".000" << " " << c << ".000" << " " << c << ".000" << " " << m-3*c << ".000" << endl;
            return 0;
        }
        if(m>4*c){
            if(m%4==0){
                cout << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << endl;
                return 0;
            }
            if(m%4==2){
                cout << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << endl;
                return 0;
            }
            cout << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << endl;
            return 0;
        }
    }
    if(n==3){
        if(m<=b){
            cout << m << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>b && m<=2*b){
            cout << b << ".000" << " " << m-b << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*b && m<=2*c && m%2==0){
            cout << m/2 << ".000" << " " << m/2 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*b && m<=2*c){
            cout << (double)m/2 << "00" << " " << (double)m/2 << "00" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*c && m<=2*c+a){
            cout << c << ".000" << " " << c << ".000" << " " << m-(2*c) << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*c+a && m<2*(c+a)){
            cout << c << ".000" << " " << c << ".000" << " " << a << ".000" << " " << m-(2*c+a) << ".000" << endl;
            return 0;
        }
        if(m>2*(a+c) && m<4*c && (m-(2*c))%2==0){
            cout << c << ".000" << " " << c << ".000" << " " << (m-(2*c))/2 << ".000" << " " << (m-(2*c))/2 << ".000" << endl;
            return 0;
        }
        if(m>2*(a+c) && m<4*c){
            cout << c << ".000" << " " << c << ".000" << " " << (double)(m-(2*c))/2 << "00" << " " << (double)(m-(2*c))/2 << "00" << endl;
            return 0;
        }
        if(m>4*c){
            if(m>4*c){
                if(m%4==0){
                    cout << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << endl;
                    return 0;
                }
                if(m%4==2){
                    cout << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << endl;
                    return 0;
                }
                cout << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << endl;
                return 0;
            }
        }
    }
    if(n==0){
        if(m<=c){
            cout << m << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>c && m<=a+c){
            cout << c << ".000" << " " << m-c << ".000" << " " << 0 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>a+c && m<=2*a+c){
            cout << c << ".000" << " " << a << ".000" << " " << m-(a+c) << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*a+c && m<=2*b+c && (m-c)%2==0){
            cout << c << ".000" << " " << (m-c)/2 << ".000" << " " << (m-c)/2 << ".000" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*a+c && m<=2*b+c){
            cout << c << ".000" << " " << (double)(m-c)/2 << "00" << " " << (double)(m-c)/2 << "00" << " " << 0 << ".000" << endl;
            return 0;
        }
        if(m>2*b+c && m<=3*b+c){
            cout << c << ".000" << " " << b << ".000" << " " << b << ".000" << " " << m-(2*b+c) << ".000" << endl;
            return 0;
        }
        if(m>c+3*b && m<=4*c){
            if((m-c)%3==1){
                cout << c << ".000" << " " << (double)(m-c)/3-0.00033 << " " << (double)(m-c)/3-0.00033 << " " << (double)(m-c)/3-0.00033 << endl;
                return 0;
            }
            if((m-c)%3==2){
                cout << c << ".000" << " " << (double)(m-c)/3-0.00067 << " " << (double)(m-c)/3-0.00067 << " " << (double)(m-c)/3-0.00067 << endl;
                return 0;
            }
            if((m-c)%3==0){
                cout << c << ".000" << " " << (m-c)/3 << ".000" << " " << (m-c)/3 << ".000" << " " << (m-c)/3 << ".000" << endl;
                return 0;
            }
        }
        if(m>4*c){
            if(m>4*c){
                if(m%4==0){
                    cout << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << " " << m/4 << ".000" << endl;
                    return 0;
                }
                if(m%4==2){
                    cout << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << " " << (double)m/4 << "00" << endl;
                    return 0;
                }
                cout << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << " " << (double)m/4 << "0" << endl;
                return 0;
            }
        }
    }
return 0;
}
