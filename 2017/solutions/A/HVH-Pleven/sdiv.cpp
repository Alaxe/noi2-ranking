#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> toInt(string str) {
    vector<int> result;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '0') {
            result.push_back(0);
        }

        if(str[i] == '1') {
            result.push_back(1);
        }

        if(str[i] == '2') {
            result.push_back(2);
        }

        if(str[i] == '3') {
            result.push_back(3);
        }

        if(str[i] == '4') {
            result.push_back(4);
        }

        if(str[i] == '5') {
            result.push_back(5);
        }

       if(str[i] == '6') {
            result.push_back(6);
        }

        if(str[i] == '7') {
            result.push_back(7);
        }

        if(str[i] == '8') {
            result.push_back(8);
        }

        if(str[i] == '9') {
            result.push_back(9);
        }
    }

    return result;
}
int main()
{
    string sequence;
    long long m, n;

    cin >> sequence;

    vector<int> seqInt = toInt(sequence);

    cin >> n >> m;

    int counter = 0;
    for(int i = 0; i < seqInt.size(); i++) {
        if(seqInt[i] % n == 0) {
            counter++;
        }
    }

    cout << fmod(counter, m) + 1 << endl;

    return 0;
}
