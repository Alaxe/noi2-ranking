#include <iostream>

using namespace std;

void output(double a) {
    a*=10000;
    long long b = a;
    if (b%10>=5) {
        b/=10;
        ++b;
    }else{
        b/=10;
    }
    short d[3];
    for (int i = 0; i < 3; ++i) {
        d[2-i] = b%10;
        b/=10;
    }
    cout << b << ".";
    for (int i = 0; i < 3; ++i) {
        cout << d[i];
    }
    cout << " ";
}

int main() {
    long long S, K, a, b, c, d;
    cin >> S >> K >> a >> b >> c >> d;
    if (K>=4*d*S) {
        double k = (double)K/(double)S/(double)4;
        output(k);
        output(k);
        output(k);
        output(k);
        cout << "\n";
        return 0;
    }
    if (K%(16*d)<=4*d && K%(16*d)!=0) { /// a c b
        K = K%(4*d);
        if (K<=a) {
            cout << K <<".000 " << "0.000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K <= 2*a) {
            cout << a <<".000 " << K-a<< ".000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=2*c) {
            double k = (double)K/(double)2;
            output(k);
            output(k);
            cout << "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=2*c+b) {
            cout << c << ".000 " << c << ".000 " << K-2*c << ".000 "<< "0.000/n";
            return 0;
        }
        if (K<=2*c+2*b){
            cout << c << ".000 " << c << ".000 " << b << ".000 "<< K-2*c-b<<".000/n";
            return 0;
        }
        if (K<=4*c) {
            double k = (double)(K-2*c)/(double)2;
            cout << c << ".000 " << c << ".000 ";
            output(k);
            output(k);
            cout << "\n";
            return 0;
        }
        double k = (double)K/(double)4;
        output(k);
        output(k);
        output(k);
        output(k);
        cout << "\n";
        return 0;
    }
    if (K%(16*d)<=8*d && K%(16*d)>4*d){///b a c
        K = K%(4*d);
        if (K<=b) {
            cout << K <<".000 " << "0.000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=b+a) {
            cout << b <<".000 " << K-b<< ".000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=b+2*a) {
            cout << b <<".000 " << a<< ".000 "<< K-b-a << ".000 "<< "0.000\n";
            return 0;
        }
        if (K<=2*b){
            double k = (double)(K-b)/(double)2;
            cout << b <<".000 ";
            output(k);
            output(k);
            cout << "0.000\n";
            return 0;
        }
        if (K<=3*c) {
            double k = (double)K/(double)3;
            output(k);
            output(k);
            output(k);
            cout << "0.000\n";
            return 0;
        }
        if(K<=4*c){
            cout << c << ".000 " << c << ".000 "<<c << ".000 "<< K-3*c<<".000";
            return 0;
        }
        double k = (double)K/(double)4;
        output(k);
        output(k);
        output(k);
        output(k);
        cout << "\n";
        return 0;
    }
    if (K%(16*d)<=12*d && K%(16*d)>8*d) {/// b c a
        K = K%(4*d);
        if (K<=b) {
            cout << K <<".000 " << "0.000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=b*2) {
            cout << b <<".000 " << K-b<< ".000 "<< "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=2*c) {
            double k = (double)K/(double)2;
            output(k);
            output(k);
            cout << "0.000 "<< "0.000\n";
            return 0;
        }
        if (K<=2*c+a) {
            cout << c << ".000 " << c << ".000 " << K-2*c << ".000 "<< "0.000/n";
            return 0;
        }
        if (K<=2*c+2*a){
            cout << c << ".000 " << c << ".000 " << a << ".000 "<< K-2*c-a<<".000/n";
            return 0;
        }
        if (K<=4*c) {
            double k = (double)(K-2*c)/(double)2;
            cout << c << ".000 " << c << ".000 ";
            output(k);
            output(k);
            cout << "\n";
            return 0;
        }
        double k = (double)K/(double)4;
        output(k);
        output(k);
        output(k);
        output(k);
        cout << "\n";
        return 0;
    }
    K = K%(4*d);
    if (K<=c) {
       cout << K <<".000 " << "0.000 "<< "0.000 "<< "0.000\n";
        return 0;
    }
    if(K<=c+a)  {
        cout << c <<".000 " << K-c<< ".000 "<< "0.000 "<< "0.000\n";
        return 0;
    }
    if (K<=c+2*a) {
        cout << c <<".000 " << a<< ".000 "<< K-c-a << ".000 "<< "0.000\n";
        return 0;
    }
    if (K<=2*b+c){
        double k = (double)(K-c)/(double)2;
        cout << c <<".000 ";
        output(k);
        output(k);
        cout << "0.000\n";
        return 0;
    }
    if (K<=3*b+c) {
        cout << c << ".000 " << b << ".000 " << b << ".000 "<< K-2*b-c<<".000/n";
        return 0;
    }
    if (K<=4*c) {
        cout << c << ".000 ";
        double k = (double)(K-c)/(double)3;
        output(k);
        output(k);
        output(k);
        return 0;
    }
    double k = (double)K/(double)4;
    output(k);
    output(k);
    output(k);
    output(k);
    cout << "\n";
    return 0;
}
