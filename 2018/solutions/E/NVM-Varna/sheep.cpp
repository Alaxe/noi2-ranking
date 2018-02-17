#include <iostream>

using namespace std;

int main() {

    int sheep;

    int L;

    cin >> sheep >> L;

    int lost[L] = {};
    int sheepList[L] = {};
    for (int i = 0; i < L ; i++) {
        cin >> lost[i];
    }
    for (int i = 1; i <= sheep ; i++) {
        sheepList[i] = i;
    }
    for(int i = 0; i < L; i++) {
        if (lost[i] == sheepList[i]) {
            sheepList[i] = -1;
        }

    }
    cout << sheepList[sheep] << endl;

}
