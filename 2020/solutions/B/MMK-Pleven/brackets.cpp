#include <iostream>
#include <string>
using namespace std;

struct Skobi {
    int p1, p2;
};
int d, i, zatv, br, k0, k1, k2, k3;
string s, ss;
Skobi a[10001];
bool fl;
char c1, c2;

int main () {
    cin >> s;
    d = s.size();
    for (i = 0; i < d; i ++) {
        if (s[i] == '(') {
            br ++;
            a[br].p1 = i;
        }
        else if (s[i] == ')') {
//            cout << br << " " << zatv+1 << " " << i << endl;
            zatv ++;
            if (a[br].p2 == 0) a[br].p2 = i;
            else a[br-zatv+1].p2 = i;
        }
    }
//    for (i = 1; i <= br; i ++) cout << a[i].p1 << " " << a[i].p2 << endl;
    k1 = a[1].p1; k2 = a[1].p2;
    for (i = 2; i <= br; i ++) {
        if (k1+1 == a[i].p1 && k2-1 == a[i].p2) {
            s[k1] = 'a'; s[k2] = 'a';
        }
        k1 = a[i].p1; k2 = a[i].p2;
    }
    for (i = br; i >= 1; i --) {
        fl = true;
        k1 = a[i].p1; k2 = a[i].p2;
        ss = s.substr(k1, k2-k1+1);
        k0 = k1;
        k3 = k2;
        while (k0 > 0) {
            k0 --;
            if (s[k0] != '&' && s[k0] != '(' && s[k0] != ')' && s[k0] != 'a') {
                c1 = s[k0];
                break;
            }
        }
        while (k3 < d) {
            k3 ++;
            if (s[k3] != '&' && s[k3] != '(' && s[k3] != ')' && s[k3] != 'a') {
                c2 = s[k3];
                break;
            }
        }
        fl = true;
        if (ss.find('+') <= k2 || ss.find('-') <= k2) fl = false;
        if (fl == false && (c1 == '*' || c2 == '*' || c1 == '/' || c2 == '/')) i = i;
        else {
            s[k1] = 'a';
            s[k2] = 'a';
        }
//        cout << ss << " " << k0 << " " << c1 << "  " << k3 << " " << c2;
//        cout << " " <<ss.find('+');
//        if (fl) cout << " t" << endl;
//        else cout << " f" << endl;
    }
    for (i = 0; i <  d; i ++) {
        if (s[i] != 'a')
            cout << s[i];
    }
    return 0;
}
/*
(&+&*(&*&+(&+&)*&))*&
(&+&*(&*&)+(&+&)*&)*&
&*&*(&*&)+&
&*(((&+&)))+&

*/
