#include<iostream>

using namespace std;

int main ()
{
    int n,a = 0,c = 0,h = 0,i;
    cin >> n;
    char m[n];
    cin >> m;
    for(int i = 0;i < n;i++) {
        if (m[i] == 'a' || m[i] == 'b') {
            a++;
        } else {
            c++;
        }
    }
    if (a == c) {
        a += c;
    } else if (c > a){
        int d = (c - a);
        while(d != -1) {
           if(c == a){
                a += c;
                cout << a << endl;
                return 0;
        } else if (m[n-h-1] == 'c' || m[n-h-1] == 'd') {
                d--;
                h++;
                c--;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        int d = (a - c);
        while(d != -1) {
           if(c == a){
                a += c;
                cout << a << endl;
                return 0;
        } else if (m[n-h-1] == 'a' || m[n-h-1] == 'b') {
                d--;
                h++;
                a--;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    }
    cout << a << endl;
    return 0;
}
