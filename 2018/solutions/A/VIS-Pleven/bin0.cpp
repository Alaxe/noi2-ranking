#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct Binary {
    vector<int> bin;
    int countOf0;
};

Binary toBinary(unsigned long long a) {
    vector<int> bin;
    int countOf0;

    while (a > 0) {
        int remainder = a % 2;
        a = a / 2;
        bin.push_back(remainder);
        if (remainder == 0) countOf0++;
    }

    Binary result;
    result.bin = bin;
    result.countOf0 = countOf0;
    return result;
}

unsigned long long countCombinations(int a, int b) {
    unsigned long long result = 1;
    for (int i = 0; i < b; i++) {
        result = result * (a - i) / (i + 1);
    }
    return result;
}

/*Binary getFirstGoodAround(Binary num, int zeroes) { //good - with z 0s

    if(num.countOf0 = zeroes)
    {
        return num;
    }
    else if (num.countOf0 < zeroes) {
        int i = num.bin.size() - 1;
        while (i > 0) {
            if (num.bin[i] == 1) {
                num.bin[i] == 0;
                num.countOf0++;
            }
            i--;
            if(num.countOf0 = zeroes)
            {
                return num;
            }
        }

        if (i == 0) {
            return num; //TODO
        }
    }
    else if (num.countOf0 > zeroes) {
        int i = num.bin.size() - 1;
        while (i > 0) {
            if (num.bin[i] == 0) {
                num.bin[i] == 1;
                num.countOf0--;
            }
            i--;
            if(num.countOf0 = zeroes)
            {
                return num;
            }
        }

        if (i == 0) {
            return num; //TODO
        }
    }

}*/

int main(){
    //input begin
    unsigned long long s, t;
    int z;

    cin >> s >> t >> z;
    //input end

    Binary sBin = toBinary(s);
    Binary tBin = toBinary(t);

    int sl = sBin.bin.size() - 1;
    int tl = tBin.bin.size() - 1;
    int result = 0;
    if (pow(2, z) == sl) result++;
    if (pow(2, z) == tl) result++;
    for (int i = sl; i < tl; i++) {
        result += countCombinations(i, z);
    }
    cout << result;


    return 0;
}
