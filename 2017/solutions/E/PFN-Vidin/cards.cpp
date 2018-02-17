#include <iostream>
using namespace std;
int main(){

    int n, a, b, row = 0, icrateX, icrateY;
    cin >> n;

    for (int j = 0; j <= n; j++){
        cin >> a;
        cin >> b;

        icrateX = a;
        icrateY = b;

        if ((icrateX || icrateY) == (a || b)){
            row = 4;
        }

        break;
    }


    cout << row << endl;

    return 0;
}
