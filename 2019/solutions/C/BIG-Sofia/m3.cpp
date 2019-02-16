#include<bits/stdc++.h>
using namespace std;
long double S, a, b, c, d;
long long K;
int main(){
    fixed(cout);
    cin >> S >> K;
    cin >> a >> b >> c >> d;

    long long vodaNaS = d*4;
    if(K >= S*vodaNaS){
        double o = (long double)K / (long double)(4*S);
        //fixed(cout);
        cout << setprecision(3) << o <<" "<< o << " " << o << " " << o << endl;
        return 0;
    }

    long long ost = K % vodaNaS;
    long long sector = K / vodaNaS;
    if(K%vodaNaS == 0){
        double o = (long double)vodaNaS / (long double)4;
        //fixed(cout);
        cout << setprecision(3) << o <<" "<< o << " " << o << " " << o << endl;
        return 0;
    }
    sector++;
    sector %= 4;


    if(sector == 1){
        swap(b, c);
        if(ost <= a){
            cout << setprecision(3) << (long double)ost << " " << 0.000 << " " << 0.000 << " " << 0.000 << endl;
            return 0;
        }
        if(ost <= 2*b){
            if(ost < 2*a){
                long double o1 = a;
                long double o2 = ost - a;
                cout << setprecision(3) << o1 << " " << o2 << " " << 0.0 << " " << 0.0 << endl;
            }else{
                long double o = (long double)ost / (long double)2;
                cout << setprecision(3) << o << " " << o << " " << 0.0 << " " << 0.0 << endl;
            }
            return 0;
        }
        if(ost <= 2*b + c){
            long double o1 = b;
            ost -= 2*b;
            long double o2 = ost;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << 0.0 << endl;
            return 0;
        }
        if(ost - 2*b < 2*c){
            long double o1 = b;
            ost -= 2*b;
            long double o2 = c;
            ost -= c;
            long double o3 = ost;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << o3 << endl;
            return 0;
        }
        if(ost - 2*b <= 2*b){
            long double o1 = b;
            ost -= 2*b;
            long double o2 = (long double)ost / 2.0;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << o2 << endl;
            return 0;
        }
        long double o = (long double)ost / 4.0;
        cout << setprecision(3) << o << " " << o << " " << o << " " << o << endl;
        return 0;
    }

    if(sector == 2){
        swap(a, b);
        if(ost <= a){
            cout << setprecision(3) << (long double)ost << " " << 0.000 << " " << 0.000 << " " << 0.000 << endl;
            return 0;
        }
        long double ost1 = ost;
        if(ost1 <= a + b){
            long double o1 = a;
            long double o2 = ost1 - o1;
            cout << setprecision(3) << o1 << " " << o2 << " " << 0.0 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - a - b <= b){
            long double o1 = a;
            long double o2 = b;
            long double o3 = ost1 - o1 - o2;
            cout << setprecision(3) << o1 << " " << o2 << " " << o3 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - a < 2*a){
            long double o1 = a;
            long double o2 = (ost1 - a)/2;
            cout << setprecision(3) << o1 << " " << o2 << " " << o2 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 <= 3*c){
            long double o = ost1 / 3.0;
            cout << setprecision(3) << o << " " << o << " " << o << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 <= 4*c){
            long double o1 = c;
            long double o2 = ost1 - 3*c;
            cout << setprecision(3) << o1 << " " << o1 << " " << o1 << " " << o2 << endl;
            return 0;
        }
        long double o = ost1 / 4.0;
        cout << setprecision(3) << o << " " << o << " " << o << " " << o << endl;
        return 0;
    }

    if(sector == 3){
        swap(a, c);
        swap(a, b);
        if(ost <= a){
            cout << setprecision(3) << (long double)ost << " " << 0.000 << " " << 0.000 << " " << 0.000 << endl;
            return 0;
        }
        long double ost1 = ost;
        if(ost1 <= 2*a){
            long double o1 = a;
            long double o2 = ost1-a;
            cout << setprecision(3) << o1 << " " << o2 << " " << 0.0 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 <= 2*b){
            long double o = ost1 / 2.0;
            cout << setprecision(3) << o << " " << o << " " << 0.0 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - 2*b <= c){
            long double o1 = b;
            long double o2 = ost1 - 2*b;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - 2*b -c <= c){
            long double o1 = b;
            ost1 -= 2*b;
            ost1 -= c;
            long double o2 = c;
            long double o3 = ost1;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << o3 << endl;
            return 0;
        }
        if(ost1 - 2*b <= 2*b){
            long double o1 = b;
            ost1 -= 2*b;
            long double o2 = ost1 / 2.0;
            cout << setprecision(3) << o1 << " " << o1 << " " << o2 << " " << o2 << endl;
            return 0;
        }
        long double o = ost1 / 4.0;
        cout << setprecision(3) << o << " " << o << " " << o << " " << o << endl;
        return 0;
    }

    if(sector == 0){
        swap(a, b);
        swap(a, c);
        if(ost <= a){
            cout << setprecision(3) << (long double)ost << " " << 0.000 << " " << 0.000 << " " << 0.000 << endl;
            return 0;
        }
        long double ost1 = ost;
        if(ost1 - a <= b){
            long double o1 = a;
            ost1 -= a;
            long double o2 = ost1;
            cout << setprecision(3) << o1 << " " << o2 << " " << 0.0 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - a - b <= b){
            long double o1 = a;
            ost1 -= a;
            long double o2 = b;
            long double o3 = ost1 - b;
            cout << setprecision(3) << o1 << " " << o2 << " " << o3 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - a <= 2*c){
            long double o1 = a;
            ost1 -= a;
            long double o2 = ost1 / 2.0;
            cout << setprecision(3) << o1 << " " << o2 << " " << o2 << " " << 0.0 << endl;
            return 0;
        }
        if(ost1 - a - 2*c <= c){
            long double o1 = a;
            ost1 -= a;
            long double o2 = c;
            ost1 -= 2*c;
            long double o3 = ost1;
            cout << setprecision(3) << o1 << " " << o2 << " " << o2 << " " << o3 << endl;
            return 0;
        }
        if(ost1 - a <= 3*a){
            long double o1 = a;
            ost1 -= a;
            long double o2 = ost1 / 3.0;
            cout << setprecision(3) << o1 << " " << o2 << " " << o2 << " " << o2 << endl;
            return 0;
        }
        long double o = ost1 / 4.0;
        cout << setprecision(3) << o << " " << o << " " << o << " " << o << endl;
        return 0;
    }

    //fixed(cout);
    //cout << setprecision(3) <<  << endl;
return 0;
}
