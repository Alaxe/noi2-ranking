#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int broiNuliOtDes(unsigned long long des, int maxNuli) {

    int brNuli = 0;
    while(des > 0) {
        if(des % 2 == 0)
            brNuli++;
        if(brNuli > maxNuli)
            return -1;

        des = des/2;
    }

    return brNuli;
}

int main() {

    unsigned long long first, last;
    int brNuli, namerenBroi=0;
    cin >> first >> last >> brNuli;

    for(int i = first; i<=last; i++) {
        if(broiNuliOtDes(i, brNuli) == brNuli)
            namerenBroi++;
    }

    cout << namerenBroi;

    return 0;
}
