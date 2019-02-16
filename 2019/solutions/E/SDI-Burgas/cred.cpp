#include <iostream>

using namespace std;

int main()
{
    int n, m, n_temp_1, n_temp_2, output;
    output = 0;
    cin >> n >> m;
    while (n <= m)
    {

        n_temp_1 = n % 10;
        n_temp_2 = (n - n_temp_1) / 10;

        n = n + n_temp_1 + n_temp_2;
        output += 1;
    }


    cout << output;
    return 0;


}
