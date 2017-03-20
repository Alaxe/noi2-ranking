#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector <int> a = {1, 2, 3, 5, 7, 9, 12, 15, 18, 22, 26, 31, 36, 42, 49, 57, 66, 76, 87, 99, 112, 126, 141, 157, 174, 192, 212};
    int br = 0, sum = 0;
    int b[1030] = {0};

    b[0] = 1;

    while (sum < 160000){

        string r;
        int pr, temp, i;

        r.resize(a.size());
        pr = 0;

        for (i = a.size() - 1; i >= 0; --i){
            temp = (a[i] - '0') + (a[i] - '0') + pr;
            r[i] = temp%10 + '0';
            pr = temp / 10;
        }

        if (pr)
            r = '1' + r;

        cout << r << endl;

        sum = r.size();
        b[br+1] = sum+1;
        ++br;
        a = r;

    }

    string t;
    cin >> t;

    for (int i = 0; i <= 1028; ++i){
        if (t.size() == b[i])
            cout << i + 1 << endl;
    }


    return 0;
}
