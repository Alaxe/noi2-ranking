#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e5 + 200;
struct bracket{
    int first;
    int second;
    bool prefix; // + e true drugo e false
    bool sufix; // + i - sa true drugo e false
    bool cont; // . / e umnojenie drugo e false
    bool smisul;
};

bracket a[maxn];
string vhod;
int par[2*maxn];
stack<int> skobi1;
vector<int> skobi2;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> vhod;
    int s = 0;
    for (int i = 0; i < vhod.size(); ++i) {
        if (vhod[i]=='(') {
            skobi1.push(i);
        }
        if (vhod[i]==')') {
            a[s].first = skobi1.top();
            par[skobi1.top()] = s;
            a[s].second = i;
            par[i] = s;
            skobi1.pop();
            ++s;
        }
    }
    for (int i = 0; i < s; ++i) {
        if (a[i].first==0)a[i].prefix = true;
        else{
            if (vhod[a[i].first-1]=='+' || vhod[a[i].first-1]=='(') a[i].prefix = true;
            else a[i].prefix = false;
        }
        if (a[i].second==vhod.size()-1) a[i].sufix = true;
        else{
            if (vhod[a[i].second+1] == '+' || vhod[a[i].second+1] == '-' || vhod[a[i].second+1]==')') a[i].sufix = true;
            else a[i].sufix = false;
        }
        //cout << a[i].first << " " << a[i].second << " " << a[i].prefix << " " << a[i].sufix << "\n";
        a[i].cont = true;
        for (int j = a[i].first+1; j < a[i].second; ++j) {
            if (vhod[j]=='+' || vhod[j]=='-') {
                a[i].cont = false;
                break;
            }
            if (vhod[j]=='(') {
                j = a[par[j]].second;
            }
        }
        a[i].smisul = true;
        if(a[i].cont)
            a[i].smisul = false;
        else{
            if (a[i].prefix && a[i].sufix)
                a[i].smisul = false;
        }
    }
    for (int i = 0; i < vhod.size(); ++i) {
        if (vhod[i]=='(' || vhod[i]==')') {
            if (a[par[i]].smisul)
                cout << vhod[i];
        }else{
            cout << vhod[i];
        }
    }
    cout << "\n";
    return 0;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&+(((&/&)))/&
*/
