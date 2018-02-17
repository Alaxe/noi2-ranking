#include<iostream>
#include<string>
using namespace std;

string stringCopy(string theString, int startIndex, int numOfChars) {

    string newString = "";
    for(int i = startIndex; i <= startIndex + numOfChars - 1; i++) {
        newString += theString[i];
    }

    return newString;
}

string stringCopyForward(string theString, int startIndex, int numOfChars) {

    string newString = "";
    for(int i = startIndex; i >= startIndex - numOfChars + 1; i--) {
        newString += theString[i];
    }

    return newString;
}

int main() {

    string bukvi;
    cin >> bukvi;

    int bukviLength = bukvi.length();
    int brPalindromi = bukviLength;

    for(int i = 0; i < bukviLength - 1; i++)
        for(int y = i + 1; y < bukviLength; y++) {
            if(bukvi[i] == bukvi[y]) {
                brPalindromi++;

                if(y > i+1) {
                    brPalindromi += y-(i+1);
                }


                int numOfChars = 2;
                while(i + numOfChars <= y - numOfChars && stringCopy(bukvi, i, numOfChars) == stringCopyForward(bukvi, y, numOfChars)) {
                    brPalindromi++;

                    int i1 = i + numOfChars - 1;
                    int y1 = y - numOfChars + 1;
                    if(y1 > i1) {
                        brPalindromi += y1-i1-1;
                    }

                    numOfChars++;
                }

            }
        }

    cout << brPalindromi;


    return 0;
}
