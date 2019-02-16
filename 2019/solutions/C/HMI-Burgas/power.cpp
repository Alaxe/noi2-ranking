#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n > 10000 || n < 0 || k > 1000 || k < 0)
    {
        cout << endl << endl << "Unexpected number entered" << endl << endl;
        return 0;
    }
    int numbers[n];
    for (int i = 1; i <= n; i++)
    {
        int number;
        cin >> number;
        if (number > 43 || number < 0)
        {
            cout << endl << endl << "Unexpected number entered" << endl << endl;
            return 0;
        }
        numbers[i] = number;
    }
    bool numberFound = false;
    int currentC = 0;
    while(!numberFound)
    {
        currentC++;
        double number = pow(currentC, k);
        int goodNums = 0;
        for (int a = 1; a <= n; a++)
        {
            if(((int)number%numbers[a]) == 0)
            {
                goodNums++;
            }
        }

        if (goodNums >= n)
        {
            cout << currentC << endl;
            numberFound = true;
        }

    }

}
