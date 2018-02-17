#include <iostream>
using namespace std;
string n;
int main (){

    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> n;
    bool dali = 1;
    int sz = n.size ();
    for (int i = 0; i < sz; i ++){
        if (n [i] != '9'){
            dali = 0;
            break;
        }
    }
    if (dali){
        cout << '1';
        for (int i = 1; i < sz; i ++) cout << '0';
        cout << "1\n";
        return 0;
    }
    int mid = sz / 2;
    for (int i = mid - 1; i >= 0; i --){
        if (n [i] == n [sz - i - 1]) continue;
        if (n [i] > n [sz - i - 1]){
            for (int j = i; j >= 0; j --){
                n [sz - j - 1] = n [j];
            }
            cout << n << '\n';
            return 0;
        }
        for (i; i >= 0; i --){
            n [sz - i - 1]  = n[i];
        }
    }
    int j;
    if (sz % 2 == 1) j = mid;
    else j = mid - 1;
    for (j; j >= 0; j --){
        if (n [j] == '9'){
            n [j] = '0';
            n [sz - j - 1] = '0';
        }
        else{
            n [j] ++;
            n [sz - j - 1] = n [j];
            break;
        }
    }
    cout << n << '\n';

    return 0;
}
