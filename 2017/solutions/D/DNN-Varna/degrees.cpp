#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long l = s.size(), counter = -1, counter1, temp = -1, i;


    for(i = 1; i; i++)
    {
        counter1 = counter;
        if(i % 3 == 1)
        {
            counter += 4 * i;
            if(counter >= l)break;
            temp += 4;
        }
        if(i % 3 == 2)
        {
            counter += 3 * i;
            if(counter >= l)break;
            temp += 3;
        }
        if(i % 3 == 0)
        {
            counter += 3 * i;
            if(counter >= l)break;
            temp += 3;
        }
    }

    cout << temp + (l - counter1) / i << endl;

    return 0;

}
