#include <iostream>
#include <vector>

using namespace std;

int calc(int firstPos, int workingArr[], int arrSize)
{
    int firstIndex = firstPos - 1;

    if(firstIndex == 0 || firstPos == arrSize)
        return 1;

    if(workingArr[firstIndex] == 0)
        workingArr[firstIndex] = 1;

    if(arrSize-firstPos == 1 || firstPos - 1 == 1)
        return arrSize-1;

    return (arrSize-firstPos)*(firstPos-1);
}

int main()
{
    int k, n;
    cin >> n >> k;

    if (k > n)
        return 1;
    int warr[n];

    int nachini = calc(k, warr, n);
    cout << nachini;
    return 0;
}
