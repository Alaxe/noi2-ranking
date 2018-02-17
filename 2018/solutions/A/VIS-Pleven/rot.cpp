#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char digits[16];

int getDigit (char digit) {
    int res;
    if (digit >= 'A' && digit <='F')
    {
        res = digit - 'A' + 10;
    } else {
        res = digit - '0';
    }
    return res;
}

string divideForSystem (string m, int b) {
    string res = "";
    int x = b - 1;
    int current = 0;
    for(int i = 0; i < m.size(); i++) {
        char digit = m[i];
        current = current * b;
        current += getDigit(digit);
        int resDigit = current / x;
        current = current % x;
        if (i == 0 && resDigit == 0){
            continue;
        }
        res = res +  digits[resDigit];
    }

    if (current != 0) {
        return "0";
    }
    return res;
}

int main(){
    //input begin
    int b;
    string m[4];
    cin >> b;
    cin >> m[0] >> m[1] >> m[2] >> m[3];
    //input end

    for (int i = 0; i < 10; i++)
    {
        digits[i] = '0' + i;
    }
    for (int i = 10; i < 16; i++)
    {
        digits[i] = 'A' - 10 + i;
    } // fills digits

    for (int i = 0; i < 4; i++)
    {
        m[i] = divideForSystem(m[i], b);
    }

    string res[4];

    for (int i = 0; i < 4; i++)
    {
        if (m[i] == "0") {
                res[i] = "0";
            continue;
        }
        res[i] += "1";
        for (int j = 1; j < m[i].size() + 1; j++) {
            int digit = getDigit(m[i][j - 1]) + 1;
            if (digit > b - 1) {
                res[i][j-1] = digits[(getDigit(res[i][j-1]) + 1)];
                digit = digit % b;
            }
            res[i] += digits[digit];
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << res[i] << endl;
    }




    return 0;
}
