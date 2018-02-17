#include<iostream>
#include<math.h>

using namespace std;
typedef unsigned long long ull;

ull number(string s){
    ull k = 0;
    double po = 0;

    for(int i=s.size()-1;i>=0;i--){
        int p = (s[i]-48);
        k += p * ceil(pow(10.0, po));
        po++;
    }

    return k;
}

int main(){

    string m,n;
    cin >> m >> n;
    long gran = 0;

    if(m.size()<18 && n.size()<18){

        ull a = number(m);
        ull b = number(n);

        long double z = sqrt(a);

        ull c = floor(z);
        ull d = ceil(z);

        if(c == d)d++;

        if(c * d < a){
            c++;
            d++;
        }

        ull dif = (c+1)*(d+1) - c*d;

        a = c*d;

        while(a <= b){
            a+=dif;
            dif+=2;
            gran++;
        }
    }

    cout << gran << endl;

    return 0;
}
