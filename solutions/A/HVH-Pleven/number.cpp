#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFound(vector<long>& seq, long n) {
    for(long i = 0; i < seq.size(); i++) {
        if(seq[i] == n) {
            return true;
        }
    }

    return false;
}

int main()
{
    long m, n;

    cin >> m >> n;

    vector<long> sequence;

    for(long i = m; i <= n; i++) {
        sequence.push_back(i);
    }


    unsigned long counter = 0;
    for(long i = 0; i < sequence.size() - 1; i++) {

        long s = sequence[i] * sequence[i+1];

        if(isFound(sequence, s) == true) {
            counter++;
        }
    }

    cout << counter << endl;
    return 0;
}
