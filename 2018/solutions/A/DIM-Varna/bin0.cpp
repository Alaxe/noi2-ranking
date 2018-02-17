#include <iostream>
#include <cmath>

using namespace std;

void MakeValues();
void HowManyO();
void Summary();

int BegNum, EndNum, Zeros;

int numOfValidValues=0;

int main()
{
    cin >> BegNum;
    cin >> EndNum;
    cin >> Zeros;

    //MakeValues();
    HowManyO();
    Summary();

    return 0;
}

/*
void MakeValues(){

int Values[EndNum];
bool bActive;

for (int i = 1; i <= EndNum; i++) {
        int rightNum = 1;

    if (i=1) {Values[i] = 1;}
     if (right(0; Values[i-1])==0) {
            Values[i] = Values[i-1]+1;
            bActive = false;
     }

    while (bActive) {
        if (right(rightnum;Values[i-1]==0)) {
            Values[i] = Values[i-1] + 10^rightNum;
        }
    }
}

}
*/

void HowManyO() {

for (int i = BegNum; i <= EndNum ; i++) {
        int nulls;
    //nulls= (how many zeros in Values[BegNum])
    if (nulls == Zeros) { numOfValidValues++;}
}
}

void Summary() {
cout << endl;
cout << numOfValidValues;
}
