#include <iostream>
#include <string.h>

using namespace std;
char abyz[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

long long getLetterIndex(char t)
{
    for (long long i=0; i<26; i++) if (t == abyz[i]) return i;
}

int main()
{
    string seq; cin >> seq;
    int i, j, ns[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, slen = seq.length();
    for (i = 0; i < slen; i++) ns[getLetterIndex(seq[i])] = 1;
    char ch1[slen], ch2[slen];

    for (i = 0; i < slen; i++) {
        int current = getLetterIndex(seq[i]), mx = 0, mn = 0;
        for (j=0; j<26; j++) {
            if (current > j && ns[j] == 1) mx++;
            if (current < j && ns[j] == 1) mn++;
        }
        ch1[i] = abyz[0 + mx];
        ch2[i] = abyz[25 - mn];
    }

    for (i = 0; i < slen; i++) cout << ch1[i];
    cout << endl;
    for (i = 0; i < slen; i++) cout << ch2[i];
    cout << endl;

    return 0;
}

/*
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z';
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z';
*/

// if (current <= mn) mn = current;
// if (current >= mx) mx = current;
