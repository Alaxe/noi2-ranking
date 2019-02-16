#include<bits/stdc++.h>

using namespace std;

int a, b, c, d;
int s, k;

void f(int sector){

    int c1 = a, c2 = b, c3 = c;

    if(sector == 1){

        b = c3;
        c = c2;

    }else if(sector == 2){

        a = c2;
        b = c1;

    }else if(sector == 3){

        a = c3;
        b = c1;
        c = c2;

    }else if(sector == 0){

        a = c2;
        b = c3;
        c = c1;

    }

    return;

}

int main () {

    cin >> s >> k;
    cin >> a >> b >> c >> d;

    float h1 = 0, h2 = 0, h3 = 0, h4 = 0;

    int ostL = k % (4 * d);
    int lastS = (k / (4 * d)) % 4;

    if(ostL == 0){

        cout << d << ".000 ";
        cout << d << ".000 ";
        cout << d << ".000 ";
        cout << d << ".000\n";

        return 0;

    }

    f(lastS);

    cout << a << ".000 ";
    cout << b << ".000 ";
    cout << c << ".000 ";
    cout << d << ".000\n";

    return 0;
}
